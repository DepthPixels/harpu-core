/* HID class support functions */

#include <stdio.h>
#include "project_config.h"
#include "transfer.h"

BYTE bigbuf[1024];   //256 bytes
extern DEV_RECORD devtable[];

HID_DEVICE hid_device = { { 0 } };
EP_RECORD hid_ep[16] = { { 0 } }; //HID class endpoints
BYTE gamepad_ep = 0;

/* HID Mouse probe. Called from USB state machine.                          */
/* assumes configuration length is less than 256 bytes                      */
/* looks for Class:03, Subclass: 01, Protocol: 02 in interface descriptor   */
/* sets mouse in boot protocol                                              */
/* assumes single configuration and interface configuration 0               */
BOOL HIDMProbe(BYTE addr, DWORD flags) {
	BYTE tmpbyte;
	BYTE rcode;
	BYTE confvalue;
	WORD total_length;
	USB_DESCR* data_ptr = (USB_DESCR *) &bigbuf;
	BYTE* byte_ptr = bigbuf;
	rcode = XferGetConfDescr(addr, 0, CONF_DESCR_LEN, 0, bigbuf); //get configuration descriptor
	if (rcode) {   //error handling
		//printf("unable to get configuration descriptor");
		return (FALSE);
	}
	if (data_ptr->descr.config.wTotalLength > 1024) {
		total_length = 1024;
	} else {
		total_length = data_ptr->descr.config.wTotalLength;
	}
	rcode = XferGetConfDescr(addr, 0, total_length, 0, bigbuf); //get the whole configuration
	if (rcode) {   //error handling
		//printf("unable to get configuration");
		return (FALSE);
	}
	confvalue = data_ptr->descr.config.bConfigurationValue;
	//printf("checking configuration value (length: %d): ",
	//		data_ptr->descr.config.wTotalLength);
	//for (int i = 0; i < data_ptr->descr.config.wTotalLength; i++) {
		//printf("%x ", (unsigned char) (bigbuf[i] & 0xff));
	//}
	while (byte_ptr < bigbuf + total_length) {
		if (data_ptr->descr.config.bDescriptorType != USB_DESCRIPTOR_INTERFACE) {
			byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
			data_ptr = (USB_DESCR*) byte_ptr;
		} // if( data_ptr->descr.config.bDescriptorType != USB_DESCRIPTOR_INTERFACE
		else {
			//printf("starting interface parsing at byte location %d\n",
			//		data_ptr->descr.config.bLength);
			BYTE class = data_ptr->descr.interface.bInterfaceClass;
			BYTE subclass = data_ptr->descr.interface.bInterfaceSubClass;
			BYTE protocol = data_ptr->descr.interface.bInterfaceProtocol;
			//printf("class %x, subclass %x, protocol %x,\n", class, subclass,
			//		protocol);
			//interface descriptor
			if (class == HID_INTF && subclass == BOOT_INTF_SUBCLASS
					&& protocol == HID_PROTOCOL_MOUSE) {
				//detected a mouse
				devtable[addr].devclass = HID_M;                  //device class
				tmpbyte = devtable[addr].epinfo->MaxPktSize;
				HID_init();                         //initialize data structures
				devtable[addr].epinfo = hid_ep; //switch endpoint information structure
				devtable[addr].epinfo[0].MaxPktSize = tmpbyte;
				hid_device.interface =
						data_ptr->descr.interface.bInterfaceNumber;
				hid_device.addr = addr;
				byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
				data_ptr = (USB_DESCR*) byte_ptr;
				while (byte_ptr < bigbuf + total_length) {
					if (data_ptr->descr.config.bDescriptorType
							!= USB_DESCRIPTOR_ENDPOINT) { //skip to endpoint descriptor
						byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
						data_ptr = (USB_DESCR*) byte_ptr;
					} else {
						/* fill endpoint information structure */
						devtable[addr].epinfo[1].epAddr =
								data_ptr->descr.endpoint.bEndpointAddress;
						devtable[addr].epinfo[1].Attr =
								data_ptr->descr.endpoint.bmAttributes;
						devtable[addr].epinfo[1].MaxPktSize =
								data_ptr->descr.endpoint.wMaxPacketSize;
						devtable[addr].epinfo[1].Interval =
								data_ptr->descr.endpoint.bInterval;
						// devtable[ addr ].epinfo[ 1 ].rcvToggle = bmRCVTOG0;
						/* configure device */
						rcode = XferSetConf(addr, 0, confvalue); //set configuration
						if (rcode) {   //error handling
							return (FALSE);
						}
						rcode = XferSetProto(addr, 0, hid_device.interface,
								BOOT_PROTOCOL);
						if (rcode) {   //error handling
							return (FALSE);
						} else {
							return (TRUE);
						}
					}
				}   //while( byte_ptr....
			}   //if (Class matches
			else { //if class don't match; die on first interface. Not really correct
				return (FALSE);
			}
		} //else if( data_ptr->
	} // while( byte_ptr < &buf + total_length
	return (FALSE);
}
/* HID Keyboard probe. Called from USB state machine.                           */
/* assumes configuration length is less than 256 bytes                          */
/* looks for Class:03, Subclass: 01, Protocol: 01 in interface descriptor       */
/* sets keyboard in boot protocol                                               */
/* assumes single configuration, single endpoint, and interface configuration 0 */
BOOL HIDKProbe(BYTE addr, DWORD flags) {
	BYTE tmpbyte;
	BYTE rcode;
	BYTE confvalue;
	WORD total_length;
	USB_DESCR* data_ptr = (USB_DESCR *) &bigbuf;
	BYTE* byte_ptr = bigbuf;
	rcode = XferGetConfDescr(addr, 0, CONF_DESCR_LEN, 0, bigbuf); //get configuration descriptor
	if (rcode) {   //error handling           
		return (FALSE);
	}
	if (data_ptr->descr.config.wTotalLength > 1024) {
		total_length = 1024;
	} else {
		total_length = data_ptr->descr.config.wTotalLength;
	}
	rcode = XferGetConfDescr(addr, 0, total_length, 0, bigbuf); //get the whole configuration
	if (rcode) {   //error handling
		return (FALSE);
	}
	confvalue = data_ptr->descr.config.bConfigurationValue; //save configuration value to use later
	while (byte_ptr < bigbuf + total_length) {             //parse configuration
		if (data_ptr->descr.config.bDescriptorType != USB_DESCRIPTOR_INTERFACE) { //skip to the next descriptor
			byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
			data_ptr = (USB_DESCR*) byte_ptr;
		} // if( data_ptr->descr.config.bDescriptorType != USB_DESCRIPTOR_INTERFACE
		else {
			//printf("starting interface parsing at byte location %d\n",
			//		data_ptr->descr.config.bLength);
			BYTE class = data_ptr->descr.interface.bInterfaceClass;
			BYTE subclass = data_ptr->descr.interface.bInterfaceSubClass;
			BYTE protocol = data_ptr->descr.interface.bInterfaceProtocol;
			//printf("class %x, subclass %x, protocol %x,\n", class, subclass,
			//		protocol);
			//interface descriptor
			if (class == HID_INTF && subclass == BOOT_INTF_SUBCLASS
					&& protocol == HID_PROTOCOL_KEYBOARD) {
				//detected a keyboard
				devtable[addr].devclass = HID_K;             //fill device class
				tmpbyte = devtable[addr].epinfo->MaxPktSize; //save max.packet size
				HID_init();                         //initialize data structures
				devtable[addr].epinfo = hid_ep; //switch endpoint information structure
				devtable[addr].epinfo[0].MaxPktSize = tmpbyte; //fill in max.packet size
				hid_device.interface =
						data_ptr->descr.interface.bInterfaceNumber; //fill in interface number to be used in HID requests
				hid_device.addr = addr;                        //fill in address
				byte_ptr = byte_ptr + data_ptr->descr.config.bLength; //skip to the next descriptor
				data_ptr = (USB_DESCR*) byte_ptr;
				while (byte_ptr < bigbuf + total_length) {
					if (data_ptr->descr.config.bDescriptorType
							!= USB_DESCRIPTOR_ENDPOINT) { //skip to endpoint descriptor
						byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
						data_ptr = (USB_DESCR*) byte_ptr;
					} else {
						/* fill endpoint information structure */
						devtable[addr].epinfo[1].epAddr =
								data_ptr->descr.endpoint.bEndpointAddress;
						devtable[addr].epinfo[1].Attr =
								data_ptr->descr.endpoint.bmAttributes;
						devtable[addr].epinfo[1].MaxPktSize =
								data_ptr->descr.endpoint.wMaxPacketSize;
						devtable[addr].epinfo[1].Interval =
								data_ptr->descr.endpoint.bInterval;
						/* configure device */
						rcode = XferSetConf(addr, 0, confvalue); //set configuration
						if (rcode) {   //error handling
							return (FALSE);
						}
						rcode = XferSetProto(addr, 0, hid_device.interface,
								BOOT_PROTOCOL);
						if (rcode) {   //error handling
							return (FALSE);
						} else {
							return (TRUE);
						}
					}
				}   //while( byte_ptr....
			}   //if (Class matches
			else { //if class don't match; stop processing after first interface. Not really correct
				return (FALSE);
			}
		} //else if( data_ptr->
	} // while( byte_ptr < &buf + total_length
	return (FALSE);
}

