`timescale 1ns / 1ps

module sdf_scene(
    input  logic clk,
    input  logic reset, // Async high reset

    input  logic signed [15:0] pos_x_in,
    input  logic signed [15:0] pos_y_in,
    input  logic signed [15:0] pos_z_in,
    input  logic               in_valid,

    input  logic               carve_en,
    input  logic signed [15:0] carve_x,
    input  logic signed [15:0] carve_y,
    input  logic signed [15:0] carve_z,
    input  logic signed [15:0] carve_radius,

    input  logic        [3:0]  ray_tag_in,
    output logic        [3:0]  ray_tag_out,
    output logic signed [15:0] pos_x_out, pos_y_out, pos_z_out,

    output logic signed [15:0] dist_out,
    output logic               out_valid
);

    // Represents a 1 radius sphere at (0, 0, 0)
    localparam logic signed [15:0] center_x = 16'sh0000;
    localparam logic signed [15:0] center_y = 16'sh0000;
    localparam logic signed [15:0] center_z = 16'sh0000;
    localparam logic signed [15:0] radius   = 16'sh0100;

    // 14-stage position shift registers (aligned with registered Cycle 14 output)
    logic signed [15:0] pos_x [0:13];
    logic signed [15:0] pos_y [0:13];
    logic signed [15:0] pos_z [0:13];

    // 13-stage carve_en shift register to align with square root outputs
    logic carve_en_pipe [0:11];
    logic cur_carve_en;
    assign cur_carve_en = carve_en_pipe[11];

    //
    // Input Combinational Differences (Cycle 0)
    //
    
    logic signed [15:0] diff_x, diff_y, diff_z;
    logic signed [15:0] carve_diff_x, carve_diff_y, carve_diff_z;

    always_comb begin: SDF_INPUT_DIFFS
        diff_x = pos_x_in - center_x;
        diff_y = pos_y_in - center_y;
        diff_z = pos_z_in - center_z;

        carve_diff_x = pos_x_in - carve_x;
        carve_diff_y = pos_y_in - carve_y;
        carve_diff_z = pos_z_in - carve_z;
    end

    //
    // Stage 1 Component Square Registers (Cycle 1)
    //

    logic [15:0] r_sq_x, r_sq_y, r_sq_z;
    logic [15:0] r_carve_sq_x, r_carve_sq_y, r_carve_sq_z;
    logic        r_in_valid;
    logic [3:0]  r_ray_tag;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            r_sq_x       <= 16'd0;
            r_sq_y       <= 16'd0;
            r_sq_z       <= 16'd0;
            r_carve_sq_x <= 16'd0;
            r_carve_sq_y <= 16'd0;
            r_carve_sq_z <= 16'd0;
            r_in_valid   <= 1'b0;
            r_ray_tag    <= 4'd0;

            for (int i = 0; i < 14; i++) begin
                pos_x[i] <= 16'sh0000;
                pos_y[i] <= 16'sh0000;
                pos_z[i] <= 16'sh0000;
            end
            for (int i = 0; i < 12; i++) begin
                carve_en_pipe[i] <= 1'b0;
            end
        end else begin // Had to specify unsigned casts to avoid warnings
            r_sq_x       <= $unsigned(16'((32'(diff_x) * 32'(diff_x)) >>> 8));
            r_sq_y       <= $unsigned(16'((32'(diff_y) * 32'(diff_y)) >>> 8));
            r_sq_z       <= $unsigned(16'((32'(diff_z) * 32'(diff_z)) >>> 8));
            r_carve_sq_x <= $unsigned(16'((32'(carve_diff_x) * 32'(carve_diff_x)) >>> 8));
            r_carve_sq_y <= $unsigned(16'((32'(carve_diff_y) * 32'(carve_diff_y)) >>> 8));
            r_carve_sq_z <= $unsigned(16'((32'(carve_diff_z) * 32'(carve_diff_z)) >>> 8));

            r_in_valid   <= in_valid;
            r_ray_tag    <= ray_tag_in;

            pos_x[0] <= pos_x_in;
            pos_y[0] <= pos_y_in;
            pos_z[0] <= pos_z_in;
            for (int i = 1; i < 14; i++) begin
                pos_x[i] <= pos_x[i-1];
                pos_y[i] <= pos_y[i-1];
                pos_z[i] <= pos_z[i-1];
            end

            carve_en_pipe[0] <= carve_en;
            for (int i = 1; i < 12; i++) begin
                carve_en_pipe[i] <= carve_en_pipe[i-1];
            end
        end
    end

    assign pos_x_out = pos_x[13];
    assign pos_y_out = pos_y[13];
    assign pos_z_out = pos_z[13];

    //
    // 3-Term Sum into Square Root (Cycle 1 -> Cycle 2)
    //

    logic [15:0] comb_sq_D;
    logic [15:0] comb_carve_sq_D;

    assign comb_sq_D       = r_sq_x + r_sq_y + r_sq_z;
    assign comb_carve_sq_D = r_carve_sq_x + r_carve_sq_y + r_carve_sq_z;

    //
    // 12-Stage Square Root Pipelines (Cycles 1 to 13)
    //

    logic signed [15:0] sqrt_sq_D;
    logic signed [15:0] carve_sqrt_sq_D;
    logic               out_valid_sphere;
    logic [3:0]         sqrt_tag_out;

    fixed_point_sqrt_q8_8 sqrt_inst (
        .clk(clk),
        .rst_n(!reset),
        .in_valid(r_in_valid),
        .radicand(comb_sq_D),
        .root(sqrt_sq_D),
        .out_valid(out_valid_sphere),
        .tag_in(r_ray_tag),
        .tag_out(sqrt_tag_out)
    );

    fixed_point_sqrt_q8_8 carve_sqrt_inst (
        .clk(clk),
        .rst_n(!reset),
        .in_valid(r_in_valid && carve_en_pipe[0]),
        .radicand(comb_carve_sq_D),
        .root(carve_sqrt_sq_D),
        .out_valid(),
        .tag_in(4'd0),
        .tag_out()
    );

    //
    // Cycle 13 Combinational Distance Evaluation -> Cycle 14 Output Registers
    //

    logic signed [15:0] dist_sphere;
    logic signed [15:0] dist_carve;
    logic signed [15:0] comb_dist_out;

    always_comb begin: SDF_OUTPUT_EVAL
        dist_sphere    = sqrt_sq_D - radius;
        dist_carve     = carve_sqrt_sq_D - carve_radius;

        if (cur_carve_en) begin
            comb_dist_out = (dist_sphere > -dist_carve) ? dist_sphere : -dist_carve;
        end else begin
            comb_dist_out = dist_sphere;
        end
    end

    always_ff @(posedge clk or posedge reset) begin: SDF_OUTPUT_REG
        if (reset) begin
            dist_out    <= 16'sh0000;
            out_valid   <= 1'b0;
            ray_tag_out <= 4'd0;
        end else begin
            dist_out    <= comb_dist_out;
            out_valid   <= out_valid_sphere;
            ray_tag_out <= sqrt_tag_out;
        end
    end

endmodule
