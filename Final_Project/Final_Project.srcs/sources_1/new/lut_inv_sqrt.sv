`timescale 1ns / 1ps
// 64-entry Lookup Table for 1/sqrt(S) in unsigned Q0.16 format
// S range: S in [2.25, 5.03] (raw Q8.8 integer in [576, 1287])
// lut_addr = (S - 576) >> 4

module lut_inv_sqrt (
    input  logic        clka,
    input  logic [5:0]  addra,
    output logic [15:0] douta,
    output logic [15:0] douta_next
);

    localparam logic [15:0] LUT_DATA [0:63] = '{
        16'hA97E, 16'hA738, 16'hA508, 16'hA2EE, 16'hA0E8, 16'h9EF5, 16'h9D13, 16'h9B42,
        16'h9981, 16'h97CF, 16'h962B, 16'h9494, 16'h930A, 16'h918C, 16'h9019, 16'h8EB1,
        16'h8D53, 16'h8C00, 16'h8AB5, 16'h8974, 16'h883B, 16'h870B, 16'h85E2, 16'h84C1,
        16'h83A7, 16'h8293, 16'h8187, 16'h8081, 16'h7F81, 16'h7E87, 16'h7D92, 16'h7CA3,
        16'h7BB9, 16'h7AD5, 16'h79F5, 16'h791A, 16'h7843, 16'h7771, 16'h76A3, 16'h75D9,
        16'h7514, 16'h7452, 16'h7393, 16'h72D9, 16'h7221, 16'h716E, 16'h70BD, 16'h7010,
        16'h6F66, 16'h6EBE, 16'h6E1A, 16'h6D78, 16'h6CDA, 16'h6C3D, 16'h6BA4, 16'h6B0D,
        16'h6A78, 16'h69E6, 16'h6956, 16'h68C9, 16'h683E, 16'h67B4, 16'h672D, 16'h66A8
    };

    assign douta      = LUT_DATA[addra];
    assign douta_next = (addra == 6'd63) ? LUT_DATA[63] : LUT_DATA[addra + 6'd1];

endmodule
