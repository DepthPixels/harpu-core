# AI Agent Session Audit Log

This file maintains an ongoing record of file changes, terminal commands executed, architectural decisions made, and debugging notes across agent threads for later reference during ECE 385 final report preparation.

---

## Session: 2026-11-08 to 2026-11-10 (Project Inception & Week 1 Setup)

### Summary of Actions
* **[AGENT]** Evaluated initial project proposal against Urbana board hardware specs (`XC7S50-CSGA324-1`) and ECE 385 grading rubric.
* **[AGENT]** Converted project architecture to an implicit 3D SDF raymarcher with dynamic CSG carving, 8-droplet PBD fluid simulation, and procedural Gyroid caverns.
* **[AGENT]** Parameterized internal resolution ($320 \times 180$ / $320 \times 240$ upscaled to $640 \times 480$ @ 60 Hz) to guarantee locked 60 FPS timing within BRAM budget.
* **[AGENT]** Formatted, verified, and exported official project proposal documents (`.md`, `.html`, `.pdf`).
* **[AGENT]** Organized project directory structure (`Documentation/`, `Documentation/AI_Documentation/`).
* **[AGENT]** Initialized local Git repository on branch `main`, verified `.gitignore` against Vivado and Vitis build paths, and linked remote to `https://github.com/DepthPixels/harpu-core.git`.
* **[AGENT]** Codified agent guidelines (`agent_rules.md`) and Week 1 progress tracking (`agents_week_1.md`).

### Files Created / Modified
* **[AGENT]** `Documentation/ECE385_Final_Project_Proposal.md` — Complete ECE 385 project proposal.
* **[AGENT]** `Documentation/ECE385_Final_Project_Proposal.html` — Print-styled HTML proposal.
* **[AGENT]** `Documentation/ECE385_Final_Project_Proposal.pdf` — Compiled PDF proposal.
* **[AGENT]** `.gitignore` — Tailored ignore rules for Vivado and Vitis.
* **[AGENT]** `Documentation/agent_rules.md` — AI agent rules.
* **[AGENT]** `Documentation/agents_week_1.md` — Week 1 progress keeping and milestone checklist.
* **[AGENT]** `Documentation/AI_Documentation/session_log.md` — Initial audit log.

---

## Session: 2026-11-10 (MicroBlaze Block Design & Video Path Audit)

### Summary of Actions
* **[USER]** Assembled baseline MicroBlaze Block Design (`mb_harpu.bd`) with MAX3421E SPI, AXI Timer, UART, and GPIO.
* **[USER]** Added Urbana board constraints (`mb_harpu.xdc`) and imported lab 6 wrapper files (`harpu_top.sv`, `color_mapper.sv`, `VGA_controller.sv`, `hex_driver.sv`).
* **[AGENT]** Inspected Vivado project source tree, constraints, and block design.
* **[AGENT]** Cross-referenced BD architecture and peripheral parameters with ECE 385 USB documentation (`IUSB.pdf`).
* **[AGENT]** Audited top-level HDL wrapper (`harpu_top.sv`), `color_mapper.sv`, `VGA_controller.sv`, and IP configurations (`clk_wiz_0`, `hdmi_tx_0`).

### Bugs & Architectural Findings Identified
1. **[AGENT] `color_mapper.sv` Latch & Undefined State:** Missing default assignment in `always_comb`, inferring 12 latches and causing undefined state in simulation.
2. **[AGENT] Block Design Peripheral Naming Mismatch:** `axi_timer_0` vs `timer_usb_axi` and `axi_quad_spi_0` vs `spi_usb` noted for Vitis `xparameters.h` compatibility.
3. **[AGENT] Simulation Testbench Absence:** Identified lack of testbench in `sim_1`.

---

## Session: 2026-11-15 to 2026-11-16 (Hardware Verification & Step 3 Implementation)

### Summary of Actions
* **[USER]** Successfully synthesized, implemented, and programmed Urbana board bitstream:
  * Verified rock-solid $640 \times 480$ @ 60 Hz HDMI output on physical monitor.
  * Verified MicroBlaze USB keyboard input via MAX3421E SPI and real-time color changes on keypress.
