`timescale 1ns / 1ps

module color_mapper (
    input  logic        pixel_clk,
    input  logic        reset,
    input  logic [9:0]  drawX,
    input  logic [9:0]  drawY,
    
    // BRAM Port B Read Interface
    output logic [16:0] address_b,
    output logic        ena_b,
    input  logic [11:0] dout_b,

    // RGB Output to hdmi_tx_0
    output logic [3:0]  red,
    output logic [3:0]  green,
    output logic [3:0]  blue
);

    logic [9:0] next_x;
    logic [8:0] fb_x;
    logic [7:0] fb_y;

    // Compensate for 1-cycle BRAM read latency by pre-fetching next pixel
    assign next_x = (drawX < 10'd639) ? (drawX + 10'd1) : 10'd0;

    // 2x Pixel Upscaler: divide screen coordinates by 2
    // 640x480 -> 320x240
    assign fb_x = next_x[9:1]; // 0 to 319
    assign fb_y = drawY[9:1];  // 0 to 239

    // Linear Address: fb_y * 320 + fb_x
    // (fb_y << 8) + (fb_y << 6) + fb_x = 256*y + 64*y + x = 320*y + x
    assign address_b = ({1'b0, fb_y, 8'b0} + {3'b0, fb_y, 6'b0}) + {8'b0, fb_x};
    assign ena_b     = 1'b1;

    always_comb begin
        if ((drawX < 10'd640) && (drawY < 10'd480)) begin
            {red, green, blue} = dout_b;
        end else begin
            {red, green, blue} = 12'h000;
        end
    end

endmodule
