# HARPU: Week 2 Progress Tracker & Midpoint Checkpoint Milestones

> **NOTE FOR ALL AI ASSISTANTS:**  
> Review and comply with **`Documentation/agent_rules.md`**.  
> **Rule Reminder:** Your primary role is planning, architectural verification, and debugging. **Do NOT generate or modify source code unless explicitly commanded by the user.** Record all actions in `Documentation/AI_Documentation/session_log.md`.

---

## 1. Project Quick Reference

* **Project:** **HARPU** (Hardware-Accelerated Raymarching Processing Unit)
* **Target:** AMD/Xilinx Spartan-7 `XC7S50-CSGA324-1` (Urbana Board)
* **Repo:** `https://github.com/DepthPixels/harpu-core.git`
* **Team:** `pdeswal2` & `ac176`
* **Current Phase:** Week 2 — Interactive CSG Carving, USB HID Gamepad Integration, & Midpoint Checkpoint Deliverable
* **Critical Milestone:** **Friday, Nov 20 — Mid-Project Checkpoint Demo (5 pts)**

---

## 2. Comprehensive Implemented Features Checklist

### Status Legend
- [x] Completed & Verified on Hardware
- [/] In Progress / Refinement
- [ ] Planned / Post-Checkpoint

---

### A. Core Hardware Raymarching Processing Unit (RPU)
- [x] **Pipelined Sphere-Tracing Engine (`raymarch_core.sv`):**
  - 16 parallel round-robin raymarch slots executing on 100 MHz clock fabric.
  - Achieves **164 FPS internal frame throughput** (~3.45 million raymarched pixels/sec).
  - Feed threshold backpressure logic (`fifo_count <= 6`) fully synchronized with `ray_gen.sv` 6-cycle feedforward pipeline.
- [x] **Procedural Scene Distance Evaluator (`sdf_scene.sv`):**
  - Continuous evaluation of analytic 3D sphere geometry in $Q8.8$ fixed-point math.
  - Latency shortened to 13 cycles (14 cycles round-trip) to guarantee collision-free 16-slot scheduling.
  - Outputs signed distance, hit surface classification, and carving difference metrics (`d_diff`).
- [x] **Pipelined Surface Normal & Analytical Shading (`sphere_shader.sv`):**
  - Continuous analytical normal blend for smooth transitions between sphere surface and carved cavity.
  - 4-stage pipelined Blinn-Phong specular ($S = (N \cdot H)^8$) and Lambertian diffuse lighting ($D = N \cdot L$).
  - DSP48E1 parallel dot product multipliers (6 independent uncascaded DSPs).

---

### B. Interactive CSG Carving & Real-Time Physics
- [x] **Dynamic Constructive Solid Geometry (CSG) Subtraction:**
  - Real-time boolean carving: $d_{\text{carved}} = \max(d_{\text{scene}}, -d_{\text{cutter}})$.
  - Dynamic carving position ($X, Y, Z$), radius ($R$), and reciprocal radius lookup ROM (`inv_rom`).
- [x] **DualSense USB HID Gamepad Integration (`carve_controller.sv`):**
  - Full USB enumeration of Sony DualSense Wireless Controller (`0x054C:0x0CE6`) over MAX3421E host controller.
  - Streaming 64-byte reports: Channel 1 (`stick_data`) and Channel 2 (`btn_data`).
  - Symmetrical signed-magnitude stick calibration eliminating two's-complement arithmetic right-shift floor bias.
  - 60 Hz `tick_pulse` frame-rate integration rate with hard boundary coordinate clamping ($\pm 1.35$ in $Q8.8$).
- [x] **Controller Quality-of-Life & Tool Navigation:**
  - Instant origin reset on Circle ($\bigcirc$) button press.
  - Carver preview on/off toggle on Triangle ($\triangle$) button press.
  - Material palette cycling on Left/Right Shoulder bumpers (L1/R1).

---

### C. Visual Polish, Telemetry HUD & Display Pipeline
- [x] **Dual-Port BRAM Framebuffer & 2x Video Upscaler (`color_mapper.sv`):**
  - True dual-port on-chip memory: Port A write at 100 MHz, Port B read at 25.175 MHz.
  - Rock-solid $640 \times 480$ @ 60 Hz HDMI output via RealDigital `hdmi_tx` IP with 0 artifacts and 0 dropped pixels.
- [x] **Hardware Reticle & Cutter Overlay (Zero-BRAM Scanout):**
  - Precision 4-arm crosshair with center clearance gap tracking tool center $(X, Y)$.
  - Four corner ticks bounding the carving tool's physical radius ($R$).
  - Color-inversion scanout multiplexer (`~dout_b`) for universal contrast on light and dark surfaces.