* **[USER]** Created BRAM framebuffer IP (`blk_mem_framebuffer`) with depth 76,800 and 12-bit RGB444 width.
* **[AGENT]** Created directory junction `F:\ECE 385 Final Project` $\to$ `F:\ECE_385_Final_Project` for toolchain compatibility.
* **[AGENT]** Audited `memory.sv`, `color_mapper.sv`, and `harpu_top.sv`. Identified port direction errors on `dout_b`, address width truncation, and clock domain crossing.
* **[AGENT]** Rewrote `memory.sv` (with 17-bit addresses, 12-bit data, output `dout_b`, and separate 100MHz write / 25MHz read clocks).
* **[AGENT]** Created `fb_test_writer.sv` with a 4-quadrant test pattern and updated `color_mapper.sv` to implement $2\times$ upscaling.
* **[USER]** Verified framebuffer test on physical monitor; observed vertical glitch streaks in Quadrant 2 color bars.
* **[AGENT]** Diagnosed setup timing violation at 100 MHz caused by combinational `/ 20` non-power-of-2 divider and unregistered write bus.
* **[AGENT]** Rewrote `fb_test_writer.sv` using a 0..19 sub-counter and fully registered output pipeline.
* **[USER]** Re-programmed board; verified 100% glitch-free, razor-sharp 4-quadrant framebuffer display.
* **[USER]** Reported resource utilization: LUT 8.78%, FF 4.06%, BRAM 56.67%, DSP 2.50%.
* **[AGENT]** Designed 5-stage pipelined architecture for Stage 1 (`ray_gen.sv`).
* **[USER]** Implemented `ray_gen.sv`.
* **[AGENT]** Generated 64-entry $Q0.16$ inverse square root ROM (`lut_inv_sqrt.sv`) and automated self-checking testbench (`ray_gen_tb.sv`).
* **[AGENT]** Diagnosed 16-bit intermediate expression truncation bug under IEEE 1800-2017 shift rules causing all tests to report `dz = 0xFFFF`.
* **[USER]** Applied 32-bit intermediate product casts in `ray_gen.sv`.
* **[USER]** Reran behavioral simulation: **All 7 automated unit-norm tests PASSED** with $<0.8\%$ error.
* **[USER]** Implemented non-restoring square root core (`math_sqrt.sv`) and sphere distance ALU (`sdf_sphere.sv`).
* **[AGENT]** Mathematically verified bit-accuracy of `math_sqrt.sv` in Python simulation (100% exact roots).
* **[USER]** Created initial FSM in `raymarch_core.sv` and skeleton for `sphere_shader.sv`.
* **[AGENT]** Audited `raymarch_core.sv` and `sphere_shader.sv`:
  * Identified that `render_x` and `render_y` were incrementing on every clock cycle instead of only inside `SHADE`.
  * Identified typo `dot` instead of `dot_product` and operator precedence bug `diffuse << 3 + diffuse << 2` in `sphere_shader.sv`.
  * Identified unused `.clk, .reset` ports in `sphere_shader_inst`.
* **[USER]** Fixed `raymarch_core.sv`: moved `render_x`/`render_y` increment into `SHADE`, removed `shaded_output` multi-driver assignment, and removed unused `.clk`/`.reset` from `sphere_shader_inst`.
* **[USER]** Fixed `sphere_shader.sv` (`dot_product` name & shift operator parentheses) and updated `raymarch_core.sv` (startup `ray_in_valid <= 1'b1;` and merged `CHECK_STEP` distance evaluation).
* **[USER]** Integrated `raymarch_core` into `harpu_top.sv`, synthesized, implemented, and programmed Urbana board bitstream.
* **[USER]** Successfully rendered first real-time 3D raymarched sphere on physical HDMI monitor with Lambertian diffuse shading!
* **[AGENT]** Analyzed display photo (`media_1794814484428_3201f710.jpg`):
  * Verified 3D lighting, depth, and sphere curvature functioning on hardware.
  * Explained pixelation as natural $2\times$ upscaling from $320 \times 240$ BRAM framebuffer.
  * Diagnosed horizontal elongation as 16:9 monitor stretch on a 4:3 ($640 \times 480$) video signal.
  * Diagnosed silhouette unevenness as grazing-ray step count limits (24 max steps).