// Custom DualSense Probe
BOOL HIDGProbe(BYTE addr, DWORD flags) {
	BYTE tmpbyte;
	BYTE rcode;
	BYTE confvalue;
	WORD total_length;
	USB_DESCR* data_ptr = (USB_DESCR *) &bigbuf;
	USB_DEVICE_DESCRIPTOR dev_descr;
	BYTE* byte_ptr = bigbuf;
	rcode = XferGetConfDescr(addr, 0, CONF_DESCR_LEN, 0, bigbuf); //get configuration descriptor
	if (rcode) {   //error handling           
		return (FALSE);
	}
	if (data_ptr->descr.config.wTotalLength > 1024) {
		total_length = 1024;
	} else {
		total_length = data_ptr->descr.config.wTotalLength;
	}
	rcode = XferGetConfDescr(addr, 0, total_length, 0, bigbuf); //get the whole configuration
	if (rcode) {   //error handling
		return (FALSE);
	}
	// Get device description for vendor id etc.
	rcode = XferGetDevDescr(addr, 0, DEV_DESCR_LEN, (BYTE*)&dev_descr);
	if (rcode) {   //error handling
		return (FALSE);
	}
	confvalue = data_ptr->descr.config.bConfigurationValue; //save configuration value to use later
	while (byte_ptr < bigbuf + total_length) {             //parse configuration
		if (data_ptr->descr.config.bDescriptorType != USB_DESCRIPTOR_INTERFACE) { //skip to the next descriptor
			byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
			data_ptr = (USB_DESCR*) byte_ptr;
		} // if( data_ptr->descr.config.bDescriptorType != USB_DESCRIPTOR_INTERFACE
		else {
			//printf("starting interface parsing at byte location %d\n",
			//		data_ptr->descr.config.bLength);
			BYTE class = data_ptr->descr.interface.bInterfaceClass;
			WORD vendorID = dev_descr.idVendor;
			WORD productID = dev_descr.idProduct;
			//printf("class %x, subclass %x, protocol %x,\n", class, subclass,
			//		protocol);
			//interface descriptor
			if (class == HID_INTF && vendorID == SONY_VENDOR_ID && productID == DUALSENSE_PRODUCT_ID) {
				//detected a DualSense
				devtable[addr].devclass = HID_DS;             //fill device class
				tmpbyte = devtable[addr].epinfo->MaxPktSize; //save max.packet size
				HID_init();                         //initialize data structures
				devtable[addr].epinfo = hid_ep; //switch endpoint information structure
				devtable[addr].epinfo[0].MaxPktSize = tmpbyte; //fill in max.packet size
				hid_device.interface =
						data_ptr->descr.interface.bInterfaceNumber; //fill in interface number to be used in HID requests
				hid_device.addr = addr;                        //fill in address
				byte_ptr = byte_ptr + data_ptr->descr.config.bLength; //skip to the next descriptor
				data_ptr = (USB_DESCR*) byte_ptr;
				while (byte_ptr < bigbuf + total_length) {
					if (data_ptr->descr.config.bDescriptorType
							!= USB_DESCRIPTOR_ENDPOINT) { //skip to endpoint descriptor
						byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
						data_ptr = (USB_DESCR*) byte_ptr;
					} else {
						if ((data_ptr->descr.endpoint.bEndpointAddress & 0x80) != 0) {
							/* fill endpoint information structure */
							gamepad_ep = data_ptr->descr.endpoint.bEndpointAddress & 0x0F;
							devtable[addr].epinfo[gamepad_ep].epAddr = gamepad_ep;
							devtable[addr].epinfo[gamepad_ep].Attr =
									data_ptr->descr.endpoint.bmAttributes;
							devtable[addr].epinfo[gamepad_ep].MaxPktSize =
									data_ptr->descr.endpoint.wMaxPacketSize;
							devtable[addr].epinfo[gamepad_ep].Interval =
									data_ptr->descr.endpoint.bInterval;
							/* configure device */
							rcode = XferSetConf(addr, 0, confvalue); //set configuration
							if (rcode) {   //error handling
								return (FALSE);
							} else {
								return (TRUE);
							}
						} else {
							byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
							data_ptr = (USB_DESCR*) byte_ptr;
						}
					}
				}   //while( byte_ptr....
			}   //if (Class matches
			else { //if class don't match check others
				byte_ptr = byte_ptr + data_ptr->descr.config.bLength;
				data_ptr = (USB_DESCR*) byte_ptr;
			}
		} //else if( data_ptr->
	} // while( byte_ptr < &buf + total_length
	return (FALSE);
}

