`timescale 1ns / 1ps

module sphere_shader (
    input  logic               clk,
    input  logic               reset,
    input  logic signed [15:0] norm_x,
    input  logic signed [15:0] norm_y,
    input  logic signed [15:0] norm_z,
    output logic        [11:0] shaded_output
);

    // Direction to light source: [0.5, 0.6, -0.625] normalized in Q8.8
    localparam logic signed [15:0] LIGHT_DIR_X = 16'sh0080;
    localparam logic signed [15:0] LIGHT_DIR_Y = 16'sh0099;
    localparam logic signed [15:0] LIGHT_DIR_Z = 16'shFF60;

    // Blinn-Phong Half-vector: (L + V) / |L + V| with V = [0, 0, -1]
    localparam logic signed [15:0] HALF_X = 16'sh0047; // +0.277
    localparam logic signed [15:0] HALF_Y = 16'sh0055; // +0.333
    localparam logic signed [15:0] HALF_Z = 16'shFF19; // -0.901

    localparam logic [3:0] AMBIENT = 4'd3;

    // -------------------------------------------------------------
    // Stage 1A: Component Multiplications in Parallel (6 independent un-cascaded DSPs)
    // -------------------------------------------------------------
    logic signed [31:0] p_lx, p_ly, p_lz;
    logic signed [31:0] p_hx, p_hy, p_hz;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            p_lx <= 32'sd0;
            p_ly <= 32'sd0;
            p_lz <= 32'sd0;
            p_hx <= 32'sd0;
            p_hy <= 32'sd0;
            p_hz <= 32'sd0;
        end else begin
            p_lx <= 32'(norm_x) * 32'(LIGHT_DIR_X);
            p_ly <= 32'(norm_y) * 32'(LIGHT_DIR_Y);
            p_lz <= 32'(norm_z) * 32'(LIGHT_DIR_Z);
            p_hx <= 32'(norm_x) * 32'(HALF_X);
            p_hy <= 32'(norm_y) * 32'(HALF_Y);
            p_hz <= 32'(norm_z) * 32'(HALF_Z);
        end
    end

    // -------------------------------------------------------------
    // Stage 1B: Fast Adder Tree Sum and Clamping into Stage 1 Registers
    // -------------------------------------------------------------
    logic signed [31:0] dp_sum;
    logic signed [31:0] hdp_sum;
    logic signed [15:0] dp_comb;
    logic signed [15:0] hdp_comb;

    assign dp_sum  = p_lx + p_ly + p_lz;
    assign hdp_sum = p_hx + p_hy + p_hz;

    assign dp_comb  = 16'(dp_sum >>> 8);
    assign hdp_comb = 16'(hdp_sum >>> 8);

    logic signed [15:0] st1_dot;
    logic signed [15:0] st1_half;
    logic               st1_spec_valid;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st1_dot        <= 16'sh0000;
            st1_half       <= 16'sh0000;
            st1_spec_valid <= 1'b0;
        end else begin
            st1_dot        <= dp_comb;
            st1_half       <= (hdp_comb[15] == 1'b0) ? hdp_comb : 16'sh0000;
            st1_spec_valid <= (dp_comb > 16'sh0000) && (hdp_comb[15] == 1'b0);
        end
    end

    // -------------------------------------------------------------
    // Stage 2: Specular S2 = S1^2
    // -------------------------------------------------------------
    logic signed [31:0] s2_mult;
    logic signed [15:0] s2_comb;

    assign s2_mult = 32'(st1_half) * 32'(st1_half);
    assign s2_comb = 16'(s2_mult >>> 8);

    logic signed [15:0] st2_dot;
    logic signed [15:0] st2_s2;
    logic               st2_spec_valid;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st2_dot        <= 16'sh0000;
            st2_s2         <= 16'sh0000;
            st2_spec_valid <= 1'b0;
        end else begin
            st2_dot        <= st1_dot;
            st2_s2         <= st1_spec_valid ? s2_comb : 16'sh0000;
            st2_spec_valid <= st1_spec_valid;
        end
    end

    // -------------------------------------------------------------
    // Stage 3: Specular S4 = S2^2
    // -------------------------------------------------------------
    logic signed [31:0] s4_mult;
    logic signed [15:0] s4_comb;

    assign s4_mult = 32'(st2_s2) * 32'(st2_s2);
    assign s4_comb = 16'(s4_mult >>> 8);

    logic signed [15:0] st3_dot;
    logic signed [15:0] st3_s4;
    logic               st3_spec_valid;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st3_dot        <= 16'sh0000;
            st3_s4         <= 16'sh0000;
            st3_spec_valid <= 1'b0;
        end else begin
            st3_dot        <= st2_dot;
            st3_s4         <= st2_spec_valid ? s4_comb : 16'sh0000;
            st3_spec_valid <= st2_spec_valid;
        end
    end

    // -------------------------------------------------------------
    // Final Stage (Combinational from Stage 3 Registers):
    // S8 = S4^2, Diffuse, Ambient, Specular Clamping & RGB Pack
    // -------------------------------------------------------------
    logic signed [31:0] s8_mult;
    logic signed [15:0] s8_comb;
    logic        [3:0]  specular;
    logic        [3:0]  diffuse;
    logic        [4:0]  r_add, r_sum, g_sum, b_sum;
    logic        [3:0]  r_base, g_base, b_base;
    logic        [3:0]  red, green, blue;

    assign s8_mult = 32'(st3_s4) * 32'(st3_s4);
    assign s8_comb = 16'(s8_mult >>> 8);

    always_comb begin
        if (st3_spec_valid) begin
            specular = (s8_comb >= 16'sh0100) ? 4'd15 : s8_comb[7:4];
        end else begin
            specular = 4'd0;
        end

        diffuse = (st3_dot >= 16'sh0100) ? 4'd15 : ((st3_dot > 16'sh0000) ? st3_dot[7:4] : 4'd0);

        r_add  = 5'(AMBIENT) + 5'(diffuse);
        r_base = (r_add > 5'd15) ? 4'd15 : r_add[3:0];
        g_base = diffuse >> 2;
        b_base = 4'd0;

        r_sum = 5'(r_base) + 5'(specular);
        g_sum = 5'(g_base) + 5'(specular);
        b_sum = 5'(b_base) + 5'(specular);

        red   = (r_sum > 5'd15) ? 4'd15 : r_sum[3:0];
        green = (g_sum > 5'd15) ? 4'd15 : g_sum[3:0];
        blue  = (b_sum > 5'd15) ? 4'd15 : b_sum[3:0];

        shaded_output = {red, green, blue};
    end

endmodule
