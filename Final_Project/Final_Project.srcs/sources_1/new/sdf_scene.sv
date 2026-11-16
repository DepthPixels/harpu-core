`timescale 1ns / 1ps

module sdf_scene(
    input  logic clk,
    input  logic reset, // Async high reset

    input  logic signed [15:0] pos_x,
    input  logic signed [15:0] pos_y,
    input  logic signed [15:0] pos_z,
    input  logic               in_valid,

    input  logic               carve_en,
    input  logic signed [15:0] carve_x,
    input  logic signed [15:0] carve_y,
    input  logic signed [15:0] carve_z,
    input  logic signed [15:0] carve_radius,

    output logic signed [15:0] dist_out,
    output logic               out_valid,
    output logic               hit_carve,
    output logic        [8:0]  blend_w
);

    // Represents a 1 radius sphere at (0, 0, 0)
    logic signed [15:0] center_x = 16'sh0000;
    logic signed [15:0] center_y = 16'sh0000;
    logic signed [15:0] center_z = 16'sh0000;
    logic signed [15:0] radius = 16'sh0100;

    logic signed [15:0] diff_x, diff_y, diff_z;
    logic signed [15:0] sq_x, sq_y, sq_z;
    logic signed [15:0] sq_D;
    logic signed [15:0] sqrt_sq_D;
    logic signed [15:0] dist_sphere;
    logic               out_valid_sphere;

    logic signed [15:0] carve_diff_x, carve_diff_y, carve_diff_z;
    logic signed [15:0] carve_sq_x, carve_sq_y, carve_sq_z;
    logic signed [15:0] carve_sq_D;
    logic signed [15:0] carve_sqrt_sq_D;
    logic signed [15:0] dist_carve;
    logic               out_valid_carve;

    logic signed [15:0] d_diff;
    assign d_diff = (-dist_carve) - dist_sphere;

    assign hit_carve = (-dist_carve >= dist_sphere) && carve_en;

    always_comb begin
        if (!carve_en || d_diff <= -16'sh0010) begin
            blend_w = 9'd0;    // Pure sphere
        end else if (d_diff >= 16'sh0030) begin
            blend_w = 9'd256;  // Pure crater
        end else begin
            blend_w = 9'((32'(d_diff + 16'sh0010)) << 2);
        end
    end

    always_comb begin: SDF_SPHERE
        diff_x = pos_x - center_x;
        diff_y = pos_y - center_y;
        diff_z = pos_z - center_z;

        sq_x = 16'((32'(diff_x) * 32'(diff_x)) >>> 8);
        sq_y = 16'((32'(diff_y) * 32'(diff_y)) >>> 8);
        sq_z = 16'((32'(diff_z) * 32'(diff_z)) >>> 8);

        sq_D = sq_x + sq_y + sq_z;

        dist_sphere = sqrt_sq_D - radius;

        carve_diff_x = pos_x - carve_x;
        carve_diff_y = pos_y - carve_y;
        carve_diff_z = pos_z - carve_z;

        carve_sq_x = 16'((32'(carve_diff_x) * 32'(carve_diff_x)) >>> 8);
        carve_sq_y = 16'((32'(carve_diff_y) * 32'(carve_diff_y)) >>> 8);
        carve_sq_z = 16'((32'(carve_diff_z) * 32'(carve_diff_z)) >>> 8);

        carve_sq_D = carve_sq_x + carve_sq_y + carve_sq_z;

        dist_carve = carve_sqrt_sq_D - carve_radius;

        if (carve_en) begin
            dist_out = (dist_sphere > -dist_carve) ? dist_sphere : -dist_carve;
        end
        else begin
            dist_out = dist_sphere;
        end

        out_valid = out_valid_sphere;
    end

    // Square Root Module
    fixed_point_sqrt_q8_8 sqrt_inst (
        .clk(clk),
        .rst_n(!reset),
        .in_valid(in_valid),
        .radicand(sq_D),
        .root(sqrt_sq_D),
        .out_valid(out_valid_sphere)
    );

    fixed_point_sqrt_q8_8 carve_sqrt_inst (
        .clk(clk),
        .rst_n(!reset),
        .in_valid(in_valid && carve_en),
        .radicand(carve_sq_D),
        .root(carve_sqrt_sq_D),
        .out_valid(out_valid_carve)
    );

endmodule
