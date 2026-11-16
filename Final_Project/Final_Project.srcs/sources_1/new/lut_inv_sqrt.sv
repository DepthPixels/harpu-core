`timescale 1ns / 1ps
// 64-entry Lookup Table for 1/sqrt(S) in unsigned Q0.16 format
// S range: S in [2.25, 5.03] (raw Q8.8 integer in [576, 1287])
// lut_addr = (S - 576) >> 4

module lut_inv_sqrt (
    input  logic        clka,
    input  logic [5:0]  addra,
    output logic [15:0] douta
);

    always_comb begin
        case (addra)
            6'd 0: douta = 16'hA97E; // S~2.281, 1/sqrt(S)~0.6621
            6'd 1: douta = 16'hA738; // S~2.344, 1/sqrt(S)~0.6532
            6'd 2: douta = 16'hA508; // S~2.406, 1/sqrt(S)~0.6447
            6'd 3: douta = 16'hA2EE; // S~2.469, 1/sqrt(S)~0.6364
            6'd 4: douta = 16'hA0E8; // S~2.531, 1/sqrt(S)~0.6285
            6'd 5: douta = 16'h9EF5; // S~2.594, 1/sqrt(S)~0.6209
            6'd 6: douta = 16'h9D13; // S~2.656, 1/sqrt(S)~0.6136
            6'd 7: douta = 16'h9B42; // S~2.719, 1/sqrt(S)~0.6065
            6'd 8: douta = 16'h9981; // S~2.781, 1/sqrt(S)~0.5996
            6'd 9: douta = 16'h97CF; // S~2.844, 1/sqrt(S)~0.5930
            6'd10: douta = 16'h962B; // S~2.906, 1/sqrt(S)~0.5866
            6'd11: douta = 16'h9494; // S~2.969, 1/sqrt(S)~0.5804
            6'd12: douta = 16'h930A; // S~3.031, 1/sqrt(S)~0.5744
            6'd13: douta = 16'h918C; // S~3.094, 1/sqrt(S)~0.5685
            6'd14: douta = 16'h9019; // S~3.156, 1/sqrt(S)~0.5629
            6'd15: douta = 16'h8EB1; // S~3.219, 1/sqrt(S)~0.5574
            6'd16: douta = 16'h8D53; // S~3.281, 1/sqrt(S)~0.5521
            6'd17: douta = 16'h8C00; // S~3.344, 1/sqrt(S)~0.5469
            6'd18: douta = 16'h8AB5; // S~3.406, 1/sqrt(S)~0.5418
            6'd19: douta = 16'h8974; // S~3.469, 1/sqrt(S)~0.5369
            6'd20: douta = 16'h883B; // S~3.531, 1/sqrt(S)~0.5322
            6'd21: douta = 16'h870B; // S~3.594, 1/sqrt(S)~0.5275
            6'd22: douta = 16'h85E2; // S~3.656, 1/sqrt(S)~0.5230
            6'd23: douta = 16'h84C1; // S~3.719, 1/sqrt(S)~0.5186
            6'd24: douta = 16'h83A7; // S~3.781, 1/sqrt(S)~0.5143
            6'd25: douta = 16'h8293; // S~3.844, 1/sqrt(S)~0.5101
            6'd26: douta = 16'h8187; // S~3.906, 1/sqrt(S)~0.5060
            6'd27: douta = 16'h8081; // S~3.969, 1/sqrt(S)~0.5020
            6'd28: douta = 16'h7F81; // S~4.031, 1/sqrt(S)~0.4981
            6'd29: douta = 16'h7E87; // S~4.094, 1/sqrt(S)~0.4942
            6'd30: douta = 16'h7D92; // S~4.156, 1/sqrt(S)~0.4905
            6'd31: douta = 16'h7CA3; // S~4.219, 1/sqrt(S)~0.4869
            6'd32: douta = 16'h7BB9; // S~4.281, 1/sqrt(S)~0.4833
            6'd33: douta = 16'h7AD5; // S~4.344, 1/sqrt(S)~0.4798
            6'd34: douta = 16'h79F5; // S~4.406, 1/sqrt(S)~0.4764
            6'd35: douta = 16'h791A; // S~4.469, 1/sqrt(S)~0.4730
            6'd36: douta = 16'h7843; // S~4.531, 1/sqrt(S)~0.4698
            6'd37: douta = 16'h7771; // S~4.594, 1/sqrt(S)~0.4666
            6'd38: douta = 16'h76A3; // S~4.656, 1/sqrt(S)~0.4634
            6'd39: douta = 16'h75D9; // S~4.719, 1/sqrt(S)~0.4603
            6'd40: douta = 16'h7514; // S~4.781, 1/sqrt(S)~0.4573
            6'd41: douta = 16'h7452; // S~4.844, 1/sqrt(S)~0.4544
            6'd42: douta = 16'h7393; // S~4.906, 1/sqrt(S)~0.4515
            6'd43: douta = 16'h72D9; // S~4.969, 1/sqrt(S)~0.4486
            6'd44: douta = 16'h7221; // S~5.031, 1/sqrt(S)~0.4458
            6'd45: douta = 16'h716E; // S~5.094, 1/sqrt(S)~0.4431
            6'd46: douta = 16'h70BD; // S~5.156, 1/sqrt(S)~0.4404
            6'd47: douta = 16'h7010; // S~5.219, 1/sqrt(S)~0.4377
            6'd48: douta = 16'h6F66; // S~5.281, 1/sqrt(S)~0.4351
            6'd49: douta = 16'h6EBE; // S~5.344, 1/sqrt(S)~0.4326
            6'd50: douta = 16'h6E1A; // S~5.406, 1/sqrt(S)~0.4301
            6'd51: douta = 16'h6D78; // S~5.469, 1/sqrt(S)~0.4276
            6'd52: douta = 16'h6CDA; // S~5.531, 1/sqrt(S)~0.4252
            6'd53: douta = 16'h6C3D; // S~5.594, 1/sqrt(S)~0.4228
            6'd54: douta = 16'h6BA4; // S~5.656, 1/sqrt(S)~0.4205
            6'd55: douta = 16'h6B0D; // S~5.719, 1/sqrt(S)~0.4182
            6'd56: douta = 16'h6A78; // S~5.781, 1/sqrt(S)~0.4159
            6'd57: douta = 16'h69E6; // S~5.844, 1/sqrt(S)~0.4137
            6'd58: douta = 16'h6956; // S~5.906, 1/sqrt(S)~0.4115
            6'd59: douta = 16'h68C9; // S~5.969, 1/sqrt(S)~0.4093
            6'd60: douta = 16'h683E; // S~6.031, 1/sqrt(S)~0.4072
            6'd61: douta = 16'h67B4; // S~6.094, 1/sqrt(S)~0.4051
            6'd62: douta = 16'h672D; // S~6.156, 1/sqrt(S)~0.4030
            6'd63: douta = 16'h66A8; // S~6.219, 1/sqrt(S)~0.4010
            default: douta = 16'h66A8;
        endcase
    end

endmodule
