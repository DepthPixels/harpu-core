`timescale 1ns / 1ps

module vec3_normalize(
    input  logic               clk,
    input  logic               reset,
    input  logic signed [15:0] nx_in,
    input  logic signed [15:0] ny_in,
    input  logic signed [15:0] nz_in,
    input  logic        [3:0]  tag_in,
    input  logic               valid,

    output logic signed [15:0] norm_x,
    output logic signed [15:0] norm_y,
    output logic signed [15:0] norm_z,
    output logic        [3:0]  tag_out,
    output logic               out_valid
);

    // Pipeline regs
    logic signed [15:0] nx_pipe [3];
    logic signed [15:0] ny_pipe [3];
    logic signed [15:0] nz_pipe [3];
    logic        [3:0]  tag_pipe [3];
    logic               valid_pipe [3];

    logic [31:0] S;

    // Stage 1 -> Square and Sum

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 3; i++) begin
                nx_pipe[i] <= 0;
                ny_pipe[i] <= 0;
                nz_pipe[i] <= 0;
                tag_pipe[i] <= 0;
                valid_pipe[i] <= 0;
                S <= 0;
            end
        end
        else begin
            if (valid_pipe[0]) begin
                S <= $unsigned((32'($signed(nx_pipe[0])) * 32'($signed(nx_pipe[0]))) + (32'($signed(ny_pipe[0])) * 32'($signed(ny_pipe[0]))) + (32'($signed(nz_pipe[0])) * 32'($signed(nz_pipe[0]))));
            end else begin
                S <= 32'b0;
            end

            for (int i = 0; i < 3; i++) begin
                if (i == 0) begin
                    nx_pipe[i] <= nx_in;
                    ny_pipe[i] <= ny_in;
                    nz_pipe[i] <= nz_in;
                    tag_pipe[i] <= tag_in;
                    valid_pipe[i] <= valid;
                end
                else begin
                    nx_pipe[i] <= nx_pipe[i-1];
                    ny_pipe[i] <= ny_pipe[i-1];
                    nz_pipe[i] <= nz_pipe[i-1];
                    tag_pipe[i] <= tag_pipe[i-1];
                    valid_pipe[i] <= valid_pipe[i-1];
                end
            end
        end
    end

    // Stage 2 -> Find Shift and use inverse Square Root
    logic [4:0] msb;
    logic [3:0] even_shift_comb;
    logic [3:0] s2_even_shift;
    logic [7:0] m; // Intermediate in Q2.6
    logic [15:0] inv_m_comb; // Q0.16 inverse sqrt
    logic [15:0] s2_inv_m; // Q0.16 inverse sqrt
    logic bypass; // Bypass for zero vector

    // Q0.16 Inverse Rom: round(65536 / sqrt((idx + 0.5) / 16.0)) for idx in [16..63]
    localparam logic [15:0] inv_sqrt_rom [64] = '{
        16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF,
        16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF, 16'hFFFF,
        16'hFC17, 16'hF4C8, 16'hEE13, 16'hE7E4, 16'hE22A, 16'hDCD7, 16'hD7E1, 16'hD33C,
        16'hCEE1, 16'hCAC8, 16'hC6EB, 16'hC345, 16'hBFD0, 16'hBC89, 16'hB96B, 16'hB673,
        16'hB39F, 16'hB0EC, 16'hAE56, 16'hABDD, 16'hA97E, 16'hA738, 16'hA508, 16'hA2EE,
        16'hA0E8, 16'h9EF5, 16'h9D13, 16'h9B42, 16'h9981, 16'h97CF, 16'h962B, 16'h9494,
        16'h930A, 16'h918C, 16'h9019, 16'h8EB1, 16'h8D53, 16'h8C00, 16'h8AB5, 16'h8974,
        16'h883B, 16'h870B, 16'h85E2, 16'h84C1, 16'h83A7, 16'h8293, 16'h8187, 16'h8081
    };

    always_comb begin
        msb = 5'b0;
        for (int unsigned i = 0; i < 32; i++) begin
            if (S[i] == 1'b1) begin
                msb = 5'(i);
            end
        end
        even_shift_comb = msb[4:1];
        if (even_shift_comb >= 4'd3) begin
            m = 8'(S >> ({even_shift_comb, 1'b0} - 6));
        end else begin
            m = 8'(S << (6 - {even_shift_comb, 1'b0}));
        end
        inv_m_comb = inv_sqrt_rom[m[7:2]];
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            bypass <= 1'b0;
            s2_even_shift <= 4'b0;
            s2_inv_m <= 16'b0;
        end
        else begin
            s2_even_shift <= even_shift_comb;
            s2_inv_m <= inv_m_comb;
            bypass <= (S == 32'b0);
        end
    end

    // Stage 3 -> Normalize

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            norm_x <= 0;
            norm_y <= 0;
            norm_z <= 0;
            tag_out <= 0;
            out_valid <= 0;
        end
        else begin
            norm_x <= (valid_pipe[2] && !bypass) ? 16'((32'($signed(nx_pipe[2])) * $signed({16'b0, s2_inv_m})) >>> (s2_even_shift + 8)) : 16'sh0000;
            norm_y <= (valid_pipe[2] && !bypass) ? 16'((32'($signed(ny_pipe[2])) * $signed({16'b0, s2_inv_m})) >>> (s2_even_shift + 8)) : 16'sh0000;
            norm_z <= (valid_pipe[2]) ? (bypass) ? -16'sd256 : 16'((32'($signed(nz_pipe[2])) * $signed({16'b0, s2_inv_m})) >>> (s2_even_shift + 8)) : 16'sh0000;
            tag_out <= tag_pipe[2];
            out_valid <= valid_pipe[2];
        end
    end
endmodule
