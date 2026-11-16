`timescale 1ns / 1ps

module ray_gen (
    input  logic clk,
    input  logic reset, // Async high reset

    input  logic [9:0]  drawX,
    input  logic [9:0]  drawY,
    input  logic        in_valid,

    output logic signed [15:0] ray_dir_x,
    output logic signed [15:0] ray_dir_y,
    output logic signed [15:0] ray_dir_z,
    output logic               ray_valid
);

    // Stage 1 of Pipeline: Raster to Screen Space

    // Q8.8 Screen Space Coords
    logic signed [15:0] u_val, v_val;
    logic signed [15:0] diff_x, diff_y;
    logic signed [15:0] r1_u, r1_v;

    logic        r1_valid;

    always_comb begin: UV_CONVERT
        diff_x = $signed({6'd0, drawX}) - 16'd160;
        diff_y = 16'd120 - $signed({6'd0, drawY});

        u_val = 16'((32'(diff_x) * 32'(16'sh0222)) >>> 8);
        v_val = 16'((32'(diff_y) * 32'(16'sh0222)) >>> 8);
    end

    always_ff @(posedge clk or posedge reset) begin: UV_REGS
        if (reset) begin
            r1_u <= 16'd0;
            r1_v <= 16'd0;
            r1_valid <= 1'd0;
        end
        else begin
            r1_u <= u_val;
            r1_v <= v_val;
            r1_valid <= in_valid;
        end
    end

    // Stage 2 of Pipeline: Camera Rotation and Direction Vector

    // Q8.8 Direction components left static for now
    logic signed [15:0] dx, dy, dz;
    logic signed [15:0] r2_dx, r2_dy, r2_dz;

    logic        r2_valid;

    always_comb begin: DIRECTION_SET
        dx = r1_u;
        dy = r1_v;
        dz = 16'sh0180;
    end

    always_ff @(posedge clk or posedge reset) begin: DIRECTION_REGS
        if (reset) begin
            r2_dx <= 16'd0;
            r2_dy <= 16'd0;
            r2_dz <= 16'd0;
            r2_valid <= 1'd0;
        end
        else begin
            r2_dx <= dx;
            r2_dy <= dy;
            r2_dz <= dz;
            r2_valid <= r1_valid;
        end
    end

    // Stage 3 of pipeline: Squared Vector Magnitude

    // Vector mags
    logic signed [15:0] sq_x, sq_y, sq_z;
    logic signed [15:0] S;
    logic signed [15:0] r3_dx, r3_dy, r3_dz;
    logic signed [15:0] r3_S;

    logic        r3_valid;

    always_comb begin: SQUARE_VECTORS
        sq_x = 16'((32'(r2_dx) * 32'(r2_dx)) >>> 8);
        sq_y = 16'((32'(r2_dy) * 32'(r2_dy)) >>> 8);
        sq_z = 16'((32'(r2_dz) * 32'(r2_dz)) >>> 8);
        S = sq_x + sq_y + sq_z;
    end

    always_ff @(posedge clk or posedge reset) begin: SQUARED_VECTORS_REGS
        if (reset) begin
            r3_dx <= 16'd0;
            r3_dy <= 16'd0;
            r3_dz <= 16'd0;
            r3_S <= 16'd0;
            r3_valid <= 1'd0;
        end
        else begin
            r3_dx <= r2_dx;
            r3_dy <= r2_dy;
            r3_dz <= r2_dz;
            r3_S <= S;
            r3_valid <= r2_valid;
        end
    end

    // Stage 4 of pipeline: Vector Magnitude

    // Lookup table output unsigned Q0.16
    logic [15:0] lut_out;
    logic [5:0]  lut_addr;
    logic signed [15:0] r4_dx, r4_dy, r4_dz;
    logic [15:0] r4_inv_norm;

    logic        r4_valid;

    always_comb begin: INVERSE_SQRT_CALC
        lut_addr = (r3_S - 16'd576) >> 4;
    end

    lut_inv_sqrt inv_sqrt_lut (
        .clka(clk),
        .addra(lut_addr),
        .douta(lut_out)
    );

    always_ff @(posedge clk or posedge reset) begin: INVERSE_SQRT_REGS
        if (reset) begin
            r4_dx <= 16'd0;
            r4_dy <= 16'd0;
            r4_dz <= 16'd0;
            r4_inv_norm <= 16'd0;
            r4_valid <= 1'd0;
        end
        else begin
            r4_dx <= r3_dx;
            r4_dy <= r3_dy;
            r4_dz <= r3_dz;
            r4_inv_norm <= lut_out;
            r4_valid <= r3_valid;
        end
    end

    // Stage 5 of pipeline: Normalized Direction Vector

    logic signed [15:0] d_hat_x, d_hat_y, d_hat_z;

    always_comb begin: NORMALIZE_DIRECTION
        d_hat_x = 16'((32'(r4_dx) * 32'($signed({1'b0, r4_inv_norm}))) >>> 16);
        d_hat_y = 16'((32'(r4_dy) * 32'($signed({1'b0, r4_inv_norm}))) >>> 16);
        d_hat_z = 16'((32'(r4_dz) * 32'($signed({1'b0, r4_inv_norm}))) >>> 16);
    end

    always_ff @(posedge clk or posedge reset) begin: NORMALIZED_DIRECTION_REGS
        if (reset) begin
            ray_dir_x <= 16'd0;
            ray_dir_y <= 16'd0;
            ray_dir_z <= 16'd0;
            ray_valid <= 1'd0;
        end
        else begin
            ray_dir_x <= d_hat_x;
            ray_dir_y <= d_hat_y;
            ray_dir_z <= d_hat_z;
            ray_valid <= r4_valid;
        end
    end

endmodule