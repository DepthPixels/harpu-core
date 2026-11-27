`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/24/2026 07:56:23 PM
// Design Name: 
// Module Name: hex_to_bcd
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

//This converts hex to bcd using double dabbling - primarily used for the FPS counter.
module hex_to_bcd #(
    parameter int WIDTH = 8,
    parameter int DIGITS = 3
)(
    
    input  logic [WIDTH-1:0] value,
    output logic [DIGITS*4-1:0] decim

    );
    
    
    logic [WIDTH-1:0] b;
    logic [DIGITS*4-1:0] accum;
    
    always_comb begin
        b = value;
        accum = '0;
        for (int i=0; i<WIDTH; i++) begin
            for (int j=0; j<DIGITS; j++)
                if (accum[4*j +: 4] >= 4'd5)
                    accum[4*j +: 4] = accum[4*j +: 4] + 4'd3;
                    
        accum = {accum[DIGITS*4-2:0],b[WIDTH-1]};
        b = { b[WIDTH-2:0], 1'b0};   
            end
        end
        assign decim = accum;
    
endmodule





