`timescale 1ns / 1ps

//-------------------------------------------------------------------------
//  fb_test_writer.sv (Optimized & Glitch-Free)
//  Generates test patterns and fills the 320x240 BRAM Framebuffer.
//  Uses counter-based bar generation (zero division) and registered outputs
//  for robust 100 MHz timing closure.
//-------------------------------------------------------------------------

module fb_test_writer (
    input  logic        clk,        // 100 MHz system clock
    input  logic        reset,      // Active-high reset
    input  logic [7:0]  keycode,    // Current USB keycode

    // BRAM Port A Interface (Fully Registered Outputs)
    output logic [16:0] address_a,
    output logic [11:0] din_a,
    output logic        ena_a,
    output logic [0:0]  wea_a
);

    logic [16:0] addr_cnt;
    logic [8:0]  pixel_x;
    logic [7:0]  pixel_y;

    // Sub-counter and bar index for glitch-free 20-pixel color bars
    logic [4:0]  bar_sub_x;
    logic [2:0]  bar_idx;

    logic [11:0] next_color;

    // Sequential address, coordinate counters, and color-bar trackers
    always_ff @(posedge clk) begin
        if (reset) begin
            addr_cnt  <= 17'd0;
            pixel_x   <= 9'd0;
            pixel_y   <= 8'd0;
            bar_sub_x <= 5'd0;
            bar_idx   <= 3'd0;
        end else begin
            // Address Counter: 0 to 76,799
            if (addr_cnt == 17'd76799) begin
                addr_cnt <= 17'd0;
            end else begin
                addr_cnt <= addr_cnt + 17'd1;
            end

            // Raster X / Y Coordinates (320 x 240)
            if (pixel_x == 9'd319) begin
                pixel_x <= 9'd0;
                pixel_y <= (pixel_y == 8'd239) ? 8'd0 : pixel_y + 8'd1;
                bar_sub_x <= 5'd0;
                bar_idx   <= 3'd0;
            end else begin
                pixel_x <= pixel_x + 9'd1;

                // Color Bar Counter (Quadrant 2: X in [160..319], Y < 120)
                if (pixel_x < 9'd160) begin
                    bar_sub_x <= 5'd0;
                    bar_idx   <= 3'd0;
                end else begin
                    if (bar_sub_x == 5'd19) begin
                        bar_sub_x <= 5'd0;
                        bar_idx   <= bar_idx + 3'd1;
                    end else begin
                        bar_sub_x <= bar_sub_x + 5'd1;
                    end
                end
            end
        end
    end

    // Combinational pattern generation
    always_comb begin
        // 1. White border around frame edge (320x240 boundary check)
        if (pixel_x == 9'd0 || pixel_x == 9'd319 || pixel_y == 8'd0 || pixel_y == 8'd239) begin
            next_color = 12'hFFF;
        end
        // 2. Gray crosshair grid splitting quadrants
        else if (pixel_x == 9'd160 || pixel_y == 8'd120) begin
            next_color = 12'h444;
        end
        // 3. Top-Left Quadrant (X < 160, Y < 120): Smooth 2D RGB gradient + Keycode tint
        else if (pixel_x < 9'd160 && pixel_y < 8'd120) begin
            next_color = {pixel_x[7:4], pixel_y[6:3], (keycode != 8'h00) ? keycode[3:0] : 4'h8};
        end
        // 4. Top-Right Quadrant (X >= 160, Y < 120): 8 Standard SMPTE Color Bars (Zero Division)
        else if (pixel_x >= 9'd160 && pixel_y < 8'd120) begin
            case (bar_idx)
                3'd0: next_color = 12'hFFF; // White
                3'd1: next_color = 12'hFF0; // Yellow
                3'd2: next_color = 12'h0FF; // Cyan
                3'd3: next_color = 12'h0F0; // Green
                3'd4: next_color = 12'hF0F; // Magenta
                3'd5: next_color = 12'hF00; // Red
                3'd6: next_color = 12'h00F; // Blue
                default: next_color = 12'h111; // Dark / Black
            endcase
        end
        // 5. Bottom-Left Quadrant (X < 160, Y >= 120): High-frequency 8x8 Checkerboard
        else if (pixel_x < 9'd160 && pixel_y >= 8'd120) begin
            if (pixel_x[3] ^ pixel_y[3])
                next_color = (keycode == 8'h16) ? 12'h0F0 : 12'h0BC; // Green on key 's'
            else
                next_color = (keycode == 8'h04) ? 12'hF00 : 12'h224; // Red on key 'a'
        end
        // 6. Bottom-Right Quadrant (X >= 160, Y >= 120): Concentric Distance Rings (Center at 240, 180)
        else begin
            logic [8:0] dx;
            logic [7:0] dy;
            logic [8:0] distance;

            dx = (pixel_x >= 9'd240) ? (pixel_x - 9'd240) : (9'd240 - pixel_x);
            dy = (pixel_y >= 8'd180) ? (pixel_y - 8'd180) : (8'd180 - pixel_y);
            distance = dx + {1'b0, dy};

            if (distance < 9'd15)
                next_color = (keycode == 8'h07) ? 12'h00F : 12'hFA0; // Orange core (Blue on key 'd')
            else if (distance < 9'd30)
                next_color = 12'hD50;
            else if (distance < 9'd45)
                next_color = 12'h920;
            else if (distance < 9'd60)
                next_color = 12'h510;
            else
                next_color = 12'h102;
        end
    end

    // Fully registered output pipeline to BRAM Port A
    always_ff @(posedge clk) begin
        if (reset) begin
            address_a <= 17'd0;
            din_a     <= 12'd0;
            ena_a     <= 1'b0;
            wea_a     <= 1'b0;
        end else begin
            address_a <= addr_cnt;
            din_a     <= next_color;
            ena_a     <= 1'b1;
            wea_a     <= 1'b1;
        end
    end

endmodule
