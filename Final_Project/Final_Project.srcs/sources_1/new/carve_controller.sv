`timescale 1ns / 1ps

/*

    Mouse bit/byte mappings:
    mouse_kbd_stick_data:
    [7:0]   = X Displacement
    [15:8]  = Y Displacement
    [16]    = Left Button
    [17]    = Right Button
    [18]    = Middle Button
    [19:25] = Unused
    [24]    = Is Mouse (1 if mouse, 0 if gamepad)
    [25]    = Strobe


    Gamepad bit/byte mappings:
    mouse_kbd_stick_data:
    [7:0]   = Left Stick X
    [15:8]  = Left Stick Y
    [23:16] = Right Stick X
    [31:24] = Right Stick Y

    gamepad_button_data:
    [7:0]   = Left Trigger
    [15:8]  = Right Trigger
    [19:6]  = D-Pad, 8 means empty
    [20]    = Square Button
    [21]    = Cross Button
    [22]    = Circle Button
    [23]    = Triangle Button
    [24]    = Left Shoulder
    [25]    = Right Shoulder
    [26]    = Left Stick Button
    [27]    = Right Stick Button
    [28]    = Share Button
    [29]    = Options Button
    [30]    = Is Gamepad (1 if gamepad, 0 if mouse)
    [31]    = Strobe

*/

module carve_controller(
    input logic clk,
    input logic reset, // Async high reset
    input logic frame_tick,
    input logic [63:0] usb_data_in,

    output logic signed [15:0] carve_x,
    output logic signed [15:0] carve_y,
    output logic signed [15:0] carve_z,
    output logic signed [15:0] light_dir_x,
    output logic signed [15:0] light_dir_y,
    output logic signed [15:0] light_dir_z,
    output logic signed [15:0] half_x,
    output logic signed [15:0] half_y,
    output logic signed [15:0] half_z,
    output logic signed [15:0] carve_radius,
    output logic signed [15:0] inv_carve_radius,
    output logic               carve_en,
    output logic        [1:0]  sphere_material,
    output logic        [1:0]  control_mode
);

    logic signed [15:0] step_size = 16'sh0010;

    logic [63:0] usb_data;
    logic [31:0] mouse_kbd_stick_data;
    assign mouse_kbd_stick_data = usb_data[31:0];
    logic [31:0] gamepad_button_data;
    assign gamepad_button_data = usb_data[63:32];

    logic tick_dly;
    logic tick_pulse;
    assign tick_pulse = frame_tick && !tick_dly;

    logic is_mouse;
    logic is_gamepad;
    logic mouse_strobe_dly;
    logic gamepad_strobe_dly;
    logic mouse_packet_pulse;
    logic gamepad_packet_pulse;

    assign is_gamepad = gamepad_button_data[30];
    assign is_mouse = mouse_kbd_stick_data[24];
    assign gamepad_packet_pulse = is_gamepad && (gamepad_button_data[31] != gamepad_strobe_dly);
    assign mouse_packet_pulse = is_mouse && (mouse_kbd_stick_data[25] != mouse_strobe_dly);

    logic [7:0] keycode;
    assign keycode = mouse_kbd_stick_data[7:0];

    logic signed [15:0] delta_x, delta_y;
    logic signed [15:0] delta2_x, delta2_y;

    logic left_btn, right_btn, middle_btn, prev_left_btn;
    assign left_btn   = mouse_kbd_stick_data[16];
    assign right_btn  = mouse_kbd_stick_data[17];
    assign middle_btn = mouse_kbd_stick_data[18];

    logic square_button, cross_button, triangle_button, circle_button, prev_square_button, prev_cross_button, prev_triangle_button;
    assign square_button   = gamepad_button_data[20];
    assign cross_button    = gamepad_button_data[21];
    assign circle_button   = gamepad_button_data[22];
    assign triangle_button = gamepad_button_data[23];

    logic l_shoulder_button, r_shoulder_button, prev_l_shoulder_button, prev_r_shoulder_button;
    assign l_shoulder_button = gamepad_button_data[24];
    assign r_shoulder_button = gamepad_button_data[25];

    // Signed-magnitude stick calibration
    logic signed [15:0] diff_ls_x, diff_ls_y, diff_rs_x, diff_rs_y;
    logic signed [15:0] mag_ls_x, mag_ls_y, mag_rs_x, mag_rs_y;
    logic signed [15:0] dz_mag_ls_x, dz_mag_ls_y, dz_mag_rs_x, dz_mag_rs_y;
    logic signed [15:0] step_ls_x, step_ls_y, step_rs_x, step_rs_y;
    logic signed [15:0] deadzone_threshold = 16'sh0010;

    // Horizontal Rotation
    logic [7:0] theta_light;
    // Elevation
    logic signed [7:0] phi_light;
    logic signed [15:0] sin_theta_light, cos_theta_light, sin_phi_light, cos_phi_light;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            light_dir_x <= 16'sh0000;
            light_dir_y <= 16'sh0000;
            light_dir_z <= 16'sh0000;
            half_x <= 16'sh0000;
            half_y <= 16'sh0000;
            half_z <= 16'sh0000;
        end else begin
            light_dir_x <= 16'((32'(cos_phi_light) * 32'(sin_theta_light)) >>> 8);
            light_dir_y <= sin_phi_light;
            light_dir_z <= -16'((32'(cos_phi_light) * 32'(cos_theta_light)) >>> 8);

            half_x <= 16'((32'((light_dir_x + 16'sh0000) >>> 1) * 32'(16'sh011A)) >>> 8);
            half_y <= 16'((32'((light_dir_y + 16'sh0000) >>> 1) * 32'(16'sh011A)) >>> 8);
            half_z <= 16'((32'((light_dir_z - 16'sh0100) >>> 1) * 32'(16'sh011A)) >>> 8);
        end
    end

    always_comb begin
        delta_x = 16'sh0000;
        delta_y = 16'sh0000;
        delta2_x = 16'sh0000;
        delta2_y = 16'sh0000;

        diff_ls_x = $signed({1'b0, mouse_kbd_stick_data[7:0]}) - 16'sd128;
        diff_ls_y = $signed({1'b0, mouse_kbd_stick_data[15:8]}) - 16'sd128;
        diff_rs_x = $signed({1'b0, mouse_kbd_stick_data[23:16]}) - 16'sd128;
        diff_rs_y = $signed({1'b0, mouse_kbd_stick_data[31:24]}) - 16'sd128;

        mag_ls_x = (diff_ls_x < 16'sd0) ? (-diff_ls_x) : diff_ls_x;
        mag_ls_y = (diff_ls_y < 16'sd0) ? (-diff_ls_y) : diff_ls_y;
        mag_rs_x = (diff_rs_x < 16'sd0) ? (-diff_rs_x) : diff_rs_x;
        mag_rs_y = (diff_rs_y < 16'sd0) ? (-diff_rs_y) : diff_rs_y;

        dz_mag_ls_x = (mag_ls_x > deadzone_threshold) ? (mag_ls_x - deadzone_threshold) : 16'sd0;
        dz_mag_ls_y = (mag_ls_y > deadzone_threshold) ? (mag_ls_y - deadzone_threshold) : 16'sd0;
        dz_mag_rs_x = (mag_rs_x > deadzone_threshold) ? (mag_rs_x - deadzone_threshold) : 16'sd0;
        dz_mag_rs_y = (mag_rs_y > deadzone_threshold) ? (mag_rs_y - deadzone_threshold) : 16'sd0;

        step_ls_x = dz_mag_ls_x >> 6;
        step_ls_y = dz_mag_ls_y >> 6;
        step_rs_x = dz_mag_rs_x >> 6;
        step_rs_y = dz_mag_rs_y >> 6;

        if (is_gamepad) begin
            delta_x  = (diff_ls_x < 16'sd0) ? (-step_ls_x) : step_ls_x;
            delta_y  = (diff_ls_y < 16'sd0) ? (-step_ls_y) : step_ls_y;
            delta2_x = (diff_rs_x < 16'sd0) ? (-step_rs_x) : step_rs_x;
            delta2_y = (diff_rs_y < 16'sd0) ? (-step_rs_y) : step_rs_y;
        end else if (is_mouse) begin
            delta_x = { {8{mouse_kbd_stick_data[7]}}, mouse_kbd_stick_data[7:0] };
            delta_y = { {8{mouse_kbd_stick_data[15]}}, mouse_kbd_stick_data[15:8] };
        end
    end
    

    // 256-entry reciprocal lookup table: 65536 / R (in Q8.8)
    logic signed [15:0] inv_rom [0:255];
    initial begin
        inv_rom[0] = 16'sh7FFF;
        inv_rom[1] = 16'sh7FFF;
        inv_rom[2] = 16'sh7FFF;
        for (int i = 3; i < 256; i++) begin
            inv_rom[i] = 16'(32'd65536 / i);
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            carve_x <= 16'sh005A;
            carve_y <= 16'sh005A;
            carve_z <= 16'shFF26;
            carve_radius <= 16'sh005A;
            sphere_material <= 2'b00;
            control_mode <= 2'b00;
            carve_en <= 1'b1;
            prev_left_btn <= 1'b0;
            prev_triangle_button <= 1'b0;
            prev_l_shoulder_button <= 1'b0;
            prev_r_shoulder_button <= 1'b0;
            prev_square_button <= 1'b0;
            prev_cross_button <= 1'b0;
            theta_light <= 8'd32; // ~45 degrees
            phi_light   <= 8'd20; // ~28 degrees elevation
        end else if (is_gamepad) begin
            if (tick_pulse) begin
                prev_square_button <= square_button;
                prev_cross_button <= cross_button;
                prev_triangle_button <= triangle_button;
                prev_l_shoulder_button <= l_shoulder_button;
                prev_r_shoulder_button <= r_shoulder_button;
                // Reset Carve Position and Radius
                if (circle_button) begin// Rising Edge
                    carve_x <= 16'sh005A;
                    carve_y <= 16'sh005A;
                    carve_z <= 16'shFF26;
                    carve_radius <= 16'sh005A;
                    carve_en <= 1'b1;
                    sphere_material <= 2'b00;
                    control_mode <= 2'b00;
                    theta_light <= 8'd32; // ~45 degrees
                    phi_light   <= 8'd20; // ~28 degrees elevation
                end else begin
                    if (square_button && !prev_square_button) // Rising Edge
                        control_mode <= (control_mode >= 2'b10) ? 2'b00 : control_mode + 2'b01;

                    if (control_mode == 2'b00) begin
                        if (cross_button && !prev_cross_button) // Rising Edge
                            carve_en <= ~carve_en; // Placeholder

                        if (triangle_button && !prev_triangle_button) // Rising Edge
                            carve_en <= ~carve_en;

                        if ((carve_radius + delta2_x) >= 16'sh001A && (carve_radius + delta2_x) <= 16'sh00DA) // Bounding for inv
                            carve_radius <= carve_radius + delta2_x;

                        if ((carve_x + delta_x) >= -16'sh015A && (carve_x + delta_x) <= 16'sh015A) // Bounding for x
                            carve_x <= carve_x + delta_x;

                        if ((carve_y - delta_y) >= -16'sh015A && (carve_y - delta_y) <= 16'sh015A) // Bounding for y
                            carve_y <= carve_y - delta_y;

                        if ((carve_z - delta2_y) >= -16'sh015A && (carve_z - delta2_y) <= 16'sh015A) // Bounding for z
                            carve_z <= carve_z - delta2_y;
                    end else if (control_mode == 2'b01) begin
                        theta_light <= theta_light + delta_x;
                        phi_light <= phi_light + delta_y;
                    end
                        // Change Sphere Material
                        if (l_shoulder_button && !prev_l_shoulder_button) // Rising Edge
                            sphere_material <= sphere_material - 2'b01;
                        else if (r_shoulder_button && !prev_r_shoulder_button) // Rising Edge
                            sphere_material <= sphere_material + 2'b01;

                end
            end
        end else if (is_mouse) begin
            if (mouse_packet_pulse) begin
                prev_left_btn <= left_btn;

                if (left_btn && !prev_left_btn) // Rising Edge
                    carve_en <= ~carve_en;

                if (right_btn)
                    carve_z <= carve_z + delta_y;

                else if (middle_btn) begin
                    if ((carve_radius - delta_y) >= 16'sh001A && (carve_radius - delta_y) <= 16'sh00DA) // Bounding for inv
                        carve_radius <= carve_radius - delta_y;
                end

                else begin
                    carve_x <= carve_x + delta_x;
                    carve_y <= carve_y - delta_y;
                end
            end
        end else if (tick_pulse) begin
            case (keycode)
                8'h1A: carve_y <= carve_y + step_size; // W
                8'h16: carve_y <= carve_y - step_size; // S
                8'h07: carve_x <= carve_x + step_size; // D
                8'h04: carve_x <= carve_x - step_size; // A
                8'h08: carve_z <= carve_z + step_size; // E
                8'h14: carve_z <= carve_z - step_size; // Q
                8'h15: begin // R (increase radius)
                    if (carve_radius < 16'sh00DA)
                        carve_radius <= carve_radius + step_size;
                end
                8'h09: begin // F (decrease radius)
                    if (carve_radius > 16'sh001A)
                        carve_radius <= carve_radius - step_size;
                end
                8'h2C: carve_en <= ~carve_en; // Space
                default: begin end
            endcase
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            inv_carve_radius <= 16'sh02D8;
        end else begin
            inv_carve_radius <= inv_rom[carve_radius[7:0]];
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            tick_dly <= 1'b0;
        end else begin
            tick_dly <= frame_tick;
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            mouse_strobe_dly <= 1'b0;
        end else begin
            mouse_strobe_dly <= mouse_kbd_stick_data[25];
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            gamepad_strobe_dly <= 1'b0;
        end else begin
            gamepad_strobe_dly <= gamepad_button_data[31];
        end
    end

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            usb_data <= 64'b0;
        end else begin
            usb_data <= usb_data_in;
        end
    end

    lut_sincos sincos_inst (
        .theta(theta_light),
        .sin_out(sin_theta_light),
        .cos_out(cos_theta_light)
    );

    lut_sincos sincos_inst2 (
        .theta(phi_light),
        .sin_out(sin_phi_light),
        .cos_out(cos_phi_light)
    );

endmodule
