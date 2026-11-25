`timescale 1ns / 1ps

module sphere_shader (
    input  logic               clk,
    input  logic               reset,
    input  logic signed [15:0] norm_x,
    input  logic signed [15:0] norm_y,
    input  logic signed [15:0] norm_z,
    input  logic signed [15:0] light_dir_x,
    input  logic signed [15:0] light_dir_y,
    input  logic signed [15:0] light_dir_z,
    input  logic signed [15:0] half_x,
    input  logic signed [15:0] half_y,
    input  logic signed [15:0] half_z,
    input  logic        [1:0]  sphere_material,
    input  logic        [8:0]  ao_in,
    output logic        [23:0] shaded_output
);

    /*
    // Direction to light source: [0.5, 0.6, -0.625] normalized in Q8.8
    localparam logic signed [15:0] LIGHT_DIR_X = 16'sh0080;
    localparam logic signed [15:0] LIGHT_DIR_Y = 16'sh0099;
    localparam logic signed [15:0] LIGHT_DIR_Z = 16'shFF60;

    // Blinn-Phong Half-vector: (L + V) / |L + V| with V = [0, 0, -1]
    localparam logic signed [15:0] HALF_X = 16'sh0047; // +0.277
    localparam logic signed [15:0] HALF_Y = 16'sh0055; // +0.333
    localparam logic signed [15:0] HALF_Z = 16'shFF19; // -0.901
    */


    //
    // Stage 1A
    // Component Multiplications in Parallel (6 independent un-cascaded DSPs)
    //

    logic signed [31:0] p_lx, p_ly, p_lz;
    logic signed [31:0] p_hx, p_hy, p_hz;

    logic [8:0] st0_ao;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            p_lx <= 32'sd0;
            p_ly <= 32'sd0;
            p_lz <= 32'sd0;
            p_hx <= 32'sd0;
            p_hy <= 32'sd0;
            p_hz <= 32'sd0;
            st0_ao <= 9'd0;
        end else begin
            p_lx <= 32'(norm_x) * 32'(light_dir_x);
            p_ly <= 32'(norm_y) * 32'(light_dir_y);
            p_lz <= 32'(norm_z) * 32'(light_dir_z);
            p_hx <= 32'(norm_x) * 32'(half_x);
            p_hy <= 32'(norm_y) * 32'(half_y);
            p_hz <= 32'(norm_z) * 32'(half_z);
            st0_ao <= ao_in;
        end
    end

    //
    // Stage 1B
    // Fast Adder Tree Sum and Clamping into Stage 1 Registers
    //

    logic signed [31:0] dp_sum;
    logic signed [31:0] hdp_sum;
    logic signed [15:0] dp_comb;
    logic signed [15:0] hdp_comb;

    assign dp_sum  = p_lx + p_ly + p_lz;
    assign hdp_sum = p_hx + p_hy + p_hz;

    assign dp_comb  = 16'(dp_sum >>> 8);
    // Q2.14
    assign hdp_comb = 16'(hdp_sum >>> 2);

    logic signed [15:0] st1_dot;
    logic signed [15:0] st1_half;
    logic               st1_spec_valid;
    logic        [8:0]  st1_ao;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st1_dot        <= 16'sh0000;
            st1_half       <= 16'sh0000;
            st1_spec_valid <= 1'b0;
            st1_ao         <= 9'd0;
        end else begin
            st1_dot        <= dp_comb;
            st1_half       <= (hdp_comb[15] == 1'b0) ? hdp_comb : 16'sh0000;
            st1_spec_valid <= (dp_comb > 16'sh0000) && (hdp_comb[15] == 1'b0);
            st1_ao         <= st0_ao;
        end
    end

    //
    // Stage 2
    // Specular S2 = S1^2
    //

    logic signed [31:0] s2_mult;
    logic signed [15:0] s2_comb;

    // Q4.28
    assign s2_mult = 32'(st1_half) * 32'(st1_half);
    assign s2_comb = 16'(s2_mult >>> 14);

    logic signed [15:0] st2_dot;
    logic signed [15:0] st2_s2;
    logic               st2_spec_valid;
    logic        [8:0]  st2_ao;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st2_dot        <= 16'sh0000;
            st2_s2         <= 16'sh0000;
            st2_spec_valid <= 1'b0;
            st2_ao         <= 9'd0;
        end else begin
            st2_dot        <= st1_dot;
            st2_s2         <= st1_spec_valid ? s2_comb : 16'sh0000;
            st2_spec_valid <= st1_spec_valid;
            st2_ao         <= st1_ao;
        end
    end

    //
    // Stage 3
    // Specular S4 = S2^2
    //
    logic signed [31:0] s4_mult;
    logic signed [15:0] s4_comb;
    // Q4.28
    assign s4_mult = 32'(st2_s2) * 32'(st2_s2);
    assign s4_comb = 16'(s4_mult >>> 14);

    logic signed [15:0] st3_dot;
    logic signed [15:0] st3_s4;
    logic               st3_spec_valid;
    logic        [8:0]  st3_ao;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st3_dot        <= 16'sh0000;
            st3_s4         <= 16'sh0000;
            st3_spec_valid <= 1'b0;
            st3_ao         <= 9'd0;
        end else begin
            st3_dot        <= st2_dot;
            st3_s4         <= st2_spec_valid ? s4_comb : 16'sh0000;
            st3_spec_valid <= st2_spec_valid;
            st3_ao         <= st2_ao;
        end
    end

    //
    // Stage 4
    // Specular S8 = S4^2 (Registered to decouple DSP from RGB pack)
    //

    logic signed [31:0] s8_mult;
    logic signed [15:0] s8_comb;
    logic signed [15:0] st4_dot;
    logic signed [15:0] st4_s8;
    logic               st4_spec_valid;
    logic        [8:0]  st4_ao;

    // Q4.28
    assign s8_mult = 32'(st3_s4) * 32'(st3_s4);
    assign s8_comb = 16'(s8_mult >>> 20);

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            st4_dot        <= 16'sh0000;
            st4_s8         <= 16'sh0000;
            st4_spec_valid <= 1'b0;
            st4_ao         <= 9'd0;
        end else begin
            st4_dot        <= st3_dot;
            st4_s8         <= st3_spec_valid ? s8_comb : 16'sh0000;
            st4_spec_valid <= st3_spec_valid;
            st4_ao         <= st3_ao;
        end
    end

    //
    // Stage 5
    // Diffuse, Ambient, Specular Clamping & 24-bit RGB Pack
    //

    logic        [7:0]  specular;
    logic        [7:0]  diffuse;
    logic        [8:0]  r_add, g_add, b_add, r_sum, g_sum, b_sum;
    logic        [7:0]  r_base, g_base, b_base;
    logic        [7:0]  red, green, blue;

    localparam logic [7:0] AMBIENT_24 = 8'd48; // Ambient base in 8-bit

    always_comb begin
        if (st4_spec_valid) begin
            specular = (st4_s8 >= 16'sh0100) ? 8'd255 : ((st4_s8 > 16'sh0000) ? st4_s8[7:0] : 8'd0);
        end else begin
            specular = 8'd0;
        end

        diffuse = (st4_dot >= 16'sh0100) ? 8'd255 : ((st4_dot > 16'sh0000) ? st4_dot[7:0] : 8'd0);

        r_add = 9'b0;
        g_add = 9'b0;
        b_add = 9'b0;

        case (sphere_material)
            2'b00: begin
                // Orange / Terracotta
                r_add  = 9'(AMBIENT_24) + 9'(diffuse);
                r_base = (r_add > 9'd255) ? 8'd255 : r_add[7:0];
                g_base = diffuse >> 2;
                b_base = 8'd0;
            end
            2'b01: begin
                // Green / Emerald Jade
                r_base = diffuse >> 3;
                g_add  = 9'd32 + 9'(diffuse);
                g_base = (g_add > 9'd255) ? 8'd255 : g_add[7:0];
                b_add  = 9'd16 + 9'(diffuse >> 1);
                b_base = (b_add > 9'd255) ? 8'd255 : b_add[7:0];
            end
            2'b10: begin
                // Blue / Cobalt
                r_add  = 9'd16 + 9'(diffuse >> 2);
                r_base = (r_add > 9'd255) ? 8'd255 : r_add[7:0];
                g_base = diffuse >> 1;
                b_add  = 9'(AMBIENT_24) + 9'(diffuse);
                b_base = (b_add > 9'd255) ? 8'd255 : b_add[7:0];
            end
            2'b11: begin
                // Purple / Amethyst
                r_add  = 9'd16 + 9'(diffuse);
                r_base = (r_add > 9'd255) ? 8'd255 : r_add[7:0];
                g_base = 8'd0;
                b_add  = 9'd32 + 9'(diffuse);
                b_base = (b_add > 9'd255) ? 8'd255 : b_add[7:0];
            end
            default: begin
                r_base = 8'd0;
                g_base = 8'd0;
                b_base = 8'd0;
            end
        endcase

        r_sum = 9'((17'(r_base) * 17'(st4_ao)) >> 8) + 9'(specular);
        g_sum = 9'((17'(g_base) * 17'(st4_ao)) >> 8) + 9'(specular);
        b_sum = 9'((17'(b_base) * 17'(st4_ao)) >> 8) + 9'(specular);

        red   = (r_sum > 9'd255) ? 8'd255 : r_sum[7:0];
        green = (g_sum > 9'd255) ? 8'd255 : g_sum[7:0];
        blue  = (b_sum > 9'd255) ? 8'd255 : b_sum[7:0];

        shaded_output = {red, green, blue};
    end

endmodule
