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
    input  logic signed [15:0] carve_radius,
    input  logic signed [15:0] inv_carve_radius,
    
    output logic [16:0] fb_addr,
    output logic [11:0] fb_din,
    output logic        fb_we,

    output logic        frame_done
);

    typedef enum logic [2:0] {
        INIT,
        UPDATE_P,
        CHECK_STEP,
        NORM_X,
        NORM_Y,
        NORM_Z,
        SHADE
    } raymarch_fsm_t;

    raymarch_fsm_t raymarch_state;

    logic        [8:0]  render_x;
    logic        [7:0]  render_y;

    // Ray Generation Signals
    logic signed [15:0] ray_dir_x, ray_dir_y, ray_dir_z;
    logic               ray_in_valid;
    logic               ray_valid;

    // Camera Origin at (0, 0, -2.5)
    logic signed [15:0] origin_x = 16'sh0000;
    logic signed [15:0] origin_y = 16'sh0000;
    logic signed [15:0] origin_z = 16'shFD80;

    logic signed [15:0] pos_x, pos_y, pos_z;
    logic signed [15:0] sdf_dist;
    logic               sdf_valid;
    logic               sdf_in_valid;

    logic signed [15:0] ray_t;
    logic signed [15:0] ray_t_min = 16'sh0100;
    logic signed [15:0] ray_t_max = 16'sh0600;
    logic signed [15:0] norm_x, norm_y, norm_z;
    logic signed [15:0] norm_sphere_x, norm_sphere_y, norm_sphere_z;
    logic signed [15:0] norm_carve_x, norm_carve_y, norm_carve_z;
    logic signed [15:0] step_cnt;
    logic               hit;
    logic               hit_carve;
    logic               is_carve_reg;

    logic        [8:0]  blend_w;
    logic        [8:0]  blend_w_reg;

    logic        [11:0] shaded_output;

    assign frame_done = (render_x == 9'd319) && (render_y == 8'd239) && (raymarch_state == SHADE);

    always_ff @(posedge clk or posedge reset) begin: RAYMARCH_FSM
        if (reset) begin
            raymarch_state <= INIT;
            ray_t          <= ray_t_min;
            step_cnt       <= '0;
            pos_x          <= origin_x;
            pos_y          <= origin_y;
            pos_z          <= origin_z;
            hit            <= 1'b0;
            sdf_in_valid   <= 1'b0;
            ray_in_valid   <= 1'b1;
            fb_we          <= 1'b0;
            render_x <= 9'd0;
            render_y <= 8'd0;
        end
        else begin
            case (raymarch_state)
                INIT: begin
                    if (ray_valid) begin
                        raymarch_state <= UPDATE_P;
                    end
                    ray_t <= ray_t_min;
                    step_cnt <= 16'sd0;
                    ray_in_valid <= 1'b0;
                    fb_we <= 1'b0;
                end

                UPDATE_P: begin
                    raymarch_state <= CHECK_STEP;
                    pos_x <= origin_x + 16'((32'(ray_dir_x) * 32'(ray_t)) >>> 8);
                    pos_y <= origin_y + 16'((32'(ray_dir_y) * 32'(ray_t)) >>> 8);
                    pos_z <= origin_z + 16'((32'(ray_dir_z) * 32'(ray_t)) >>> 8);
                    sdf_in_valid <= 1'b1;
                end

                CHECK_STEP: begin
                    sdf_in_valid <= 1'b0;
                    if (sdf_valid) begin
                        if (sdf_dist < 16'sh0005) begin
                            raymarch_state <= SHADE;
                            hit <= 1'b1;
                            is_carve_reg <= hit_carve;
                            blend_w_reg <= blend_w;
                        end
                        else if (ray_t > ray_t_max || step_cnt > 16'sd24) begin
                            raymarch_state <= SHADE;
                            hit <= 1'b0;
                        end
                        else begin
                            raymarch_state <= UPDATE_P;
                            ray_t <= ray_t + sdf_dist;
                            step_cnt <= step_cnt + 16'sd1;
                        end
                    end
                end
                SHADE: begin
                    raymarch_state <= INIT;
                    if (hit)
                        fb_din <= shaded_output;
                    else
                        fb_din <= 12'h112;
                    fb_we <= 1'b1;
                    fb_addr <= ({1'b0, render_y, 8'b0} + {3'b0, render_y, 6'b0}) + {8'b0, render_x};
                    ray_in_valid <= 1'b1;
                    if (render_x == 9'd319) begin
                        render_x <= 9'd0;
                        render_y <= (render_y == 8'd239) ? 8'd0 : render_y + 8'd1;
                    end else begin
                        render_x <= render_x + 9'd1;
                    end
                end
                default: begin
                    raymarch_state <= INIT;
                    ray_t          <= ray_t_min;
                    step_cnt       <= 16'sd0;
                    pos_x          <= origin_x;
                    pos_y          <= origin_y;
                    pos_z          <= origin_z;
                    hit            <= 1'b0;
                    sdf_in_valid   <= 1'b0;
                    ray_in_valid   <= 1'b0;
                    fb_we          <= 1'b0;
                end
            endcase
        end
    end

    logic signed [15:0] blend_carve_z;

    always_comb begin
        norm_sphere_x = pos_x;
        norm_sphere_y = pos_y;
        norm_sphere_z = pos_z;
        norm_carve_x = 16'((32'(carve_x - pos_x) * 32'(inv_carve_radius)) >>> 8);
        norm_carve_y = 16'((32'(carve_y - pos_y) * 32'(inv_carve_radius)) >>> 8);
        norm_carve_z = 16'((32'(carve_z - pos_z) * 32'(inv_carve_radius)) >>> 8);

        blend_carve_z = (norm_carve_z > 0 && blend_w_reg < 9'd256) ? -norm_carve_z : norm_carve_z;

        norm_x = 16'((32'(norm_sphere_x) * (256 - blend_w_reg) + 32'(norm_carve_x) * blend_w_reg) >>> 8);
        norm_y = 16'((32'(norm_sphere_y) * (256 - blend_w_reg) + 32'(norm_carve_y) * blend_w_reg) >>> 8);
        norm_z = 16'((32'(norm_sphere_z) * (256 - blend_w_reg) + 32'(blend_carve_z) * blend_w_reg) >>> 8);
    end

    ray_gen ray_gen_inst (
        .clk(clk),
        .reset(reset),
        .drawX({1'b0, render_x}),
        .drawY({2'b0, render_y}),
        .in_valid(ray_in_valid),
        .ray_dir_x(ray_dir_x),
        .ray_dir_y(ray_dir_y),
        .ray_dir_z(ray_dir_z),
        .ray_valid(ray_valid)
    );

    sdf_scene sdf_scene_inst (
        .clk(clk),
        .reset(reset),
        .pos_x(pos_x),
        .pos_y(pos_y),
        .pos_z(pos_z),
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
        .blend_w(blend_w)
    );

    sphere_shader sphere_shader_inst (
        .norm_x(norm_x),
        .norm_y(norm_y),
        .norm_z(norm_z),
        .shaded_output(shaded_output)
    );

endmodule