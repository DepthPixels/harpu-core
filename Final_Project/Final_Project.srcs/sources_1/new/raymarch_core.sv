`timescale 1ns / 1ps

module raymarch_core (
    input  logic        clk,
    input  logic        reset, // Async high reset

    input  logic [9:0]  drawX,
    input  logic [9:0]  drawY,
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
    input  logic signed [15:0] inv_carve_radius,
    input  logic        [1:0]  sphere_material,
    
    output logic [16:0] fb_addr,
    output logic [23:0] fb_din,
    output logic        fb_we,

    output logic        frame_done
);

    // typedef enum logic [2:0] {
    //     INIT,
    //     UPDATE_P,
    //     CHECK_STEP,
    //     NORM_X,
    //     NORM_Y,
    //     NORM_Z,
    //     SHADE
    // } raymarch_fsm_t;

    // raymarch_fsm_t raymarch_state;

    logic        [8:0]  gen_x;
    logic        [7:0]  gen_y;
    logic        [16:0] pixel_spawn_count;
    logic        [16:0] pixels_fed;
    logic        [8:0]  slot_render_x [0:15];
    logic        [7:0]  slot_render_y [0:15];

    // Ray Generation Signals
    logic signed [15:0] ray_dir_x_in, ray_dir_y_in, ray_dir_z_in;
    logic signed [15:0] ray_dir_x [0:15];
    logic signed [15:0] ray_dir_y [0:15];
    logic signed [15:0] ray_dir_z [0:15];
    logic               ray_in_valid;
    logic               ray_valid;
    logic        [8:0]  ray_x_pipe [0:5];
    logic        [7:0]  ray_y_pipe [0:5];
    logic        [8:0]  ray_x_aligned;
    logic        [7:0]  ray_y_aligned;

    assign ray_x_aligned = ray_x_pipe[5];
    assign ray_y_aligned = ray_y_pipe[5];

    // Camera Origin at (0, 0, -2.5)
    logic signed [15:0] origin_x = 16'sh0000;
    logic signed [15:0] origin_y = 16'sh0000;
    logic signed [15:0] origin_z = 16'shFD80;

    logic signed [15:0] pos_x, pos_y, pos_z;
    logic signed [15:0] pos_x_out, pos_y_out, pos_z_out;
    logic signed [15:0] sdf_dist;
    logic               sdf_valid;
    logic               sdf_in_valid;

    logic signed [15:0] ray_t [0:15];
    logic signed [15:0] ray_t_min = 16'sh0100;
    logic signed [15:0] ray_t_max = 16'sh0600;
    logic signed [15:0] norm_x, norm_y, norm_z;
    logic signed [15:0] norm_sphere_x, norm_sphere_y, norm_sphere_z;
    logic signed [15:0] norm_carve_x, norm_carve_y, norm_carve_z;
    logic signed [15:0] step_cnt [0:15];
    logic               hit;
    logic               hit_carve;
    logic               is_carve_reg;

    logic signed [15:0] sdf_d_diff;
    logic        [23:0] shaded_output;

    // Pipelining stuff
    logic        [3:0]  issue_ptr;
    logic        [15:0] slot_active;
    logic        [3:0]  ray_tag_in;
    logic        [3:0]  ray_tag_out;

    // 16-deep x 65-bit Circular FIFO Storage
    logic        [8:0]  fifo_x   [0:15];
    logic        [7:0]  fifo_y   [0:15];
    logic signed [15:0] fifo_dx  [0:15];
    logic signed [15:0] fifo_dy  [0:15];
    logic signed [15:0] fifo_dz  [0:15];
    logic        [8:0]  fifo_head_x;
    logic        [7:0]  fifo_head_y;
    logic signed [15:0] fifo_head_dx, fifo_head_dy, fifo_head_dz;

    logic [3:0] fifo_wr_ptr;
    logic [3:0] fifo_rd_ptr;
    logic [4:0] fifo_count;   // 0 to 16
    logic       fifo_empty;
    logic       fifo_full;

    assign fifo_empty = (fifo_count == 5'd0);
    assign fifo_full  = (fifo_count >= 5'd16);

    assign fifo_head_x  = fifo_x[fifo_rd_ptr];
    assign fifo_head_y  = fifo_y[fifo_rd_ptr];
    assign fifo_head_dx = fifo_dx[fifo_rd_ptr];
    assign fifo_head_dy = fifo_dy[fifo_rd_ptr];
    assign fifo_head_dz = fifo_dz[fifo_rd_ptr];

    logic fifo_wr;
    logic fifo_rd;
    assign fifo_wr = ray_valid;
    assign fifo_rd = (!slot_active[issue_ptr]) && (!fifo_empty) && (pixel_spawn_count < 17'd76800);

    // Stage 0 Hit Latch Registers (decouples SDF hit detection from CSG normal calculation)
    logic               s0_retire_we;
    logic               s0_retire_is_hit;
    logic [16:0]        s0_retire_addr;
    logic signed [15:0] s0_pos_x, s0_pos_y, s0_pos_z;
    logic signed [15:0] s0_d_diff;

    logic s0_pix_x;
    logic s0_pix_y;

    // Stage 1 CSG Normal Delay Registers (decouples Carve Normal DSP from CSG Blend DSP)
    logic signed [15:0] s1_norm_carve_x, s1_norm_carve_y, s1_norm_carve_z;
    logic signed [15:0] s1_norm_sphere_x, s1_norm_sphere_y, s1_norm_sphere_z;
    logic [8:0]         s1_blend_w;
    logic [8:0]         stage1_blend_w;
    logic               s1_retire_we;
    logic               s1_retire_is_hit;
    logic [16:0]        s1_retire_addr;

    logic s1_pix_x;
    logic s1_pix_y;

    // Shading Pipeline Stage 2 Registers (between CSG Blend & Sphere Shader)
    logic signed [15:0] pipe_norm_x, pipe_norm_y, pipe_norm_z;
    logic        [16:0] pipe_addr;
    logic               pipe_is_hit;
    logic               pipe_we;

    logic pipe_pix_x;
    logic pipe_pix_y;

    // Retire Shading Pipeline Delay Registers (aligning with sphere_shader 4-cycle latency)
    logic        pipe_we_r   [1:4];
    logic [16:0] pipe_addr_r [1:4];
    logic        pipe_hit_r  [1:4];

    logic can_feed;
    assign can_feed = (fifo_count <= 5'd6) && (pixels_fed < 17'd76800);
    assign ray_in_valid = can_feed;

    logic [3:0] ray_tag_reg;
    assign ray_tag_in = ray_tag_reg;
    assign frame_done = (pixel_spawn_count == 17'd76800) && (slot_active == 16'd0);

    always_ff @(posedge clk or posedge reset) begin: RAYMARCH_FSM
        if (reset) begin
            hit               <= 1'b0;
            sdf_in_valid      <= 1'b0;
            s0_retire_we      <= 1'b0;
            s0_retire_is_hit  <= 1'b0;
            s0_retire_addr    <= 17'd0;
            s0_pos_x          <= 16'sh0000;
            s0_pos_y          <= 16'sh0000;
            s0_pos_z          <= 16'sh0000;
            s0_d_diff         <= 16'sh0000;
            s1_norm_carve_x   <= 16'sh0000;
            s1_norm_carve_y   <= 16'sh0000;
            s1_norm_carve_z   <= 16'sh0000;
            s1_norm_sphere_x  <= 16'sh0000;
            s1_norm_sphere_y  <= 16'sh0000;
            s1_norm_sphere_z  <= 16'sh0000;
            s1_blend_w        <= 9'd0;
            s1_retire_we      <= 1'b0;
            s1_retire_is_hit  <= 1'b0;
            s1_retire_addr    <= 17'd0;
            pipe_we           <= 1'b0;
            pipe_is_hit       <= 1'b0;
            pipe_addr         <= 17'd0;
            pipe_norm_x       <= 16'sh0000;
            pipe_norm_y       <= 16'sh0000;
            pipe_norm_z       <= 16'sh0000;
            fb_we             <= 1'b0;
            fb_din            <= 24'd0;
            fb_addr           <= 17'd0;
            for (int i = 1; i <= 4; i++) begin
                pipe_we_r[i]   <= 1'b0;
                pipe_addr_r[i] <= 17'd0;
                pipe_hit_r[i]  <= 1'b0;
            end
            gen_x             <= 9'd0;
            gen_y             <= 8'd0;
            pos_x             <= origin_x;
            pos_y             <= origin_y;
            pos_z             <= origin_z;
            issue_ptr         <= 4'd0;
            slot_active       <= 16'd0;
            pixel_spawn_count <= 17'd0;
            fifo_wr_ptr       <= 4'd0;
            fifo_rd_ptr       <= 4'd0;
            fifo_count        <= 5'd0;
            pixels_fed        <= 17'd0;
            ray_tag_reg       <= 4'd0;
        end else begin
            issue_ptr <= issue_ptr + 4'd1;

            // Retire Shading Pipeline Delay: align with sphere_shader 4-cycle latency
            pipe_we_r[1]   <= pipe_we;
            pipe_addr_r[1] <= pipe_addr;
            pipe_hit_r[1]  <= pipe_is_hit;

            pipe_we_r[2]   <= pipe_we_r[1];
            pipe_addr_r[2] <= pipe_addr_r[1];
            pipe_hit_r[2]  <= pipe_hit_r[1];

            pipe_we_r[3]   <= pipe_we_r[2];
            pipe_addr_r[3] <= pipe_addr_r[2];
            pipe_hit_r[3]  <= pipe_hit_r[2];

            pipe_we_r[4]   <= pipe_we_r[3];
            pipe_addr_r[4] <= pipe_addr_r[3];
            pipe_hit_r[4]  <= pipe_hit_r[3];

            // Framebuffer writeback at Stage 5 (coincident with valid shaded_output)
            fb_we   <= pipe_we_r[4];
            fb_addr <= pipe_addr_r[4];
            fb_din  <= pipe_hit_r[4] ? shaded_output : 24'h101820;

            // FIFO Stuff
            if (can_feed == 1) begin
                pixels_fed <= pixels_fed + 17'd1;
                if (gen_x == 9'd319) begin
                    gen_x <= 9'd0;
                    gen_y <= (gen_y == 8'd239) ? 8'd0 : gen_y + 8'd1;
                end else begin
                    gen_x <= gen_x + 9'd1;
                end
            end

            if (ray_valid == 1) begin
                fifo_x[fifo_wr_ptr] <= ray_x_aligned;
                fifo_y[fifo_wr_ptr] <= ray_y_aligned;
                fifo_dx[fifo_wr_ptr] <= ray_dir_x_in;
                fifo_dy[fifo_wr_ptr] <= ray_dir_y_in;
                fifo_dz[fifo_wr_ptr] <= ray_dir_z_in;
                fifo_wr_ptr <= fifo_wr_ptr + 4'd1;
            end

            case ({fifo_wr, fifo_rd})
                2'b10:   fifo_count <= fifo_count + 5'd1; // write only
                2'b01:   fifo_count <= fifo_count - 5'd1; // read only
                default: fifo_count <= fifo_count;        // both or neither
            endcase

            if (pixel_spawn_count == 17'd76800 && slot_active == 16'd0) begin
                pixel_spawn_count <= 17'd0;
                pixels_fed        <= 17'd0;
                gen_x             <= 9'd0;
                gen_y             <= 8'd0;
                fifo_wr_ptr       <= 4'd0;
                fifo_rd_ptr       <= 4'd0;
                fifo_count        <= 5'd0;
            end

            if (slot_active[issue_ptr]) begin
                pos_x <= origin_x + 16'((32'(ray_dir_x[issue_ptr]) * 32'(ray_t[issue_ptr])) >>> 8);
                pos_y <= origin_y + 16'((32'(ray_dir_y[issue_ptr]) * 32'(ray_t[issue_ptr])) >>> 8);
                pos_z <= origin_z + 16'((32'(ray_dir_z[issue_ptr]) * 32'(ray_t[issue_ptr])) >>> 8);
                sdf_in_valid <= 1'b1;
                ray_tag_reg <= issue_ptr;
            end else begin
                if (pixel_spawn_count < 17'd76800 && !fifo_empty) begin
                    fifo_rd_ptr <= fifo_rd_ptr + 4'd1;
                    slot_render_x[issue_ptr] <= fifo_head_x;                    
                    slot_render_y[issue_ptr] <= fifo_head_y;
                    ray_dir_x[issue_ptr]    <= fifo_head_dx;
                    ray_dir_y[issue_ptr]    <= fifo_head_dy;
                    ray_dir_z[issue_ptr]    <= fifo_head_dz;
                    pos_x <= origin_x + fifo_head_dx;
                    pos_y <= origin_y + fifo_head_dy;
                    pos_z <= origin_z + fifo_head_dz;
                    ray_t[issue_ptr] <= ray_t_min;
                    step_cnt[issue_ptr] <= '0;
                    slot_active[issue_ptr] <= 1'b1;
                    sdf_in_valid <= 1'b1;
                    ray_tag_reg <= issue_ptr;
                    pixel_spawn_count <= pixel_spawn_count + 1;

                end else begin
                    sdf_in_valid <= 0;
                end
            end

            // Stage 1 CSG Normal Pipeline Registers (Carve Normal & Coordinate Forwarding)
            s1_norm_carve_x  <= norm_carve_x;
            s1_norm_carve_y  <= norm_carve_y;
            s1_norm_carve_z  <= norm_carve_z;
            s1_norm_sphere_x <= s0_pos_x;
            s1_norm_sphere_y <= s0_pos_y;
            s1_norm_sphere_z <= s0_pos_z;
            s1_blend_w       <= stage1_blend_w;
            s1_retire_we     <= s0_retire_we;
            s1_retire_is_hit <= s0_retire_is_hit;
            s1_retire_addr   <= s0_retire_addr;
            s1_pix_x         <= s0_pix_x;
            s1_pix_y         <= s0_pix_y;

            // Stage 2 CSG Normal Pipeline Registers (Analytical Normal Blend into Shader)
            pipe_we     <= s1_retire_we;
            pipe_is_hit <= s1_retire_is_hit;
            pipe_addr   <= s1_retire_addr;
            pipe_norm_x <= norm_x;
            pipe_norm_y <= norm_y;
            pipe_norm_z <= norm_z;
            pipe_pix_x  <= s1_pix_x;
            pipe_pix_y  <= s1_pix_y;

            // Default stage 0 retire write enable
            s0_retire_we <= 1'b0;

            if (sdf_valid == 1) begin
                if (sdf_dist < 16'sh0002) begin
                    // Surface Hit: Retire slot, latch hit coordinates & write address
                    slot_active[ray_tag_out] <= 1'b0;
                    s0_retire_is_hit <= 1'b1;
                    s0_retire_we     <= 1'b1;
                    s0_pos_x         <= pos_x_out;
                    s0_pos_y         <= pos_y_out;
                    s0_pos_z         <= pos_z_out;
                    s0_d_diff        <= sdf_d_diff;
                    s0_retire_addr   <= ({1'b0, slot_render_y[ray_tag_out], 8'b0} + 
                                         {3'b0, slot_render_y[ray_tag_out], 6'b0}) + 
                                         {8'b0, slot_render_x[ray_tag_out]};
                    s0_pix_x         <= slot_render_x[ray_tag_out][0];
                    s0_pix_y         <= slot_render_y[ray_tag_out][0];
                end
                else if (ray_t[ray_tag_out] > ray_t_max || step_cnt[ray_tag_out] > 16'sd24) begin
                    // Background Miss: Retire slot, flag as background
                    slot_active[ray_tag_out] <= 1'b0;
                    s0_retire_is_hit <= 1'b0;
                    s0_retire_we     <= 1'b1;
                    s0_pos_x         <= 16'sh0000;
                    s0_pos_y         <= 16'sh0000;
                    s0_pos_z         <= 16'sh0000;
                    s0_d_diff        <= 16'sh0000;
                    s0_retire_addr   <= ({1'b0, slot_render_y[ray_tag_out], 8'b0} + 
                                         {3'b0, slot_render_y[ray_tag_out], 6'b0}) + 
                                         {8'b0, slot_render_x[ray_tag_out]};
                end
                else begin
                    // Step forward in the scene
                    ray_t[ray_tag_out]    <= ray_t[ray_tag_out] + sdf_dist;
                    step_cnt[ray_tag_out] <= step_cnt[ray_tag_out] + 16'sd1;
                    slot_active[ray_tag_out] <= 1'b1;
                end
            end
        end
    end

    logic signed [15:0] c_diff_x, c_diff_y, c_diff_z;
    logic signed [31:0] ext_diff_x, ext_diff_y, ext_diff_z;
    logic signed [31:0] ext_inv_radius;

    assign c_diff_x = carve_x - s0_pos_x;
    assign c_diff_y = carve_y - s0_pos_y;
    assign c_diff_z = carve_z - s0_pos_z;

    assign ext_diff_x = {{16{c_diff_x[15]}}, c_diff_x};
    assign ext_diff_y = {{16{c_diff_y[15]}}, c_diff_y};
    assign ext_diff_z = {{16{c_diff_z[15]}}, c_diff_z};
    assign ext_inv_radius = {{16{inv_carve_radius[15]}}, inv_carve_radius};

    logic signed [31:0] ext_d_diff;
    logic signed [15:0] stage1_d_rel;

    assign ext_d_diff = {{16{s0_d_diff[15]}}, s0_d_diff};
    assign stage1_d_rel = 16'((ext_d_diff * ext_inv_radius) >>> 8);

    always_comb begin
        if (!carve_en || stage1_d_rel[15] == 1'b1) begin
            stage1_blend_w = 9'd0;    // Pure sphere (outside hole)
        end else if (stage1_d_rel >= 16'sh0080) begin
            stage1_blend_w = 9'd256;  // Pure crater interior
        end else begin
            stage1_blend_w = 9'((32'(stage1_d_rel)) << 1); // Gentle, smooth bleed into bevel
        end
    end

    always_comb begin
        // Stage 1 CSG Carve Normal (1 DSP48E1 slice, ~4.0 ns)
        norm_carve_x = 16'((ext_diff_x * ext_inv_radius) >>> 8);
        norm_carve_y = 16'((ext_diff_y * ext_inv_radius) >>> 8);
        norm_carve_z = 16'((ext_diff_z * ext_inv_radius) >>> 8);

        // Stage 2 Continuous Signed Analytical CSG Gradient Blend (Single DSP Multiply-Add, ~3.5 ns)
        // N_blend = N_sphere + ((N_carve - N_sphere) * w) >>> 8
        norm_x = s1_norm_sphere_x + 16'((32'(s1_norm_carve_x - s1_norm_sphere_x) * 32'($signed({1'b0, s1_blend_w}))) >>> 8);
        norm_y = s1_norm_sphere_y + 16'((32'(s1_norm_carve_y - s1_norm_sphere_y) * 32'($signed({1'b0, s1_blend_w}))) >>> 8);
        norm_z = s1_norm_sphere_z + 16'((32'(s1_norm_carve_z - s1_norm_sphere_z) * 32'($signed({1'b0, s1_blend_w}))) >>> 8);
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 6; i++) begin
                ray_x_pipe[i] <= 9'b0;
                ray_y_pipe[i] <= 8'b0;
            end
        end else begin
            // Stage 0 register update
            ray_x_pipe[0] <= gen_x;
            ray_y_pipe[0] <= gen_y;

            // Stages 1 to 5 register updates (aligned with 6-cycle ray_gen latency)
            for (int i = 1; i < 6; i++) begin
                ray_x_pipe[i] <= ray_x_pipe[i-1];
                ray_y_pipe[i] <= ray_y_pipe[i-1];
            end
        end
    end

    ray_gen ray_gen_inst (
        .clk(clk),
        .reset(reset),
        .drawX({1'b0, gen_x}),
        .drawY({2'b0, gen_y}),
        .in_valid(ray_in_valid),
        .ray_dir_x(ray_dir_x_in),
        .ray_dir_y(ray_dir_y_in),
        .ray_dir_z(ray_dir_z_in),
        .ray_valid(ray_valid)
    );

    sdf_scene sdf_scene_inst (
        .clk(clk),
        .reset(reset),
        .pos_x_in(pos_x),
        .pos_y_in(pos_y),
        .pos_z_in(pos_z),
        .pos_x_out(pos_x_out),
        .pos_y_out(pos_y_out),
        .pos_z_out(pos_z_out),
        .carve_en(carve_en),
        .carve_x(carve_x),
        .carve_y(carve_y),
        .carve_z(carve_z),
        .carve_radius(carve_radius),
        .inv_carve_radius(inv_carve_radius),
        .in_valid(sdf_in_valid),
        .dist_out(sdf_dist),
        .out_valid(sdf_valid),
        .hit_carve(hit_carve),
        .d_diff(sdf_d_diff),
        .ray_tag_in(ray_tag_in),
        .ray_tag_out(ray_tag_out)
    );

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
        .pix_x(pipe_pix_x),
        .pix_y(pipe_pix_y)
    );

endmodule