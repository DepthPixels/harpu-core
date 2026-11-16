`timescale 1ns / 1ps

module carve_controller(
    input logic clk,
    input logic reset, // Async high reset
    input logic frame_tick,
    input logic [7:0] keycode,

    output logic signed [15:0] carve_x,
    output logic signed [15:0] carve_y,
    output logic signed [15:0] carve_z,
    output logic signed [15:0] carve_radius,
    output logic signed [15:0] inv_carve_radius,
    output logic carve_en
);

    logic signed [15:0] step_size = 16'sh0010;

    logic tick_dly;
    logic tick_pulse;
    assign tick_pulse = frame_tick && !tick_dly;

    // 256-entry reciprocal lookup table: 65536 / R (in Q8.8)
    logic signed [15:0] inv_rom [0:255];
    initial begin
        inv_rom[0] = 16'sh7FFF;
        inv_rom[1] = 16'sh7FFF;
        inv_rom[2] = 16'sh7FFF;
        for (int i = 3; i < 256; i++) begin
            inv_rom[i] = 16'(32'd65536 / i);
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            carve_x <= 16'sh005A;
            carve_y <= 16'sh005A;
            carve_z <= 16'shFF26;
            carve_radius <= 16'sh005A;
            carve_en <= 1'b1;
        end else if (tick_pulse) begin
            case (keycode)
                8'h1A: carve_y <= carve_y + step_size; // W
                8'h16: carve_y <= carve_y - step_size; // S
                8'h07: carve_x <= carve_x + step_size; // D
                8'h04: carve_x <= carve_x - step_size; // A
                8'h08: carve_z <= carve_z + step_size; // E
                8'h14: carve_z <= carve_z - step_size; // Q
                8'h15: begin // R (increase radius)
                    if (carve_radius < 16'sh00DA)
                        carve_radius <= carve_radius + step_size;
                end
                8'h09: begin // F (decrease radius)
                    if (carve_radius > 16'sh001A)
                        carve_radius <= carve_radius - step_size;
                end
                8'h2C: carve_en <= ~carve_en; // Space
                default: begin end
            endcase
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            inv_carve_radius <= 16'sh02D8;
        end else begin
            inv_carve_radius <= inv_rom[carve_radius[7:0]];
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            tick_dly <= 1'b0;
        end else begin
            tick_dly <= frame_tick;
        end
    end

endmodule
