`timescale 1ns / 1ps

module harpu_top (
    input  logic       Clk,
    input  logic       reset_rtl_0,

    // USB signals (MAX3421E host controller)
    input  logic [0:0] gpio_usb_int_tri_i,
    output logic       gpio_usb_rst_tri_o,
    input  logic       usb_spi_miso,
    output logic       usb_spi_mosi,
    output logic       usb_spi_sclk,
    output logic       usb_spi_ss,

    // UART
    input  logic       uart_rtl_0_rxd,
    output logic       uart_rtl_0_txd,

    // HDMI Differential Pairs
    output logic       hdmi_tmds_clk_n,
    output logic       hdmi_tmds_clk_p,
    output logic [2:0] hdmi_tmds_data_n,
    output logic [2:0] hdmi_tmds_data_p,
        
    // Dual 7-Segment HEX Displays
    output logic [7:0] hex_segA,
    output logic [3:0] hex_gridA,
    output logic [7:0] hex_segB,
    output logic [3:0] hex_gridB
);
    
    // Internal Clocks & Resets
    logic clk_25MHz, clk_125MHz;
    logic locked;
    logic reset_ah;
    assign reset_ah = reset_rtl_0; // Pushbutton 0 is active-high

    // MicroBlaze USB Keycode Registers
    logic [31:0] keycode0_gpio, keycode1_gpio;

    // Video Scanout & Sync Signals
    logic [9:0] drawX, drawY;
    logic hsync, vsync, vde;
    logic [3:0] red, green, blue;

    // Framebuffer Interconnect (Port A: 100MHz Write, Port B: 25MHz Read)
    logic [16:0] fb_addr_a;
    logic [11:0] fb_din_a;
    logic        fb_ena_a;
    logic        fb_wea_a;

    logic [16:0] fb_addr_b;
    logic        fb_ena_b;
    logic [11:0] fb_dout_b;

    // Carving Control Signals
    logic        carve_en;
    logic signed [15:0] carve_x, carve_y, carve_z;
    logic signed [15:0] carve_radius;
    logic signed [15:0] inv_carve_radius;

    hex_driver HexA (
        .clk(Clk),
        .reset(reset_ah),
        .in({4'h0, 4'h0, fps_display[7:4], fps_display[3:0]}),
        .hex_seg(hex_segA),
        .hex_grid(hex_gridA)
    );

    hex_driver HexB (
        .clk(Clk),
        .reset(reset_ah),
        .in({carve_x[7:4], carve_x[3:0], keycode0_gpio[7:4], keycode0_gpio[3:0]}),
        .hex_seg(hex_segB),
        .hex_grid(hex_gridB)
    );

    mb_harpu mb_harpu_i (
        .clk_100MHz(Clk),
        .gpio_usb_int_tri_i(gpio_usb_int_tri_i),
        .gpio_usb_keycode_0_tri_o(keycode0_gpio),
        .gpio_usb_keycode_1_tri_o(keycode1_gpio),
        .gpio_usb_rst_tri_o(gpio_usb_rst_tri_o),
        .reset_rtl_0(~reset_ah), // MicroBlaze Block Design expects active-low reset
        .uart_rtl_0_rxd(uart_rtl_0_rxd),
        .uart_rtl_0_txd(uart_rtl_0_txd),
        .usb_spi_miso(usb_spi_miso),
        .usb_spi_mosi(usb_spi_mosi),
        .usb_spi_sclk(usb_spi_sclk),
        .usb_spi_ss(usb_spi_ss)
    );
        
    clk_wiz_0 clk_wiz (
        .clk_out1(clk_25MHz),
        .clk_out2(clk_125MHz),
        .reset(reset_ah),
        .locked(locked),
        .clk_in1(Clk)
    );

    vga_controller vga (
        .pixel_clk(clk_25MHz),
        .reset(reset_ah),
        .hs(hsync),
        .vs(vsync),
        .active_nblank(vde),
        .drawX(drawX),
        .drawY(drawY)
    );

    assign fb_ena_a = 1'b1;

    logic [26:0] second_counter;
    always_ff @(posedge Clk or posedge reset_ah) begin
        if (reset_ah) begin
            second_counter <= 27'd0;
        end else if (second_counter == 27'd99999999) begin
            second_counter <= 27'd0;
        end else begin
            second_counter <= second_counter + 27'd1;
        end
    end

    logic [7:0] frame_counter;
    logic [7:0] fps_display;
    logic       frame_done;
    always_ff @(posedge Clk or posedge reset_ah) begin
        if (reset_ah) begin
            frame_counter <= 8'd0;
        end else if (second_counter == 27'd99999999) begin
            fps_display <= frame_counter;
            frame_counter <= 8'd0;
        end else if (frame_done) begin
            frame_counter <= frame_counter + 8'd1;
        end
    end

    logic [1:0] sphere_material;

    raymarch_core raymarch_inst (
        .clk(Clk),
        .reset(reset_ah),
        .drawX(drawX),
        .drawY(drawY),
        .carve_en(carve_en),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .carve_radius(carve_radius),
        .fb_addr(fb_addr_a),
        .fb_din(fb_din_a),
        .fb_we(fb_wea_a),
        .frame_done(frame_done),
        .inv_carve_radius(inv_carve_radius),
        .sphere_material(sphere_material)
    );

    carve_controller carve_controller_inst (
        .clk(Clk),
        .reset(reset_ah),
        .frame_tick(frame_done),
        .usb_data_in({ keycode1_gpio, keycode0_gpio }),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .carve_radius(carve_radius),
        .carve_en(carve_en),
        .sphere_material(sphere_material),
        .inv_carve_radius(inv_carve_radius)
    );

    framebuffer_memory fb_mem_inst (
        .clka(Clk),
        .ena_a(fb_ena_a),
        .wea_a(fb_wea_a),
        .address_a(fb_addr_a),
        .din_a(fb_din_a),
        
        .clkb(clk_25MHz),
        .ena_b(fb_ena_b),
        .address_b(fb_addr_b),
        .dout_b(fb_dout_b)
    );

    color_mapper color_instance (
        .pixel_clk(clk_25MHz),
        .reset(reset_ah),
        .drawX(drawX),
        .drawY(drawY),
        .address_b(fb_addr_b),
        .ena_b(fb_ena_b),
        .dout_b(fb_dout_b),
        .red(red),
        .green(green),
        .blue(blue),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_radius(carve_radius)
    );

    hdmi_tx_0 vga_to_hdmi (
        .pix_clk(clk_25MHz),
        .pix_clkx5(clk_125MHz),
        .pix_clk_locked(locked),
        .rst(reset_ah),
        
        .red(red),
        .green(green),
        .blue(blue),
        .hsync(hsync),
        .vsync(vsync),
        .vde(vde),
        
        .aux0_din(4'b0),
        .aux1_din(4'b0),
        .aux2_din(4'b0),
        .ade(1'b0),
        
        .TMDS_CLK_P(hdmi_tmds_clk_p),          
        .TMDS_CLK_N(hdmi_tmds_clk_n),          
        .TMDS_DATA_P(hdmi_tmds_data_p),         
        .TMDS_DATA_N(hdmi_tmds_data_n)          
    );

endmodule
