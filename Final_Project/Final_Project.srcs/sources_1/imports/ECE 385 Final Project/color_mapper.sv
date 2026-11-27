`timescale 1ns / 1ps

module color_mapper (
    input  logic        pixel_clk,
    input  logic        reset,
    input  logic [9:0]  drawX,
    input  logic [9:0]  drawY,
    input  logic signed [15:0] carve_x,
    input  logic signed [15:0] carve_y,
    input  logic signed [15:0] carve_radius,
    
    //HUD - FPS, carve size & shape
    
    input logic [7:0] fps_in,
    input logic [1:0] control_mode,
    input logic [1:0] tool_id,mode_in,material_in,
    input logic hud_en,
    
    // BRAM Port B Read Interface
    output logic [16:0] address_b,
    output logic        ena_b,
    input  logic [23:0] dout_b,

    // RGB Output to hdmi_tx_0 (8-bit per channel TrueColor)
    output logic [7:0]  red,
    output logic [7:0]  green,
    output logic [7:0]  blue
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
    
    //HUD Overlay
    parameter int num_char = 8; //Edit for bigger bounds - set to 8 as initial
    logic [7:0] stab_fps, sync_fps;
    logic[ 1:0] stab_mode, sync_mode;
    logic [1:0] stab_mat, sync_mat;
    always_ff @(posedge pixel_clk) begin
        stab_fps <= fps_in;
        sync_fps <= stab_fps;
        stab_mode <= control_mode;
        sync_mode <= stab_mode;
        stab_mat <= material_in;
        sync_mat <= stab_mat;
    end
    
    //Conversion for FPS into Decimal
    logic [11:0] holder_dcm;
    logic [3:0] hun,ten,one;
    logic [3:0] bcd_h,bcd_t,bcd_o;
    logic [7:0] post_fps;
    
    hex_to_bcd fps_bcd (.value(sync_fps), .decim(holder_dcm)); //Converts hex to decimal in hundreds, tens, ones
    assign hun = holder_dcm[11:8];
    assign ten = holder_dcm[7:4];
    assign one = holder_dcm[3:0];
    
    always_ff @(posedge pixel_clk) begin //Updates FPS if detects a change(reset, fps dif)
        if (reset) begin
            post_fps <= 8'd0;
            bcd_h <= 4'd0; bcd_t <= 4'd0; bcd_o <= 4'd0;
        end else if (sync_fps != post_fps) begin
            post_fps <= sync_fps;
            bcd_h <= hun; bcd_t <= ten; bcd_o <= one;
        end
    end
    
    logic [6:0] tool_char;
    //Tool Mode Selector - Will be added later
    always_comb begin
        case(sync_mode)
            2'b00:   tool_char = 7'h43;   //C = carve
            2'b01:   tool_char = 7'h4C;   //L = light
            2'b10:   tool_char = 7'h56;   //V = camera view
            default: tool_char = 7'h20; //Else = space
        endcase
    end
    //Codes: F=x46, P=x50, S=x53, C=x43, 
    // A=x41 a=x61, e=x65, r = x72, v=x76
    //abcdefghijklmnopqrstuvwxyz
    //Vals: 0=x30, 9=x39
    //Space: x20
    //FPS hto MODE C 
    logic [6:0] carr [0:num_char-1];
    logic [9:0] char_x0 [0:num_char-1];
    localparam int hud_x = 640 - 8*num_char;
    always_comb begin
        carr[0] = 7'h46; char_x0[0] = hud_x; //FPS hto
        carr[1] = 7'h50; char_x0[1] = hud_x+8;
        carr[2] = 7'h53; char_x0[2] = hud_x+16;
        carr[3] = 7'h20; char_x0[3] = hud_x+24;
        carr[4] = 7'h30 + bcd_h; char_x0[4] = hud_x+32;
        carr[5] = 7'h30 + bcd_t; char_x0[5] = hud_x+40;
        carr[6] = 7'h30 + bcd_o; char_x0[6] = hud_x+48;
        carr[7] = 7'h20; char_x0[7] = hud_x+56; //FIN fps
        /* Update when needed - Only fps is necessary rn.
        carr[8] = 7'h4d; char_x0[8] = hud_x+64; //MAT C
        carr[9] = 7'h41; char_x0[9] = hud_x+72;
        carr[10] = 7'h20; char_x0[10] = hud_x+80;
        carr[11] = 7'h20; char_x0[11] = hud_x+88;
        carr[12] = 7'h20; char_x0[12] = hud_x+96;*/
    end
    
    wire [7:0] glyph [0:num_char-1];
    logic ink [0:num_char-1];
    
    generate //Run for each cell
        for (genvar i=0;i<num_char;i++)begin : gen_cell
            logic [10:0] lx,ly;
            logic [3:0] row;
            logic [2:0] col;
            logic inner;
            logic [10:0] font_addr; 
            assign inner = (drawX >= char_x0[i]) && (drawX < char_x0[i]+8) && (drawY >= 10'd464) && (drawY < 10'd480);
            assign lx = {1'b0, drawX} - {1'b0, char_x0[i]}; 
            assign ly = {1'b0, drawY} - 10'd472; // Up 3 - finds bounds
            
            assign col = lx[2:0];
            assign row = ly[3:0];
            assign font_addr = {carr[i],row};
            assign ink[i] = inner && glyph[i][7-col];
            
            font_rom u_font (.addr(font_addr), .data(glyph[i]));
        end
    endgenerate
            
    //is the hud on
    logic hud_on;
    always_comb begin
        hud_on = 1'b0;
        for (int i=0;i<num_char;i++)
            hud_on = hud_on | ink[i];
    end

    always_comb begin
        if ((drawX < 10'd640) && (drawY < 10'd480)) begin
            if (is_crosshair || is_corner) begin
                {red, green, blue} = ~dout_b;
            end else if (hud_on && hud_en) begin
                {red, green, blue} = 24'hFFFFFF;
            end else begin
                {red, green, blue} = dout_b;
                
            end
        end else begin
            {red, green, blue} = 24'h000000;
        end
    end

endmodule
