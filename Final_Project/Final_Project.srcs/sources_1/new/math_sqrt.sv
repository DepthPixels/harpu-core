module fixed_point_sqrt_q8_8 (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        in_valid,
    input  logic [15:0] radicand,
    input  logic [3:0]  tag_in,
    output logic [15:0] root,
    output logic        out_valid,
    output logic [3:0]  tag_out
);

    // Zero-pad Q8.8 to Q8.16 (24 bits) so sqrt yields Q4.8 (12 bits)
    logic [23:0] radicand_ext;
    assign radicand_ext = {radicand, 8'd0};

    // Pipeline registers for stages 0 through 11 (12 stages total)
    logic               valid_pipe [0:11];
    logic signed [25:0] rem_pipe   [0:11]; // 26-bit signed remainder
    logic [23:0]        x_pipe     [0:11];
    logic [11:0]        q_pipe     [0:11]; // 12-bit Q4.8 internal root
    logic [3:0]         tag_pipe   [0:11];

    // Combinational next-stage signals
    logic signed [25:0] rem_shifted [0:11];
    logic signed [25:0] test_val    [0:11];
    logic signed [25:0] rem_next    [0:11];
    logic [11:0]        q_next      [0:11];

    always_comb begin
        // Stage 0: Initial step
        rem_shifted[0] = {24'd0, radicand_ext[23:22]};
        test_val[0]    = 26'sd1; // {12'd0, 12'd0, 2'b01}
        rem_next[0]    = rem_shifted[0] - test_val[0];
        q_next[0]      = {11'd0, ~rem_next[0][25]};

        // Stages 1 to 11: Iterative non-restoring steps
        for (int i = 1; i < 12; i++) begin
            rem_shifted[i] = {rem_pipe[i-1][23:0], x_pipe[i-1][23:22]};

            // Check sign bit [25] of previous remainder
            if (rem_pipe[i-1][25]) begin
                test_val[i] = signed'({12'd0, q_pipe[i-1], 2'b11});
                rem_next[i] = rem_shifted[i] + test_val[i];
            end else begin
                test_val[i] = signed'({12'd0, q_pipe[i-1], 2'b01});
                rem_next[i] = rem_shifted[i] - test_val[i];
            end

            q_next[i] = {q_pipe[i-1][10:0], ~rem_next[i][25]};
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < 12; i++) begin
                valid_pipe[i] <= 1'b0;
                tag_pipe[i]   <= 4'b0;
                rem_pipe[i]   <= 26'sd0;
                x_pipe[i]     <= 24'd0;
                q_pipe[i]     <= 12'd0;
            end
        end else begin
            // Stage 0 register update
            valid_pipe[0] <= in_valid;
            tag_pipe[0]   <= tag_in;
            rem_pipe[0]   <= rem_next[0];
            x_pipe[0]     <= {radicand_ext[21:0], 2'b00};
            q_pipe[0]     <= q_next[0];

            // Stages 1 to 11 register updates
            for (int i = 1; i < 12; i++) begin
                valid_pipe[i] <= valid_pipe[i-1];
                tag_pipe[i]   <= tag_pipe[i-1];
                rem_pipe[i]   <= rem_next[i];
                x_pipe[i]     <= {x_pipe[i-1][21:0], 2'b00};
                q_pipe[i]     <= q_next[i];
            end
        end
    end

    // Zero-extend 12-bit Q4.8 result to 16-bit Q8.8 output
    assign root      = {4'd0, q_pipe[11]};
    assign out_valid = valid_pipe[11];
    assign tag_out   = tag_pipe[11];

endmodule
