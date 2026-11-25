`timescale 1ns / 1ps

module sim_top (
    input  logic        clk,
    input  logic        reset,
    input  logic [63:0] usb_data,

    output logic [16:0] fb_addr,
    output logic [23:0] fb_din,
    output logic        fb_we,
    output logic        frame_done,

    output logic signed [15:0] carve_x,
    output logic signed [15:0] carve_y,
    output logic signed [15:0] carve_z,
    output logic signed [15:0] carve_radius,
    output logic               carve_en,
    output logic        [1:0]  sphere_material,
    output logic        [1:0]  control_mode
);

    logic signed [15:0] light_dir_x, light_dir_y, light_dir_z;
    logic signed [15:0] half_x, half_y, half_z;
    logic signed [15:0] inv_carve_radius;

    carve_controller carve_ctrl_inst (
        .clk(clk),
        .reset(reset),
        .frame_tick(frame_done),
        .usb_data_in(usb_data),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .light_dir_x(light_dir_x),
        .light_dir_y(light_dir_y),
        .light_dir_z(light_dir_z),
        .half_x(half_x),
        .half_y(half_y),
        .half_z(half_z),
        .carve_radius(carve_radius),
        .inv_carve_radius(inv_carve_radius),
        .carve_en(carve_en),
        .sphere_material(sphere_material),
        .control_mode(control_mode)
    );

    raymarch_core raymarch_inst (
        .clk(clk),
        .reset(reset),
        .carve_en(carve_en),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .light_dir_x(light_dir_x),
        .light_dir_y(light_dir_y),
        .light_dir_z(light_dir_z),
        .half_x(half_x),
        .half_y(half_y),
        .half_z(half_z),
        .carve_radius(carve_radius),
        .sphere_material(sphere_material),
        .fb_addr(fb_addr),
        .fb_din(fb_din),
        .fb_we(fb_we),
        .frame_done(frame_done)
    );

endmodule
