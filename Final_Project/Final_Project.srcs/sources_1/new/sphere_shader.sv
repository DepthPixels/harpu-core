`timescale 1ns / 1ps

module sphere_shader (
    input  logic signed [15:0] norm_x,
    input  logic signed [15:0] norm_y,
    input  logic signed [15:0] norm_z,
    output logic        [11:0] shaded_output
);

    logic signed [15:0] light_dir_x = 16'sh0080;
    logic signed [15:0] light_dir_y = 16'sh0099;
    logic signed [15:0] light_dir_z = 16'shFF60;

    logic signed [15:0] half_x = 16'sh0047; // +0.277
    logic signed [15:0] half_y = 16'sh0055; // +0.333
    logic signed [15:0] half_z = 16'shFF19; // -0.901

    logic signed [15:0] dot_product;
    logic signed [15:0] half_dot_product;
    logic signed [15:0] s1, s2, s4, s8;

    logic        [3:0]  diffuse;
    logic        [3:0]  intensity;
    logic        [3:0]  ambient = 4'd1;
    logic        [3:0]  specular;

    logic        [3:0]  r_base, g_base, b_base;
    logic        [4:0]  r_sum, g_sum, b_sum;
    logic        [3:0]  red, green, blue;

    always_comb begin
        dot_product = 16'((32'(norm_x)*32'(light_dir_x) + 32'(norm_y)*32'(light_dir_y) + 32'(norm_z)*32'(light_dir_z)) >>> 8);
        half_dot_product = 16'((32'(norm_x)*32'(half_x) + 32'(norm_y)*32'(half_y) + 32'(norm_z)*32'(half_z)) >>> 8);

        // Specular Stuff
        if (half_dot_product[15] == 0) begin
            s1 = half_dot_product;
            s2 = 16'((32'(s1) * 32'(s1)) >>> 8);
            s4 = 16'((32'(s2) * 32'(s2)) >>> 8);
            s8 = 16'((32'(s4) * 32'(s4)) >>> 8);
        end
        else begin
            s1 = 16'sh0000;
            s2 = 16'sh0000;
            s4 = 16'sh0000;
            s8 = 16'sh0000;
        end
        specular = (s8 >= 16'sh0100) ? 4'd15 : s8[7:4];

        diffuse = (dot_product >= 16'sh0100) ? 4'd15 : ((dot_product > 0) ? dot_product[7:4] : 4'd0);
        intensity = ambient + (((diffuse << 3) + (diffuse << 2)) >> 4);

        r_base = (diffuse == 4'd15) ? 4'd15 : (ambient + diffuse);
        g_base = diffuse >> 2;
        b_base = 4'd0;

        r_sum = 5'(r_base) + 5'(specular);
        g_sum = 5'(g_base) + 5'(specular);
        b_sum = 5'(b_base) + 5'(specular);

        red   = (r_sum > 5'd15) ? 4'd15 : r_sum[3:0];
        green = (g_sum > 5'd15) ? 4'd15 : g_sum[3:0];
        blue  = (b_sum > 5'd15) ? 4'd15 : b_sum[3:0];
        shaded_output = {red, green, blue};
    end
endmodule