- [x] **Dynamic Material Presets (4-Palette Wheel):**
  - *Preset 0:* Coral Bronze / Martian Clay (Warm terracotta with gold/white specular glint).
  - *Preset 1:* Emerald Jade / Cyan Core (Deep green with polished mint sheen).
  - *Preset 2:* Cobalt Blue / Titanium (Royal blue with electric cyan highlights).
  - *Preset 3:* Metallic Chrome / Platinum (Neutral high-contrast metal).
- [x] **Hardware 7-Segment Telemetry HUD (`hex_driver.sv`):**
  - `HexA`: Displays real-time internal frame rate (locked 164 FPS).
  - `HexB`: Displays active controller mode and coordinate telemetry.

---

### D. 3D Spherical Orbital Lighting Subsystem
- [x] **Trigonometric Sine/Cosine ROM (`lut_sincos.sv`):**
  - 256-entry $Q8.8$ sine table ($0 \dots 2\pi$ mapped to $0 \dots 255$, peak amplitudes normalized to $\pm 16\text{'sh0100}$).
  - Simultaneous sine and cosine extraction with zero DSP slice overhead.
- [x] **Fixed-Radius Orbital Sun / Dynamic Light Source:**
  - Longitude/Azimuth ($\theta$) and Latitude/Elevation ($\phi$) controlled via analog sticks.
  - Dynamically calculates unit light direction $\vec{L} = [\cos\phi\sin\theta, \; \sin\phi, \; -\cos\phi\cos\theta]$ and Blinn-Phong half-vector $\vec{H}$.
  - Live specular highlights and shadow terminators orbit the sphere in real time.
- [x] **Mode Multiplexing State Machine:**
  - Square ($\square$) button cycles active control mode:
    - Mode 0: Carver Tool
    - Mode 1: Orbital Light Source
    - Mode 2: Camera Viewport

---

## 3. Midpoint Checkpoint Deliverable Status (Nov 20)

* **Rubric Requirement:** Working live demo showing a 3D scene on an HDMI monitor where the user walks/looks with USB controls and carves geometry in real time.
* **Demonstrated Capabilities:**
  1. Real-time 3D implicit surface raymarching at **164 FPS** on physical Urbana hardware.
  2. Live USB HID PS5 DualSense controller streaming analog translation, depth, and radius controls over GPIO.
  3. Real-time CSG boolean carving with smooth analytical normal interpolation.
  4. Dynamic orbital directional lighting orbiting the 3D geometry in real time.
  5. 24-bit TrueColor display output (8 bits per channel) eliminating banding on smooth surfaces.
  6. Scanout reticle overlay, 4-material palette switcher, and hardware FPS display.
* **Midpoint Checkpoint Readiness:** **100% READY FOR DEMO**.

---

## 4. Post-Implementation Utilization & Timing Summary

### Resource Utilization (Spartan-7 `XC7S50-CSGA324-1`):
| Resource | Used | Available | Utilization % |
| :--- | :--- | :--- | :--- |
| **LUT** | 7,039 | 32,600 | 21.59% |
| **LUTRAM** | 391 | 9,600 | 4.07% |
| **FF** | 6,906 | 65,200 | 10.59% |
| **BRAM** | 68 | 75 | **90.67%** *(24-bit TrueColor buffer)* |
| **DSP48E1** | 38 | 120 | 31.67% |
| **IO** | 42 | 210 | 20.00% |
| **BUFG** | 8 | 32 | 25.00% |
| **MMCM** | 2 | 5 | 40.00% |

### Timing Summary:
* **Worst Negative Slack (WNS):** **-1.011 ns** (Setup violation on 100 MHz clock domain)
* **Total Negative Slack (TNS):** -58.318 ns
* **Failing Endpoints:** 343 / 16,439
* **Status:** **Timing closure is NOT achieved.** Bitstream operates successfully for hardware demo purposes, but resolving the -1.011 ns setup violation via pipeline register slicing is an active priority for Week 3.

---

## 5. Post-Checkpoint Roadmap (Week 3 & Beyond)

1. **Timing Closure Optimization (Priority 1):**
   * Inspect implemented timing report to trace the -1.011 ns critical path (likely in `sphere_shader.sv` dot products or `sdf_scene.sv` carving comparisons) and insert pipeline register slices to reach positive WNS.
2. **Full 3D Orbital Camera:**
   * Connect camera yaw/pitch angles to primary ray direction rotator in `ray_gen.sv` to orbit the viewpoint completely around the carved model.
3. **Procedural Cavern Background & 4 Primitives:**
   * Integrate analytic box, capsule, and torus distance estimators into the primary scene distance field.
4. **BRAM Optimization / Fluid Dynamics:**
   * Re-evaluate 24-bit buffer configuration or line-buffering if additional BRAM is required for complex fluid metaball state.
