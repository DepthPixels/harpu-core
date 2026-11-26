# HARPU Post-Checkpoint AI Agent Session Audit Log

> **Context:** This log covers all AI agent sessions, discussions, debugging notes, and architectural developments following the completion of the **ECE 385 Midpoint Checkpoint (Nov 20, 2026)**.  
> **Previous Log:** For Week 1 and Week 2 history leading up to the checkpoint demo, refer to [session_log.md](file:///F:/ECE_385_Final_Project/Documentation/AI_Documentation/session_log.md).

---

## 1. Verified Baseline State at Checkpoint Completion

As of the Nov 20 Midpoint Checkpoint, HARPU is fully operational on physical AMD Spartan-7 (`XC7S50-CSGA324-1`) Urbana hardware:

* **16-Ray Interleaved Wavefront Pipeline (`raymarch_core.sv`):** 
  * 16 simultaneous active raymarch contexts in flight on 100 MHz system fabric.
  * Measures **164 FPS internal frame throughput** on hardware 7-segment display (`hex_driver.sv`), rendering ~3.45 million raymarched pixels/sec.
* **Dynamic Interactive CSG Carving (`carve_controller.sv` & `sdf_scene.sv`):**
  * Real-time boolean subtraction ($d_{\text{carved}} = \max(d_{\text{scene}}, -d_{\text{cutter}})$) with analytical normal interpolation.
  * Integrated with reciprocal radius lookup ROM (`lut_inv_sqrt.sv`) and dynamic position registers.
* **USB HID DualSense Gamepad Integration (`carve_controller.sv` & `lw_usb_main.c`):**
  * PS5 DualSense controller (`0x054C:0x0CE6`) enumerated over MAX3421E USB Host controller.
  * Symmetric signed-magnitude analog stick calibration, frame-rate synchronized integration (60 Hz `tick_pulse`), hard coordinate bounding ($\pm 1.35$ in $Q8.8$).
  * Circle ($\bigcirc$) instant origin reset, Triangle ($\triangle$) carver preview toggle, and Square ($\square$) mode cycling.
* **3D Spherical Orbital Lighting (`lut_sincos.sv` & `sphere_shader.sv`):**
  * 256-entry $Q8.8$ sine/cosine ROM.
  * Right analog stick orbits directional sun light vector $\vec{L}$ and updates half-vector $\vec{H}$ dynamically in real time.
* **24-Bit TrueColor Framebuffer & HDMI Scanout (`color_mapper.sv` & `memory.sv`):**
  * Full 24-bit TrueColor ($8\text{b Red}, 8\text{b Green}, 8\text{b Blue}$) on-chip BRAM buffer.
  * Rock-solid $640 \times 480$ @ 60 Hz HDMI output via RealDigital `hdmi_tx` IP with zero screen tearing.
  * Color-inversion reticle overlay (`~dout_b`) displaying crosshair and tool radius boundary.
  * 4-preset material palette cycling on Left/Right Shoulder bumpers (L1/R1).
* **Post-Implementation Resource Utilization (Hardware Checkpoint):**
  * **LUT:** 7,039 / 32,600 (21.59%)
  * **LUTRAM:** 391 / 9,600 (4.07%)
  * **FF:** 6,906 / 65,200 (10.59%)
  * **BRAM (36Kb blocks):** 68 / 75 (90.67%) *(High utilization driven by 24-bit TrueColor framebuffer expansion)*
  * **DSP48E1:** 38 / 120 (31.67%)
  * **IO:** 42 / 210 (20.00%)
  * **BUFG:** 8 / 32 (25.00%)
  * **MMCM:** 2 / 5 (40.00%)
* **Timing Status (Active Engineering Target):**
  * **Timing closure is NOT yet achieved.**
  * **Worst Negative Slack (WNS):** -1.011 ns
  * **Total Negative Slack (TNS):** -58.318 ns
  * **Failing Endpoints:** 343 (out of 16,439 total endpoints)
  * *Note:* Despite the setup violation on the 100 MHz clock domain, the bitstream successfully runs on the physical Urbana board for demo purposes. Resolving this -1.011 ns critical path via additional pipeline register slicing is an active priority for post-checkpoint optimization.
* **Hardware Verification:**
  * Video capture archived in `docs/harpu_demo.gif`.

---

## 2. Active Session Log

### Session: 2026-11-21 (Post-Checkpoint Inception & State Reload)
* **[AGENT]** Inspected workspace and documentation following the completion of Week 1 and Week 2 milestones:
  1. Verified physical hardware achievements recorded in [agents_week_2.md](file:///F:/ECE_385_Final_Project/Documentation/agents_week_2.md), [README.md](file:///F:/ECE_385_Final_Project/README.md), and git commit history through commit `7b68856`.
  2. Confirmed that all mid-checkpoint requirements were exceeded: 164 FPS 16-ray wavefront pipeline, 24-bit TrueColor display, full DualSense USB HID integration, dynamic CSG carving, and orbital lighting.
* **[AGENT]** Initialized `Documentation/AI_Documentation/session_log_post_checkpoint.md` as the dedicated session and audit log for post-checkpoint development (Weeks 3 & 4) to prevent context truncation and keep records organized.
* **[AGENT]** Updated `Documentation/agent_rules.md` to reference `session_log_post_checkpoint.md` for active session recording.
* **[USER]** Provided verified post-implementation utilization and timing reports from Vivado:
  1. Corrected timing closure status: clarified that timing closure is **not yet achieved** (WNS = -1.011 ns, TNS = -58.318 ns, 343 failing endpoints).
  2. Logged official resource utilization: LUT 21.59%, FF 10.59%, DSP 31.67%, BRAM 90.67% (68/75 blocks).
* **[AGENT]** Updated documentation across `session_log_post_checkpoint.md` and `agents_week_2.md` to reflect the -1.011 ns WNS setup deficit and 90.67% BRAM usage as open engineering priorities for Week 3.

### Session: 2026-11-25 (Codebase Lines of Code Audit)
* **[USER]** Requested a comprehensive Lines of Code (LOC) audit across all project subsystems written to date.
* **[AGENT]** Executed source code audit across hardware RTL, simulation testbenches, Vitis MicroBlaze C drivers, physical constraints, and test utilities:
  * **Hardware RTL (SystemVerilog):** 2,468 lines across 15 core modules (`raymarch_core.sv`, `carve_controller.sv`, `sphere_shader.sv`, `harpu_top.sv`, `lut_sincos.sv`, `ray_gen.sv`, `sdf_scene.sv`, `fb_test_writer.sv`, `vec3_normalize.sv`, `VGA_controller.sv`, `hex_driver.sv`, `math_sqrt.sv`, `color_mapper.sv`, `memory.sv`, `lut_inv_sqrt.sv`).
  * **Simulation Testbenches:** 162 lines (`sim_top.sv`, `ray_gen_tb.sv`).
  * **Application C & USB Software:** 2,482 lines (`lw_usb_main.c`, `platform.c`, MAX3421E / HID / transfer driver library, excluding autogenerated BSP).
  * **Physical Constraints (XDC):** 85 lines (`mb_harpu.xdc`, `harpu_impl.xdc`).
  * **Python Test Scripts:** 165 lines (`scratch_test.py`).
  * **Grand Total Source Code:** **5,362 lines of code**.

### Session: 2026-11-24 (Complete Critical Path Timing Analysis)
* **[AGENT]** Extracted all 343 failing setup timing paths from the latest post-route checkpoint (`Final_Project/Final_Project.runs/impl_1/harpu_top_routed.dcp`) via Vivado batch mode (`report_timing -delay_type max -max_paths 500 -nworst 1 -slack_lesser_than 0.0`, exit code 0) and grouped them by source-to-destination register family via PowerShell parsing (exit code 0).
* **[AGENT]** Diagnosed that all 343 failing endpoints collapse into 10 path families driven by **5 distinct RTL root causes**:
  1. `carve_controller.sv` (`phi_light_reg` → `light_dir_z_reg`, **-1.011 ns**, 9 endpoints): Combinational `lut_sincos` (`MUXF8`) feeds directly into fabric `CARRY4` multiplication and negation in one cycle (16 logic levels).
  2. `sphere_shader.sv` (`st3_s4_reg` → `raymarch_core/fb_din_reg`, **-0.570 ns**, 22 endpoints): Unregistered final stage chains `s8_mult` (`DSP48E1`), specular/diffuse clamping, 4-material mux, RGB saturating adders, and `fb_din` mux (10 logic levels).
  3. `sdf_scene.sv` → `raymarch_core.sv` (`carve_sqrt_inst/q_pipe_reg` → `step_cnt_reg` / `ray_t_reg`, **-0.466 ns / -0.458 ns**, 257 endpoints = 75% of all failures): Unregistered `SDF_OUTPUT_EVAL` (CSG subtraction/max) feeds directly into `raymarch_core`'s hit comparator, 16-slot fanout, and `ray_t` adder (14 logic levels, 6.40 ns route). Verified `math_sqrt.sv` is 12 cycles (14-cycle round-trip vs 16-slot ring), leaving exactly **1 spare cycle** to register `sdf_scene` outputs without slot collision.
  4. `carve_controller.sv` (`usb_data_reg` → `carve_x/y/z/radius_reg`, **-0.450 ns to -0.061 ns**, 46 endpoints): Combinational stick deadzone/abs/shift logic chains directly into clamped coordinate adders (11–13 logic levels).
  5. `raymarch_core.sv` (`ray_t_reg` → `pos_z_reg` at **-0.223 ns**, 6 endpoints; `s1_norm_carve_y1` → `pipe_norm_y_reg` at **-0.106 ns**, 3 endpoints): External `+ origin_z` and `+ s1_norm_sphere_y` placed outside `>>> 8` prevent DSP48E1 post-adder (`C`-port) absorption, adding ~1.7–2.1 ns of fabric `CARRY4` + routing delay.
* **[AGENT]** No source files modified; presented full root-cause breakdown and zero-throughput-loss pipeline/DSP closure plan to user for approval.
* **[USER]** Directed agent to apply all 5 timing-closure fixes (explicitly delegating this as a simple, repetitive timing-closure task consisting of pipeline register slicing and algebraic DSP post-adder absorption).
* **[AGENT]** Applied simple, repetitive timing-closure register slicing and DSP post-adder rewrites across 4 RTL files at user's explicit request:
  * `Final_Project/Final_Project.srcs/sources_1/new/carve_controller.sv` — Registered `lut_sincos` outputs (`r_sin/cos_theta/phi_light`) before light vector multiply, and registered stick calibration outputs (`r_delta_x/y`, `r_delta2_x/y`, `r_mouse_packet_pulse`) before clamped coordinate updates.
  * `Final_Project/Final_Project.srcs/sources_1/new/sphere_shader.sv` — Inserted Stage 4 pipeline registers (`st4_s8`, `st4_dot`, `st4_spec_valid`) after `s8_mult` to decouple DSP from RGB clamping/packing (5-cycle shader latency).
  * `Final_Project/Final_Project.srcs/sources_1/new/sdf_scene.sv` — Registered `SDF_OUTPUT_EVAL` outputs (`dist_out`, `out_valid`, `ray_tag_out`, `hit_carve`, `d_diff`) and extended `pos_x/y/z` shift registers from 13 to 14 stages (`[0:13]`) using the 1 spare cycle in the 16-slot wavefront ring.
  * `Final_Project/Final_Project.srcs/sources_1/new/raymarch_core.sv` — Extended `pipe_we_r`/`pipe_addr_r`/`pipe_hit_r` from 4 to 5 stages to match `sphere_shader`, and rewrote `pos_x/y/z` and `norm_x/y/z` as `(((A <<< 8) + B * C) >>> 8)` so Vivado absorbs `+ origin_*` and `+ s1_norm_sphere_*` into DSP48E1 `C`-port post-adders.
* **[AGENT]** Verified RTL elaboration via Vivado batch mode (`synth_design -rtl` on `raymarch_core` and `carve_controller`, exit code 0): **0 Errors, 0 Critical Warnings**.
* **[USER]** Ran full Vivado synthesis and implementation; confirmed timing closure achieved.
* **[AGENT]** Verified post-implementation timing in `Final_Project/Final_Project.runs/impl_1/harpu_top_timing_summary_routed.rpt`: **WNS = +0.489 ns**, **TNS = 0.000 ns** (0 / 16,885 failing endpoints), **WHS = +0.050 ns**, **WPWS = +3.000 ns** — all timing constraints met (+1.500 ns WNS improvement).
* **[USER]** Designed and implemented `Final_Project/Final_Project.srcs/sources_1/new/vec3_normalize.sv` (4-cycle fixed-point 3D vector normalizer for tetrahedral gradients) and fixed all review findings.
* **[AGENT]** Reviewed `vec3_normalize.sv` across two passes (caught 16-bit multiply truncation, `$sqrt` synthesis issue, shift underflow/overflow, signed×unsigned promotion, and pipeline alignment). At user's explicit request, populated the 64-entry precomputed `Q0.16` `inv_sqrt_rom` table in `vec3_normalize.sv` (simple, repetitive numerical LUT generation).
* **[USER]** Rewrote `raymarch_core.sv` with 6-state per-slot tetrahedral normal + 1-tap Crevice AO wavefront FSM (`S_MARCH`, `S_NORM0..3`, `S_NORM_WAIT`, `S_AO`), integrated `ao_in` modulation into `sphere_shader.sv`, cleaned up unused ports/warnings in `sdf_scene.sv`, `carve_controller.sv`, and `harpu_top.sv`.
* **[AGENT]** Reviewed all modified RTL files and verified full RTL elaboration via Vivado batch mode (`synth_design -rtl` on `raymarch_core` + `vec3_normalize` + `sdf_scene` + `sphere_shader` and `carve_controller`, exit code 0): **0 Errors, 0 Critical Warnings**. Flagged missing `reset` on Section 3 `pipe_we_r`/`fb_we` and outdated `sim/sim_top.sv` port list before Verilator testing.
* **[USER]** Directed agent to update the Verilator testbench (`sim/sim_top.sv`, `sim/sim_main.cpp`, `sim/Makefile`) for 64-bit PS5 DualSense gamepad input (matching `carve_controller.sv`) and 24-bit TrueColor output while running Vivado synthesis & implementation.
* **[AGENT]** Updated Verilator simulation harness at user's explicit request:
  * `sim/sim_top.sv` — Upgraded to 64-bit `usb_data`, 24-bit `fb_din`, wired `light_dir_*`, `half_*`, `sphere_material`, and `control_mode`.
  * `sim/Makefile` — Added `lut_sincos.sv` and `vec3_normalize.sv` to `SRCS`.
  * `sim/sim_main.cpp` — Added `SDL_INIT_GAMECONTROLLER` hot-plug PS5 DualSense support packing sticks, triggers, 4-bit D-Pad hat, and face/shoulder buttons into the exact 64-bit `carve_controller.sv` format (with mouse/keyboard fallback) and direct 24-bit ARGB8888 framebuffer blit.
* **[AGENT]** Built Verilator simulator (`mingw32-make -C sim all`, exit code 0): `sim/obj_dir/Vsim_top.exe` compiled and linked cleanly with zero errors.
* **[USER]** Debugged and verified Step 1 (4-tap tetrahedral normals + 1-tap Crevice AO) in Verilator (`vec3_normalize.sv` signed squaring, `carve_controller.sv` `-light_dir_z`, `raymarch_core.sv` `NORM_EPS` tuning and 9-bit `{sdf_dist[5:0], 3'b000}` AO shift); implemented Step 2 (Gyroid-carved sphere, Rock Craggle, Excavator Ribbing + Bevel, and D-Pad Right `surface_mode` cycling) across `sdf_scene.sv`, `carve_controller.sv`, `raymarch_core.sv`, and `harpu_top.sv`.
* **[AGENT]** Diagnosed Step 1 visual artifacts (`carve_controller.sv` dropped `-` on `light_dir_z`, `raymarch_core.sv` 6-bit `sdf_dist[5:0] << 3` wrap-around, thin-shell `NORM_EPS` punch-through) and reviewed Step 2 RTL (caught missing unary `-` on CSG carve subtraction in `sdf_scene.sv` L310/L312 and missing `prev_dpad_right` reset). At user's explicit request, wired `surface_mode` into `sim/sim_top.sv` and `sim/sim_main.cpp` (simple, repetitive testbench plumbing) and rebuilt Verilator.
* **[USER]** Upgraded `sdf_scene.sv` to 2-octave FBM asteroid rock + `anim_phase` procedural animation (toggled via D-Pad Up in `carve_controller.sv`) and updated `sphere_shader.sv` color presets to Turquoise (`#70BDBB`) and Asteroid Grey.
* **[AGENT]** Reviewed 2-octave FBM and animation RTL (caught unregistered Octave 2 `r_sin/cos_x2/y2/z2`, `gx2/gy2/gz2` latch defaults, and ungated `anim_cnt` in `carve_controller.sv`). At user's explicit request, wired `anim_phase` into `sim/sim_top.sv` (simple testbench plumbing) and rebuilt Verilator (`mingw32-make -C sim all`).
