`timescale 1ns / 1ps

module color_mapper (
    input  logic        pixel_clk,
    input  logic        reset,
    input  logic [9:0]  drawX,
    input  logic [9:0]  drawY,
    input  logic signed [15:0] carve_x,
    input  logic signed [15:0] carve_y,
    input  logic signed [15:0] carve_radius,
    
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

    // Overlay stuff
    logic signed [15:0] x_0, y_0, R, delta_x, delta_y, x_r_diff, y_r_diff;
    logic signed [15:0] GAP = 16'sd3; // pixel gap
    logic signed [15:0] LENGTH = 16'sd10; // pixel length
    logic signed [15:0] CORNER_LEN = 16'sd4; // pixel corner length

    logic is_crosshair;
    logic is_corner;

    assign x_0 = 320 + (((carve_x <<< 4) - carve_x) >>> 4);
    assign y_0 = 240 - (((carve_y <<< 4) - carve_y) >>> 4);
    assign R = (((carve_radius <<< 4) - carve_radius) >>> 4);

    assign delta_x = (drawX > x_0) ? drawX - x_0 : x_0 - drawX;
    assign delta_y = (drawY > y_0) ? drawY - y_0 : y_0 - drawY;
    assign x_r_diff = (delta_x > R) ? delta_x - R : R - delta_x;
    assign y_r_diff = (delta_y > R) ? delta_y - R : R - delta_y;


    assign is_crosshair = ((delta_x >= GAP) && (delta_x <= LENGTH) && (delta_y <= 16'sd1)) || ((delta_y >= GAP) && (delta_y <= LENGTH) && (delta_x <= 16'sd1));
    assign is_corner = ((x_r_diff <= 16'sd1) && (delta_y >= (R - CORNER_LEN)) && (delta_y <= R)) || ((y_r_diff <= 16'sd1) && (delta_x >= (R - CORNER_LEN)) && (delta_x <= R));

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
            if (is_crosshair || is_corner) begin
                {red, green, blue} = ~dout_b;
            end else begin
                {red, green, blue} = dout_b;
            end
        end else begin
            {red, green, blue} = 12'h000;
        end
    end

endmodule