/* HID data structures initialization */
void HID_init(void) {
	for (int i = 0; i < 16; i = i+1) {
		hid_ep[i].sndToggle = bmSNDTOG0;
		hid_ep[i].rcvToggle = bmRCVTOG0;
	}
}
/* poll boot mouse */
BYTE mousePoll(BOOT_MOUSE_REPORT* buf) {
	BYTE rcode;
	MAXreg_wr( rPERADDR, hid_device.addr);    //set peripheral address
	rcode = XferInTransfer(hid_device.addr, 1, 8, (BYTE*) buf,
			devtable[hid_device.addr].epinfo[1].MaxPktSize);
	return (rcode);
}
/* poll boot keyboard */
BYTE kbdPoll(BOOT_KBD_REPORT* buf) {
	BYTE rcode;
	MAXreg_wr( rPERADDR, hid_device.addr);    //set peripheral address
	rcode = XferInTransfer(hid_device.addr, 1, 8, (BYTE*) buf,
			devtable[hid_device.addr].epinfo[1].MaxPktSize);
	return (rcode);
}
// poll gamepad
BYTE gamepadPoll(GAMEPAD_REPORT* buf) {
	BYTE rcode;
	MAXreg_wr( rPERADDR, hid_device.addr);    //set peripheral address
	rcode = XferInTransfer(hid_device.addr, gamepad_ep, 64, (BYTE*) buf,
			devtable[hid_device.addr].epinfo[gamepad_ep].MaxPktSize);
	return (rcode);
}
BOOL HIDMEventHandler(BYTE address, BYTE event, void *data, DWORD size) {
	return (FALSE);
}
BOOL HIDKEventHandler(BYTE address, BYTE event, void *data, DWORD size) {
	return (FALSE);
}
BOOL HIDGEventHandler(BYTE address, BYTE event, void *data, DWORD size) {
	return (FALSE);
}
