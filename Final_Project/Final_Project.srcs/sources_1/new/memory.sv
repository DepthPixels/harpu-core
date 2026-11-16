`timescale 1ns / 1ps

module framebuffer_memory (
    // Port A: Write Port (Compute / Raymarcher / Test Writer Clock)
    input  logic        clka,
    input  logic        ena_a,
    input  logic        wea_a,
    input  logic [16:0] address_a,
    input  logic [11:0] din_a,

    // Port B: Read Port (Video Scanout Clock, 25 MHz)
    input  logic        clkb,
    input  logic        ena_b,
    input  logic [16:0] address_b,
    output logic [11:0] dout_b
);

    blk_mem_framebuffer sram0 (
        .clka   (clka),
        .ena    (ena_a),
        .wea    (wea_a),
        .addra  (address_a),
        .dina   (din_a),
        
        .clkb   (clkb),
        .enb    (ena_b),
        .addrb  (address_b),
        .doutb  (dout_b)
    );

endmodule
