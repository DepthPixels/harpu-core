`timescale 1ns / 1ps

module raymarch_core (
    input  logic        clk,
    input  logic        reset, // Async high reset

    input  logic        carve_en,
    input  logic signed [15:0] carve_x,
    input  logic signed [15:0] carve_y,
    input  logic signed [15:0] carve_z,
    input  logic signed [15:0] light_dir_x,
    input  logic signed [15:0] light_dir_y,
    input  logic signed [15:0] light_dir_z,
    input  logic signed [15:0] half_x,
    input  logic signed [15:0] half_y,
    input  logic signed [15:0] half_z,
    input  logic signed [15:0] carve_radius,
    input  logic        [1:0]  sphere_material,
    
    output logic [16:0] fb_addr,
    output logic [23:0] fb_din,
    output logic        fb_we,

    output logic        frame_done
);


    // FSM Declaration and data

    typedef enum logic [2:0] {
        S_MARCH,
        S_NORM0,
        S_NORM1,
        S_NORM2,
        S_NORM3,
        S_NORM_WAIT,
        S_AO
    } slot_state_t;

    logic [3:0] issue_ptr;

    slot_state_t slot_state [0:15];
    logic [15:0] slot_active;

    logic signed [15:0] slot_hit_x [0:15];
    logic signed [15:0] slot_hit_y [0:15];
    logic signed [15:0] slot_hit_z [0:15];
    logic signed [15:0] slot_nx    [0:15];
    logic signed [15:0] slot_ny    [0:15];
    logic signed [15:0] slot_nz    [0:15];
    logic signed [15:0] slot_norm_x [0:15];
    logic signed [15:0] slot_norm_y [0:15];
    logic signed [15:0] slot_norm_z [0:15];


    //
    // Section 1
    // Pixel Feeder and Ray FIFO
    //

    logic [8:0]  gen_x;
    logic [7:0]  gen_y;
    logic [16:0] pixels_fed;
    logic [16:0] pixels_spawn_count;

    // wires for ray_gen
    logic        ray_gen_in_valid;
    logic        ray_valid;
    logic signed [15:0] ray_dir_x_in;
    logic signed [15:0] ray_dir_y_in;
    logic signed [15:0] ray_dir_z_in;

    // Pipeline for Raygen (6-cycle delay)
    logic [8:0]  ray_x_pipe [0:5];
    logic [7:0]  ray_y_pipe [0:5];
    logic [8:0]  ray_x_aligned;
    logic [7:0]  ray_y_aligned;

    assign ray_x_aligned = ray_x_pipe[5];
    assign ray_y_aligned = ray_y_pipe[5];

    // 16 deep FIFO for Raygen
    logic [8:0]  fifo_x [0:15];
    logic [7:0]  fifo_y [0:15];
    logic [3:0]  fifo_wr_ptr;
    logic [3:0]  fifo_rd_ptr;
    logic [4:0]  fifo_count;
    logic signed [15:0] fifo_dx [0:15];
    logic signed [15:0] fifo_dy [0:15];
    logic signed [15:0] fifo_dz [0:15];

    // Section 2 Connection Wires
    logic fifo_empty;
    logic can_feed;
    logic fifo_wr;
    logic fifo_rd;
    logic [8:0]  fifo_head_x;
    logic [7:0]  fifo_head_y;
    logic signed [15:0] fifo_head_dx;
    logic signed [15:0] fifo_head_dy;
    logic signed [15:0] fifo_head_dz;

    always_comb begin
        fifo_empty = (fifo_count == 5'd0);
        can_feed = ((fifo_count <= 5'd6) && (pixels_fed < 17'd76800));
        ray_gen_in_valid = can_feed;
        fifo_wr = ray_valid;
        fifo_rd = ((!slot_active[issue_ptr]) && (!fifo_empty) && (pixels_spawn_count < 17'd76800));
        frame_done = ((pixels_spawn_count == 17'd76800) && (slot_active == 16'd0));

        fifo_head_x = fifo_x[fifo_rd_ptr];
        fifo_head_y = fifo_y[fifo_rd_ptr];
        fifo_head_dx = fifo_dx[fifo_rd_ptr];
        fifo_head_dy = fifo_dy[fifo_rd_ptr];
        fifo_head_dz = fifo_dz[fifo_rd_ptr];
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            gen_x <= 9'd0;
            gen_y <= 8'd0;
            pixels_fed <= 17'd0;
            fifo_wr_ptr <= 4'd0;
            fifo_rd_ptr <= 4'd0;
            fifo_count <= 5'd0;

            for (int i = 0; i < 6; i++) begin
                ray_x_pipe[i] <= 9'd0;
                ray_y_pipe[i] <= 8'd0;
            end
        end else if (frame_done) begin  // Also reset on frame_done to prep for next frame
            gen_x <= 9'd0;
            gen_y <= 8'd0;
            pixels_fed <= 17'd0;
            fifo_wr_ptr <= 4'd0;
            fifo_rd_ptr <= 4'd0;
            fifo_count <= 5'd0;

            for (int i = 0; i < 6; i++) begin
                ray_x_pipe[i] <= 9'd0;
                ray_y_pipe[i] <= 8'd0;
            end
        end else begin
            // The next pixel is fed simultaneously so update the counters and prep the next pixel
            if (can_feed) begin
                pixels_fed <= pixels_fed + 17'd1;
                if (gen_x == 9'd319) begin
                    gen_x <= 9'd0;
                    gen_y <= (gen_y == 8'd239) ? 8'd0 : gen_y + 8'd1;
                end else begin
                    gen_x <= gen_x + 9'd1;
                end
            end

            // Update FIFO Write Pointers and Data
            if (fifo_wr) begin
                fifo_x[fifo_wr_ptr] <= ray_x_aligned;
                fifo_y[fifo_wr_ptr] <= ray_y_aligned;
                fifo_dx[fifo_wr_ptr] <= ray_dir_x_in;
                fifo_dy[fifo_wr_ptr] <= ray_dir_y_in;
                fifo_dz[fifo_wr_ptr] <= ray_dir_z_in;

                fifo_wr_ptr <= fifo_wr_ptr + 4'd1;
            end

            // Update fifo_rd_ptr
            if (fifo_rd) begin
                fifo_rd_ptr <= fifo_rd_ptr + 4'd1;
            end

            // Update FIFO count
            case ({fifo_wr, fifo_rd})
                2'b01: fifo_count <= fifo_count - 5'd1;
                2'b10: fifo_count <= fifo_count + 5'd1;
                default: fifo_count <= fifo_count;
            endcase

            // Pipeline ray_x and ray_y
            ray_x_pipe[0] <= gen_x;
            ray_y_pipe[0] <= gen_y;
            for (int i = 0; i < 5; i++) begin
                ray_x_pipe[i+1] <= ray_x_pipe[i];
                ray_y_pipe[i+1] <= ray_y_pipe[i];
            end
        end
    end

    // Raygen Instantiation
    ray_gen ray_gen_inst (
        .clk(clk),
        .reset(reset),
        .drawX({1'b0, gen_x}),
        .drawY({2'b0, gen_y}),
        .in_valid(ray_gen_in_valid),
        .ray_dir_x(ray_dir_x_in),
        .ray_dir_y(ray_dir_y_in),
        .ray_dir_z(ray_dir_z_in),
        .ray_valid(ray_valid)
    );


    //
    // Section 2
    // Ray Marching and SDF Scene Evaluation - 16 Slot Wavefront Core
    //

    // Constants
    localparam logic signed [15:0] origin_x = 16'sh0000;
    localparam logic signed [15:0] origin_y = 16'sh0000;
    localparam logic signed [15:0] origin_z = 16'shFD80; // -2.5 in Q8.8
    localparam logic signed [15:0] ray_t_min = 16'sh0100;
    localparam logic signed [15:0] ray_t_max = 16'sh0600;
    localparam logic signed [15:0] NORM_EPS = 16'sh0008;

    // Marching Slots
    logic [8:0]  slot_render_x [0:15]; // Screen Coords
    logic [7:0]  slot_render_y [0:15];
    logic [15:0] slot_step_cnt [0:15]; // Step Count
    logic signed [15:0] slot_ray_dx [0:15]; // Ray Directions
    logic signed [15:0] slot_ray_dy [0:15];
    logic signed [15:0] slot_ray_dz [0:15];
    logic signed [15:0] slot_ray_t [0:15]; // Ray Marching Distance

    // SDF Scene Connection Wires
    logic sdf_in_valid;
    logic sdf_valid;
    logic [3:0]  ray_tag_in;
    logic [3:0]  ray_tag_out;
    logic signed [15:0] sdf_pos_x;
    logic signed [15:0] sdf_pos_y;
    logic signed [15:0] sdf_pos_z;
    logic signed [15:0] sdf_pos_x_out;
    logic signed [15:0] sdf_pos_y_out;
    logic signed [15:0] sdf_pos_z_out;
    logic signed [15:0] sdf_dist;

    // Normalizer Connection Wires
    logic norm_in_valid;
    logic norm_out_valid;
    logic [3:0]  norm_tag_in;
    logic [3:0]  norm_tag_out;
    logic signed [15:0] norm_in_x;
    logic signed [15:0] norm_in_y;
    logic signed [15:0] norm_in_z;
    logic signed [15:0] norm_out_x;
    logic signed [15:0] norm_out_y;
    logic signed [15:0] norm_out_z;

    // Retire Connections to Section 3
    logic pipe_we;
    logic pipe_hit;
    logic [16:0] pipe_addr;
    logic [8:0]  pipe_ao;
    logic signed [15:0] pipe_norm_x;
    logic signed [15:0] pipe_norm_y;
    logic signed [15:0] pipe_norm_z;

    
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            issue_ptr <= 4'd0;
            slot_active <= 16'd0;
            pixels_spawn_count <= 17'd0;
            sdf_in_valid <= 1'b0;
            ray_tag_in <= 4'd0;
            norm_in_valid <= 1'b0;
            pipe_we <= 1'b0;
            pipe_hit <= 1'b0;
            pipe_addr <= 17'd0;
            pipe_ao <= 9'd0;

            sdf_pos_x <= origin_x;
            sdf_pos_y <= origin_y;
            sdf_pos_z <= origin_z;
            
            for (int i = 0; i < 16; i++) begin
                slot_state[i] <= S_MARCH;
            end
        end else begin
            issue_ptr <= issue_ptr + 4'd1;
            if (frame_done) pixels_spawn_count <= 17'd0;

            // Issue new rays
            if (slot_active[issue_ptr] == 1'b1) begin // This slot is active so continue marching it
                ray_tag_in <= issue_ptr;
                
                case (slot_state[issue_ptr]) // This isn't state management, just grouping the SDF stuff here
                    S_MARCH: begin
                        sdf_pos_x <= 16'(((32'(origin_x) <<< 8) + (32'(slot_ray_dx[issue_ptr]) * 32'(slot_ray_t[issue_ptr]))) >>> 8);
                        sdf_pos_y <= 16'(((32'(origin_y) <<< 8) + (32'(slot_ray_dy[issue_ptr]) * 32'(slot_ray_t[issue_ptr]))) >>> 8);
                        sdf_pos_z <= 16'(((32'(origin_z) <<< 8) + (32'(slot_ray_dz[issue_ptr]) * 32'(slot_ray_t[issue_ptr]))) >>> 8);

                        sdf_in_valid <= 1'b1;
                    end
                    S_NORM0: begin
                        sdf_pos_x <= slot_hit_x[issue_ptr] + NORM_EPS;
                        sdf_pos_y <= slot_hit_y[issue_ptr] - NORM_EPS;
                        sdf_pos_z <= slot_hit_z[issue_ptr] - NORM_EPS;

                        sdf_in_valid <= 1'b1;
                    end
                    S_NORM1: begin
                        sdf_pos_x <= slot_hit_x[issue_ptr] - NORM_EPS;
                        sdf_pos_y <= slot_hit_y[issue_ptr] - NORM_EPS;
                        sdf_pos_z <= slot_hit_z[issue_ptr] + NORM_EPS;

                        sdf_in_valid <= 1'b1;
                    end
                    S_NORM2: begin
                        sdf_pos_x <= slot_hit_x[issue_ptr] - NORM_EPS;
                        sdf_pos_y <= slot_hit_y[issue_ptr] + NORM_EPS;
                        sdf_pos_z <= slot_hit_z[issue_ptr] - NORM_EPS;

                        sdf_in_valid <= 1'b1;
                    end
                    S_NORM3: begin
                        sdf_pos_x <= slot_hit_x[issue_ptr] + NORM_EPS;
                        sdf_pos_y <= slot_hit_y[issue_ptr] + NORM_EPS;
                        sdf_pos_z <= slot_hit_z[issue_ptr] + NORM_EPS;

                        sdf_in_valid <= 1'b1;
                    end
                    S_NORM_WAIT: begin
                        sdf_in_valid <= 1'b0;
                    end
                    S_AO: begin
                        sdf_pos_x <= slot_hit_x[issue_ptr] + (slot_norm_x[issue_ptr] >>> 3);
                        sdf_pos_y <= slot_hit_y[issue_ptr] + (slot_norm_y[issue_ptr] >>> 3);
                        sdf_pos_z <= slot_hit_z[issue_ptr] + (slot_norm_z[issue_ptr] >>> 3);

                        sdf_in_valid <= 1'b1;
                    end
                    default: begin
                        sdf_in_valid <= 1'b0;
                    end
                endcase
            end else if (fifo_rd) begin // This slot isn't active so spawn one
                slot_render_x[issue_ptr] <= fifo_head_x;
                slot_render_y[issue_ptr] <= fifo_head_y;
                slot_ray_dx[issue_ptr] <= fifo_head_dx;
                slot_ray_dy[issue_ptr] <= fifo_head_dy;
                slot_ray_dz[issue_ptr] <= fifo_head_dz;
                slot_ray_t[issue_ptr] <= ray_t_min;
                slot_step_cnt[issue_ptr] <= 16'd0;
                slot_state[issue_ptr] <= S_MARCH;
                slot_active[issue_ptr] <= 1'b1;
                
                sdf_pos_x <= origin_x + fifo_head_dx;
                sdf_pos_y <= origin_y + fifo_head_dy;
                sdf_pos_z <= origin_z + fifo_head_dz;
                
                sdf_in_valid <= 1'b1;
                ray_tag_in <= issue_ptr;
                pixels_spawn_count <= pixels_spawn_count + 17'd1;
            end else begin
                sdf_in_valid <= 1'b0;
            end

            // Return from SDF and Normalizer
            pipe_we <= 1'b0;
            norm_in_valid <= 1'b0;

            if (sdf_valid) begin
                case (slot_state[ray_tag_out])
                    S_MARCH: begin
                        if (sdf_dist < 16'sh0002) begin // Hit
                            slot_hit_x[ray_tag_out] <= sdf_pos_x_out;
                            slot_hit_y[ray_tag_out] <= sdf_pos_y_out;
                            slot_hit_z[ray_tag_out] <= sdf_pos_z_out;

                            // Reset Normals
                            slot_nx[ray_tag_out] <= 16'sh0000;
                            slot_ny[ray_tag_out] <= 16'sh0000;
                            slot_nz[ray_tag_out] <= 16'sh0000;

                            slot_state[ray_tag_out] <= S_NORM0;
                        end else if (slot_ray_t[ray_tag_out] >= ray_t_max || slot_step_cnt[ray_tag_out] >= 16'd24) begin // Miss
                            // Retire Miss
                            pipe_we <= 1'b1;
                            pipe_hit <= 1'b0;
                            pipe_addr <= ({1'b0, slot_render_y[ray_tag_out], 8'b0} + {3'b0, slot_render_y[ray_tag_out], 6'b0} + {8'b0, slot_render_x[ray_tag_out]});
                            pipe_ao <= 9'd0;
                            pipe_norm_x <= 16'sh0000;
                            pipe_norm_y <= 16'sh0000;
                            pipe_norm_z <= 16'sh0000;

                            slot_active[ray_tag_out] <= 1'b0;
                        end else begin // Continue Marching
                            slot_ray_t[ray_tag_out] <= slot_ray_t[ray_tag_out] + sdf_dist;
                            slot_step_cnt[ray_tag_out] <= slot_step_cnt[ray_tag_out] + 16'd1;
                        end
                    end
                    S_NORM0: begin
                        slot_nx[ray_tag_out] <= slot_nx[ray_tag_out] + sdf_dist;
                        slot_ny[ray_tag_out] <= slot_ny[ray_tag_out] - sdf_dist;
                        slot_nz[ray_tag_out] <= slot_nz[ray_tag_out] - sdf_dist;

                        slot_state[ray_tag_out] <= S_NORM1;
                    end
                    S_NORM1: begin
                        slot_nx[ray_tag_out] <= slot_nx[ray_tag_out] - sdf_dist;
                        slot_ny[ray_tag_out] <= slot_ny[ray_tag_out] - sdf_dist;
                        slot_nz[ray_tag_out] <= slot_nz[ray_tag_out] + sdf_dist;

                        slot_state[ray_tag_out] <= S_NORM2;
                    end
                    S_NORM2: begin
                        slot_nx[ray_tag_out] <= slot_nx[ray_tag_out] - sdf_dist;
                        slot_ny[ray_tag_out] <= slot_ny[ray_tag_out] + sdf_dist;
                        slot_nz[ray_tag_out] <= slot_nz[ray_tag_out] - sdf_dist;

                        slot_state[ray_tag_out] <= S_NORM3;
                    end
                    S_NORM3: begin
                        norm_in_x <= slot_nx[ray_tag_out] + sdf_dist;
                        norm_in_y <= slot_ny[ray_tag_out] + sdf_dist;
                        norm_in_z <= slot_nz[ray_tag_out] + sdf_dist;

                        norm_tag_in <= ray_tag_out;
                        norm_in_valid <= 1'b1;

                        slot_state[ray_tag_out] <= S_NORM_WAIT;
                    end
                    S_NORM_WAIT: begin
                        // Wait for Normalizer to return
                        
                    end
                    S_AO: begin
                        // Retire Hit
                        pipe_we <= 1'b1;
                        pipe_hit <= 1'b1;
                        pipe_addr <= ({1'b0, slot_render_y[ray_tag_out], 8'b0} + {3'b0, slot_render_y[ray_tag_out], 6'b0} + {8'b0, slot_render_x[ray_tag_out]});
                        pipe_ao <= (sdf_dist <= 16'sh0000) ? 9'd128 : (sdf_dist >= 16'sh0020) ? 9'd256 : (9'd128 + {1'b0, sdf_dist[5:0], 2'b00}); // Clamp to [64, 256]
                        pipe_norm_x <= slot_norm_x[ray_tag_out];
                        pipe_norm_y <= slot_norm_y[ray_tag_out];
                        pipe_norm_z <= slot_norm_z[ray_tag_out];

                        slot_active[ray_tag_out] <= 1'b0;
                    end
                    default: begin
                        slot_state[ray_tag_out] <= S_MARCH;
                    end
                endcase
            end

            // Normalizer Return Check
            if (norm_out_valid) begin
                slot_norm_x[norm_tag_out] <= norm_out_x;
                slot_norm_y[norm_tag_out] <= norm_out_y;
                slot_norm_z[norm_tag_out] <= norm_out_z;

                slot_state[norm_tag_out] <= S_AO;
            end
        end
    end

    // Distance Calculation Instantiation
    sdf_scene sdf_scene_inst (
        .clk(clk),
        .reset(reset),
        .pos_x_in(sdf_pos_x),
        .pos_y_in(sdf_pos_y),
        .pos_z_in(sdf_pos_z),
        .pos_x_out(sdf_pos_x_out),
        .pos_y_out(sdf_pos_y_out),
        .pos_z_out(sdf_pos_z_out),
        .carve_en(carve_en),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .carve_radius(carve_radius),
        .in_valid(sdf_in_valid),
        .dist_out(sdf_dist),
        .out_valid(sdf_valid),
        .ray_tag_in(ray_tag_in),
        .ray_tag_out(ray_tag_out)
    );

    // Normalizer Instantiation
    vec3_normalize vec3_normalize_inst (
        .clk(clk),
        .reset(reset),
        .nx_in(norm_in_x),
        .ny_in(norm_in_y),
        .nz_in(norm_in_z),
        .tag_in(norm_tag_in),
        .valid(norm_in_valid),
        .norm_x(norm_out_x),
        .norm_y(norm_out_y),
        .norm_z(norm_out_z),
        .tag_out(norm_tag_out),
        .out_valid(norm_out_valid)
    );


    //
    // Section 3
    // Shading and Framebuffer Writeback
    //

    logic pipe_we_r [1:5];
    logic pipe_hit_r [1:5];
    logic [16:0] pipe_addr_r [1:5];
    logic [23:0] shaded_output;

    always_ff @(posedge clk) begin
        pipe_we_r[1] <= pipe_we;
        pipe_hit_r[1] <= pipe_hit;
        pipe_addr_r[1] <= pipe_addr;

        for (int i = 2; i <= 5; i++) begin
            pipe_we_r[i] <= pipe_we_r[i-1];
            pipe_hit_r[i] <= pipe_hit_r[i-1];
            pipe_addr_r[i] <= pipe_addr_r[i-1];
        end

        fb_we <= pipe_we_r[5];
        fb_addr <= pipe_addr_r[5];
        fb_din <= (pipe_hit_r[5]) ? shaded_output : 24'h87CEEB; // Sky Blue for Misses
    end

    sphere_shader sphere_shader_inst (
        .clk(clk),
        .reset(reset),
        .norm_x(pipe_norm_x),
        .norm_y(pipe_norm_y),
        .norm_z(pipe_norm_z),
        .light_dir_x(light_dir_x),
        .light_dir_y(light_dir_y),
        .light_dir_z(light_dir_z),
        .half_x(half_x),
        .half_y(half_y),
        .half_z(half_z),
        .sphere_material(sphere_material),
        .shaded_output(shaded_output),
        .ao_in(pipe_ao)
    );

endmodule