* **[USER]** Fixed `sphere_shader.sv`: added diffuse clamp for `dot_product >= 16'sh0100` and implemented 5-bit `r_sum, g_sum, b_sum` saturation adders.
* **[USER]** Tested Stage 2.5A bitstream on monitor: observed bright white specular highlight, but noted a weird green band near the highlight and secondary brightness spots (e.g., at dead center).
* **[AGENT]** Diagnosed root causes:
  1. Green Band: In `sphere_shader.sv`, `dot_product[7:4]` equals 15 in the band $[0x00F0, 0x00FF]$. `r_base = ambient + diffuse = 1 + 15 = 16` overflows the 4-bit `r_base` to 0, completely dropping the red channel and leaving pure green `{0, 3, 0}`.
  2. Dead-Center Brightness: Blinn-Phong exponent of 8 is too broad; at dead center where the normal faces the camera, $(\vec{N} \cdot \vec{H})^8 = (0.901)^8 \approx 42\%$, causing a 6/15 white haze. Stepping to exponent 32 drops dead-center specular to zero and focuses the glint into a single sharp highlight.
* **[USER]** Tested updated `sphere_shader.sv`: verified green banding is gone, but noted specular shape is irregular/jagged and diffuse highlight area saturates into a solid blocky red patch.
* **[AGENT]** Diagnosed root causes:
  1. Blocky Red Patch: Red was permitted to saturate to 15 from diffuse alone ($1 + 14 = 15$), causing a massive flat region of identical color `{F, 3, 0}` across the top cap. Scaled diffuse red to peak at 12 so smooth color gradients are preserved, reserving 13-15 for the white specular glint.
  2. Jagged Specular Shape: Power-32 exponent ($s_{32}$) hyper-amplifies subtle $1\%$ raymarch step endpoint tolerances ($|\vec{p}| \in [1.000, 1.019]$) into $50\%$ brightness cliffs. Replaced with power-16 plus threshold subtraction ($s_{16} - 64$), which completely cuts out dead-center haze while restoring a smooth, circular specular highlight.
* **[USER]** Reminded agent to adhere strictly to the "No Large Code Dumps" rule in `agent_rules.md`.
* **[USER]** Updated `sphere_shader.sv` with power-16 specular shift logic and proportional diffuse multipliers.
* **[USER]** Applied `(diffuse == 4'd15) ? 4'd15 : (ambient + diffuse);` in `sphere_shader.sv`.
* **[USER]** Confirmed bitstream on monitor: green band is 100% eliminated, smooth natural gradient restored, and specular highlight verified.
* **[USER]** Selected Option A: Proceeding to implement Dynamic CSG Carving ALU (`sdf_scene.sv`).
* **[USER]** Corrected `carve_controller.sv`: added missing comma, fixed port bit-widths to signed 16-bit, mapped USB HID scancodes, corrected WASD axes, and added `tick_dly` edge detector.
* **[USER]** Confirmed tearing fix and requested Stage 2.5B: Finite-Difference Normal Engine.
* **[USER]** Implemented Analytical CSG Normal logic: added `hit_carve` output in `sdf_scene.sv`, simplified `raymarch_core.sv` FSM back to 4 states (`INIT`, `UPDATE_P`, `CHECK_STEP`, `SHADE`), and added closed-form normal vector calculation.
* **[AGENT]** Audited `sdf_scene.sv` and `raymarch_core.sv`:
  1. Caught syntax error in `sdf_scene.sv`: missing comma after `out_valid` on line 19.
  2. Caught 1-cycle pipeline sampling race on `hit_carve`: `hit_carve` is combinationally derived from square root outputs that expire when `sdf_valid` drops; recommended registering `is_carve_reg <= hit_carve` inside `CHECK_STEP` when `sdf_valid` is high so `always_comb` normal evaluation in `SHADE` reads stable hit identity.
  3. Verified closed-form concave normal arithmetic: $(\vec{c}_B - \vec{p}) \times 2.85$ correctly generates inward-facing unit normals for the carved bowl.
* **[USER]** Fixed comma in `sdf_scene.sv` and implemented `is_carve_reg` latching in `raymarch_core.sv`.
* **[AGENT]** Verified full Analytical CSG Normal pipeline:
  * `hit_carve` is cleanly registered into `is_carve_reg` on hit detection while `sdf_valid` is high.
  * Inward bowl normals and outward sphere normals are 100% stable during `SHADE`.
  * Ready for synthesis, bitstream generation, and hardware verification on Urbana board.

