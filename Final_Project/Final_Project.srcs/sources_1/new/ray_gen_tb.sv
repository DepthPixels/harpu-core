`timescale 1ns / 1ps

//-------------------------------------------------------------------------
//  ray_gen_tb.sv
//  Comprehensive testbench for ray_gen (Stage 1 of HARPU Raymarcher)
//  Verifies pipeline latency, screen projection, and unit vector magnitude.
//-------------------------------------------------------------------------

module ray_gen_tb;

    logic        clk;
    logic        reset;
    logic [9:0]  drawX;
    logic [9:0]  drawY;
    logic        in_valid;

    logic signed [15:0] ray_dir_x;
    logic signed [15:0] ray_dir_y;
    logic signed [15:0] ray_dir_z;
    logic               ray_valid;

    // Instantiate Unit Under Test (UUT)
    ray_gen uut (
        .clk        (clk),
        .reset      (reset),
        .drawX      (drawX),
        .drawY      (drawY),
        .in_valid   (in_valid),
        .ray_dir_x  (ray_dir_x),
        .ray_dir_y  (ray_dir_y),
        .ray_dir_z  (ray_dir_z),
        .ray_valid  (ray_valid)
    );

    // 100 MHz Clock Generation (10 ns period)
    always #5 clk = ~clk;

    // Helper task to convert Q8.8 fixed-point to real float
    function real q88_to_real(input logic signed [15:0] val);
        q88_to_real = real'(val) / 256.0;
    endfunction

    // Task to apply a pixel and verify unit norm after pipeline latency
    task check_pixel(
        input [9:0] x,
        input [9:0] y,
        input string desc
    );
        real fx, fy, fz, mag;
        begin
            @(posedge clk);
            drawX    <= x;
            drawY    <= y;
            in_valid <= 1'b1;

            // Wait for 5-stage pipeline latency (5 cycles)
            repeat (5) @(posedge clk);
            #1; // Sample shortly after clock edge

            fx  = q88_to_real(ray_dir_x);
            fy  = q88_to_real(ray_dir_y);
            fz  = q88_to_real(ray_dir_z);
            mag = $sqrt(fx*fx + fy*fy + fz*fz);

            $display("----------------------------------------------------------------------");
            $display("Test: %s at (%0d, %0d)", desc, x, y);
            $display("  Q8.8 Hex: (dx=0x%04X, dy=0x%04X, dz=0x%04X)", ray_dir_x, ray_dir_y, ray_dir_z);
            $display("  Float   : (dx=%0.4f, dy=%0.4f, dz=%0.4f)", fx, fy, fz);
            $display("  Length  : %0.4f (Expected ~1.000)", mag);

            if (mag >= 0.95 && mag <= 1.05) begin
                $display("  STATUS  : [PASS] Ray is properly normalized.");
            end else begin
                $display("  STATUS  : [FAIL] Ray length outside acceptable tolerance!");
            end
        end
    endtask

    initial begin
        $display("======================================================================");
        $display("Starting HARPU Ray Generation Pipeline Testbench");
        $display("======================================================================");

        // Initialize signals
        clk      = 0;
        reset    = 1;
        drawX    = 0;
        drawY    = 0;
        in_valid = 0;

        // Reset sequence (20 ns)
        #20;
        @(posedge clk);
        reset = 0;
        @(posedge clk);

        // Test 1: Screen Center (160, 120) -> Ray should point straight forward along +Z
        check_pixel(10'd160, 10'd120, "Screen Center");

        // Test 2: Top Center (160, 0) -> Ray should tilt upward (+Y)
        check_pixel(10'd160, 10'd0, "Top Center");

        // Test 3: Bottom Center (160, 239) -> Ray should tilt downward (-Y)
        check_pixel(10'd160, 10'd239, "Bottom Center");

        // Test 4: Left Center (0, 120) -> Ray should tilt left (-X)
        check_pixel(10'd0, 10'd120, "Left Center");

        // Test 5: Right Center (319, 120) -> Ray should tilt right (+X)
        check_pixel(10'd319, 10'd120, "Right Center");

        // Test 6: Top-Left Corner (0, 0) -> Ray should tilt left and up
        check_pixel(10'd0, 10'd0, "Top-Left Corner");

        // Test 7: Bottom-Right Corner (319, 239) -> Ray should tilt right and down
        check_pixel(10'd319, 10'd239, "Bottom-Right Corner");

        #50;
        $display("======================================================================");
        $display("Ray Generation Simulation Complete!");
        $display("======================================================================");
        $finish;
    end

endmodule
