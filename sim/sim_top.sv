`timescale 1ns / 1ps

module sim_top (
    input  logic        clk,
    input  logic        reset,
    input  logic [7:0]  keycode,

    output logic [16:0] fb_addr,
    output logic [11:0] fb_din,
    output logic        fb_we,
    output logic        frame_done,

    output logic signed [15:0] carve_x,
    output logic signed [15:0] carve_y,
    output logic signed [15:0] carve_z,
    output logic signed [15:0] carve_radius,
    output logic               carve_en
);

    logic signed [15:0] inv_carve_radius;

    carve_controller carve_ctrl_inst (
        .clk(clk),
        .reset(reset),
        .frame_tick(frame_done),
        .keycode(keycode),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .carve_radius(carve_radius),
        .inv_carve_radius(inv_carve_radius),
        .carve_en(carve_en)
    );

    raymarch_core raymarch_inst (
        .clk(clk),
        .reset(reset),
        .drawX(10'd0),
        .drawY(10'd0),
        .carve_en(carve_en),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .carve_radius(carve_radius),
        .inv_carve_radius(inv_carve_radius),
        .fb_addr(fb_addr),
        .fb_din(fb_din),
        .fb_we(fb_we),
        .frame_done(frame_done)
    );

endmodule