* **[USER]** Tested bitstream on hardware (`media_1794827857702_df2a48f6.jpg`): verified 100% of glitter noise is gone and 11 FPS is solid, but identified:
  1. Specular highlight in carved hole persists even on the dark/unlit side of the sphere.
  2. Specular highlight intensity and size explodes as hole radius expands.
  3. Borders of the crater are high contrast / dark.
* **[AGENT]** Diagnosed root causes:
  1. Specular Dark-Side Bleed: `sphere_shader.sv` evaluated specular solely on `half_dot_product[15] == 0` without gating on diffuse illumination (`dot_product > 0`), causing concave crater surfaces facing the camera to reflect specular even when completely self-shadowed.
  2. Hole Radius Expansion: In `raymarch_core.sv`, the crater normal was scaled by hardcoded constant `16'sh02DA` ($1/0.35$). As radius expanded to $0.66$, normal length reached $1.90$, blowing up $(\vec{N} \cdot \vec{H})^8$ by $170\times$ and saturating the crater into a giant white spot.
  3. High Contrast Borders: Crater overhang slopes downward ($N_y < 0$), falling into shadow under overhead light ($L_y = +0.60$); low ambient (`4'd1`) produced pitch black juxtaposed against saturated white specular.
* **[USER]** Requested Option B: 256-entry reciprocal lookup table for `inv_carve_radius` and confirmed edits to `sphere_shader.sv`, `raymarch_core.sv`, and `harpu_top.sv`.
* **[AGENT]** Audited `sphere_shader.sv`, `raymarch_core.sv`, and `harpu_top.sv`:
  * Verified `sphere_shader.sv` gates specular with `if (dot_product > 0 && half_dot_product[15] == 0)`.
  * Verified `raymarch_core.sv` scales crater normal dynamically by `inv_carve_radius`.
  * Verified `harpu_top.sv` interconnects `inv_carve_radius` across `carve_controller` and `raymarch_core`.
* **[AGENT]** Updated `carve_controller.sv` with Option B:
  * Implemented 256-entry $Q8.8$ reciprocal lookup table (`inv_rom[0:255]`) precomputed as $65536 / R$.
  * Added safety clamping on radius controls: $R \in [16\text{'sh001A}, 16\text{'sh00DA}]$ ($0.10$ to $0.85$).
  * Added registered `inv_carve_radius` output clocked at 100 MHz, eliminating division logic and ensuring zero timing delay during raymarching.

### Session Log Update (2026-11-16: Verification & Bevel/LUT Distortion Fixes)
* **[USER]**: Noticed circular distortion seam at screen center and problematic bevel lighting when carve moved closer or embedded inside sphere. Instructed verification of changes and implementation of `inv_lut` interpolation.
* **[AGENT]**: 
  * Verified and implemented linear interpolation in `lut_inv_sqrt.sv` and `ray_gen.sv` across entries using fractional bits `r3_S[3:0]`, completely eliminating the discrete concentric circular distortion seam.
  * Corrected `lutouta_next` naming and fixed missing parenthesis syntax error in `ray_gen.sv`.
  * Verified `sdf_scene.sv` crater rim blend: removed the discontinuous 64-count jump at $d_{\text{rel}} = 0$ by aligning `blend_w` to ramp continuously from 0 at $d_{\text{rel}} = 0$ to 256 at $d_{\text{rel}} = 16'sh0040$.
  * Fixed bevel normal cancellation in `raymarch_core.sv`: when cutter is embedded deeper than the surface ($c_z > p_z$), enforced forward-facing $Z$ on the bevel transition (`blend_carve_z = -norm_carve_z`) to prevent destructive cancellation with $\vec{n}_{\text{sphere}}$ and eliminate dark rim artifacts.
  * Cast `carve_y` and `carve_z` to `(int16_t)` in `sim/sim_main.cpp` for accurate negative coordinate reporting in SDL2 window title.
  * **[USER]**: Inquired whether restoring color bleeding into the bevel for shallow carves (more outside than inside) is more accurate due to lower slope gradient.
  * **[AGENT]**: Confirmed physical and visual accuracy of gentle bleed. Widened the crater transition zone in `sdf_scene.sv` from $d_{\text{rel}} \in [0, 64]$ to $[0, 128]$ (`blend_w = d_rel << 1`), allowing the bright sphere lighting and specular highlight to roll smoothly into shallow dents while preserving clean boundaries on embedded cuts with zero hardware DSP overhead.
