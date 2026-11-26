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
    input  logic        [1:0]  surface_mode,
    input  logic        [7:0]  anim_phase,

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
    logic signed [15:0] r_sin_x_comb, r_sin_y_comb, r_sin_z_comb, r_sin_x2_comb, r_sin_y2_comb, r_sin_z2_comb;
    logic signed [15:0] r_cos_x_comb, r_cos_y_comb, r_cos_z_comb, r_cos_x2_comb, r_cos_y2_comb, r_cos_z2_comb;
    logic signed [15:0] r_sin_x, r_sin_y, r_sin_z, r_sin_x2, r_sin_y2, r_sin_z2;
    logic signed [15:0] r_cos_x, r_cos_y, r_cos_z, r_cos_x2, r_cos_y2, r_cos_z2 ;
    logic [7:0] gx, gy, gz, gx2, gy2, gz2;

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

    // Surface Mode Handling
    always_comb begin
        gx2 = 8'd0;
        gy2 = 8'd0;
        gz2 = 8'd0;

        case (surface_mode)
            2'b00: begin // Default: Sphere only
                gx = 8'd0;
                gy = 8'd0;
                gz = 8'd0;
            end
            2'b01: begin // Gyroid
                gx = pos_x_in[7:0] + anim_phase;
                gy = pos_y_in[7:0] - anim_phase;
                gz = pos_z_in[7:0] + (anim_phase >> 1);
            end
            2'b10: begin // Rocky
                gx  = pos_x_in[8:1] + pos_z_in[9:2];
                gy  = pos_y_in[8:1] - pos_x_in[9:2];
                gz  = pos_z_in[8:1] + pos_y_in[9:2];

                gx2 = {pos_x_in[6:0], 1'b0} - pos_y_in[7:0] + 8'd37 + anim_phase;
                gy2 = {pos_y_in[6:0], 1'b0} + pos_z_in[7:0] + 8'd91 - anim_phase;
                gz2 = {pos_z_in[6:0], 1'b0} - pos_x_in[7:0] + 8'd149;
            end
            2'b11: begin // Ribbing
                gx = {carve_diff_x[4:0], 3'b0} + {anim_phase[6:0], 1'b0};
                gy = {carve_diff_y[4:0], 3'b0} + {anim_phase[6:0], 1'b0};
                gz = {carve_diff_z[4:0], 3'b0} + {anim_phase[6:0], 1'b0};
            end
            default: begin // Fallback to Sphere only
                gx = 8'd0;
                gy = 8'd0;
                gz = 8'd0;
            end
        endcase
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

            r_sin_x <= 16'sh0000;
            r_sin_y <= 16'sh0000;
            r_sin_z <= 16'sh0000;
            r_cos_x <= 16'sh0100;
            r_cos_y <= 16'sh0100;
            r_cos_z <= 16'sh0100;
            r_sin_x2 <= 16'sh0000;
            r_sin_y2 <= 16'sh0000;
            r_sin_z2 <= 16'sh0000;
            r_cos_x2 <= 16'sh0100;
            r_cos_y2 <= 16'sh0100;
            r_cos_z2 <= 16'sh0100;

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

            r_sin_x <= r_sin_x_comb;
            r_sin_y <= r_sin_y_comb;
            r_sin_z <= r_sin_z_comb;
            r_cos_x <= r_cos_x_comb;
            r_cos_y <= r_cos_y_comb;
            r_cos_z <= r_cos_z_comb;
            r_sin_x2 <= r_sin_x2_comb;
            r_sin_y2 <= r_sin_y2_comb;
            r_sin_z2 <= r_sin_z2_comb;
            r_cos_x2 <= r_cos_x2_comb;
            r_cos_y2 <= r_cos_y2_comb;
            r_cos_z2 <= r_cos_z2_comb;

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

    // Sincos for gyroid and other modes
    lut_sincos gx_sincos (
        .theta  (gx),
        .sin_out(r_sin_x_comb),
        .cos_out(r_cos_x_comb)
    );

    lut_sincos gy_sincos (
        .theta  (gy),
        .sin_out(r_sin_y_comb),
        .cos_out(r_cos_y_comb)
    );

    lut_sincos gz_sincos (
        .theta  (gz),
        .sin_out(r_sin_z_comb),
        .cos_out(r_cos_z_comb)
    );

    lut_sincos gx2_sincos (
        .theta  (gx2),
        .sin_out(r_sin_x2_comb),
        .cos_out(r_cos_x2_comb)
    );

    lut_sincos gy2_sincos (
        .theta  (gy2),
        .sin_out(r_sin_y2_comb),
        .cos_out(r_cos_y2_comb)
    );

    lut_sincos gz2_sincos (
        .theta  (gz2),
        .sin_out(r_sin_z2_comb),
        .cos_out(r_cos_z2_comb)
    );

    //
    // Get gyroid sum and delay to match sqrt_sq_D
    //

    logic signed [15:0] g_px, g_py, g_pz, g_px2, g_py2, g_pz2;
    logic signed [15:0] oct1, oct2;
    logic signed [15:0] r_sin_x_d1;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            g_px <= 16'sh0000;
            g_py <= 16'sh0000;
            g_pz <= 16'sh0000;
            g_px2 <= 16'sh0000;
            g_py2 <= 16'sh0000;
            g_pz2 <= 16'sh0000;
            r_sin_x_d1 <= 16'sh0000;
        end else begin
            g_px <= 16'((32'(r_sin_x) * 32'(r_cos_y)) >>> 8);
            g_py <= 16'((32'(r_sin_y) * 32'(r_cos_z)) >>> 8);
            g_pz <= 16'((32'(r_sin_z) * 32'(r_cos_x)) >>> 8);
            g_px2 <= 16'((32'(r_sin_x2) * 32'(r_cos_y2)) >>> 8);
            g_py2 <= 16'((32'(r_sin_y2) * 32'(r_cos_z2)) >>> 8);
            g_pz2 <= 16'((32'(r_sin_z2) * 32'(r_cos_x2)) >>> 8);

            r_sin_x_d1 <= r_sin_x;
        end
    end

    assign oct1 = g_px + g_py + g_pz;
    assign oct2 = g_px2 + g_py2 + g_pz2;

    logic signed [15:0] g_sum;
    logic signed [15:0] g_sum_pipe [0:9]; // 10 cycle delay to match sqrt_sq_D

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            g_sum <= 16'sh0000;

            for (int i = 0; i < 10; i++) begin
                g_sum_pipe[i] <= 16'sh0000;
            end
        end else begin
            if (surface_mode == 2'd2) begin
                g_sum <= (oct1 >>> 4) + (oct2 >>> 6);
            end else begin
                g_sum <= (surface_mode == 2'd3) ? r_sin_x_d1 : g_px + g_py + g_pz;
            end

            g_sum_pipe[0] <= g_sum;
            for (int i = 1; i < 10; i++) begin
                g_sum_pipe[i] <= g_sum_pipe[i-1];
            end
        end
    end

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
    logic signed [15:0] dist_gyroid;
    logic signed [15:0] d_carve_mod;
    logic signed [15:0] comb_dist_out;
    logic signed [15:0] d_raw;
    logic signed [15:0] d_base;
    logic signed [15:0] g_val;
    logic signed [15:0] g_bias;

    always_comb begin: SDF_OUTPUT_EVAL
        dist_sphere    = sqrt_sq_D - radius;
        dist_carve     = carve_sqrt_sq_D - carve_radius;
        g_val          = g_sum_pipe[9];
        g_bias         = g_val + 16'sh0030; // +ve = More open, -ve = Thicker

        dist_gyroid = (g_bias >>> 4) + (g_bias >>> 5);
        d_raw = dist_sphere + g_val;
        d_carve_mod = dist_carve + (g_val >>> 6);

        case (surface_mode)
            2'b00: begin // Sphere only
                d_base = dist_sphere;
            end
            2'b01: begin // Gyroid
                d_base = (dist_sphere > dist_gyroid) ? dist_sphere : dist_gyroid;
            end
            2'b10: begin // Rocky
                d_base = d_raw - (d_raw >>> 2);
            end
            default: begin // Fallback to Sphere only
                d_base = dist_sphere;
            end
        endcase

        if (cur_carve_en) begin
            if (surface_mode == 2'b11) begin // Ribbing
                comb_dist_out = ((d_base > -d_carve_mod) ? d_base : -d_carve_mod) - 16'sh0008;
            end else begin
                comb_dist_out = (d_base > -dist_carve) ? d_base : -dist_carve;
                
            end
        end else begin
            comb_dist_out = d_base;
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
