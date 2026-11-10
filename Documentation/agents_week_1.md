# HARPU: Week 1 Agent Context & Handoff Guide

> **Purpose:** This document maintains state, architectural constraints, and task progress across new AI agent sessions and conversation threads to avoid context fragmentation. Any new agent thread should read this file first.

---

## 1. Project Identity & Repository Overview

* **Project Name:** **HARPU** (Hardware-Accelerated Raymarching Processing Unit)
* **Full Title:** Real-Time Dynamic SDF Raymarching & Fluid Physics Sandbox
* **Course:** ECE 385 (Digital Systems Laboratory) - UIUC
* **Team:** `pdeswal2` & `ac176`
* **Target Hardware:** RealDigital Urbana FPGA Board
* **FPGA Part Number:** AMD/Xilinx Spartan-7 **`XC7S50-CSGA324-1`**
  * *Resource Budget:* 32,600 LUTs, 65,200 FFs, 120 DSP48E1 slices, 75 36Kb BRAM blocks (337.5 KB).
* **Git Repository:** `https://github.com/DepthPixels/harpu-core.git`
  * *Local Working Directory:* `F:\ECE 385 Final Project`
  * *Active Vivado Project:* `F:\ECE 385 Final Project\Final_Project\Final_Project.xpr`
  * *Documentation Folder:* `F:\ECE 385 Final Project\Documentation\`

---

## 2. System Architecture & Core Concept

Instead of conventional polygon rasterization (which requires vertex transformations, triangle setup, and Z-buffer memory), HARPU is an **implicit surface raymarcher** executing iterative sphere-tracing directly in hardware.

### Key Architectural Pillars:
1. **Procedural Background:**
   * Infinite terrain waves and 3D Gyroid caverns:
     $$\sin(x)\cos(y) + \sin(y)\cos(z) + \sin(z)\cos(x) = 0$$
   * Evaluated entirely in fixed-point math with **0 bytes of RAM**.
2. **Native Geometric Sculpting Toolbox:**
   * **4 Base Primitives:** Sphere, Sharp Box (Inigo Quilez exact box), Capsule (continuous tunnel boring), and Torus (arches/rings).
   * **3 Surface Modifiers:** Rock Craggle Noise (blasted rock), Excavator Ribbing (TBM drill rings), and Bevel Rounding ($d' = d - r$).
   * **Dynamic CSG:** Real-time boolean subtraction (`smax(d_scene, -d_tool)`) and union (`smin`).
3. **PBD Fluid Physics Sandbox:**
   * 8 dynamic liquid droplets simulated in MicroBlaze and rendered in hardware using polynomial smooth-minimum (`smin`) metaball blending for realistic surface tension and pooling.
4. **Lighting Engine:**
   * 4-tap tetrahedral finite-difference gradient estimator ($\nabla d$).
   * Blinn-Phong specular highlights + distance fog.
   * **Crevice Ambient Occlusion (AO):** 1-tap forward probe along the normal vector darkening subterranean shafts.
5. **Video & Memory Pipeline:**
   * **Internal Render Resolution:** Parameterized $320 \times 180$ or $320 \times 240$ buffer in dual-port BRAM.
   * **Output Display Resolution:** $640 \times 480$ @ 60 Hz via the provided RealDigital `hdmi_tx` IP (`encode.v` + `serdes_10_to_1.v`).
   * **Zero DDR3 Dependency:** All Week 1–2 buffers stay 100% in on-chip BRAM to eliminate memory arbitration bugs.
6. **SoC Partitioning:**
   * **MicroBlaze (C):** MAX3421E USB Host polling (WASD walking, mouse look), dynamic CSG smart merging, undo history stack, and 8-droplet PBD physics loop.
   * **FPGA Logic (SystemVerilog):** 100–125 MHz pipelined Raymarch Processing Unit, distance ALUs, lighting, video scanout upscaler, and PWM audio.

---

## 3. Week 1 Objectives & Daily Schedule (Nov 9 – Nov 15)

### Phase 1: Video Scanout Bring-Up (Days 1–2)
- [ ] Import the provided RealDigital `hdmi_tx` IP (`encode.v`, `serdes_10_to_1.v`) into `Final_Project.xpr`.
- [ ] Write `vga_controller.sv` / `sync_generator.sv` for $640 \times 480$ @ 60 Hz ($25.175\text{ MHz}$ pixel clock).
- [ ] Generate standard color-bar test patterns and static geometric gradient patterns on a physical monitor.
- [ ] Implement the dual-line buffer / $2\times$ pixel doubler ($320 \times 240 \to 640 \times 480$).

### Phase 2: Core Raymarching RTL in Simulation (Days 3–4)
- [ ] **Fixed-Point Ray Direction Generator:** Compute normalized ray direction $\vec{r}_d$ from screen coordinates $(u, v)$ and camera rotation matrix $R_{3\times3}$ using $Q8.8$ arithmetic.
- [ ] **Primitive Distance ALUs:**
  - Sphere: $\|\vec{p} - \vec{c}\| - r$
  - Sharp Box: $\|\max(|\vec{p}| - \vec{b}, 0)\| + \min(\max(q_x, \max(q_y, q_z)), 0)$
  - Gyroid Cavern formula: $\sin(x)\cos(y) + \sin(y)\cos(z) + \sin(z)\cos(x)$
- [ ] **Raymarch Stepper Loop:** Finite state machine / systolic pipeline iterating $t \leftarrow t + d$.
- [ ] **Tetrahedral Surface Normal Unit:** 4-sample finite-difference ALU.
- [ ] **Blinn-Phong + Crevice AO:** Simple directional sun light + 1-tap AO probe.

### Phase 3: Hardware Verification (Day 5)
- [ ] Connect the single-core raymarcher output into the dual-port BRAM buffer.
- [ ] Output a static or auto-rotating 3D sphere / box directly to the physical HDMI monitor.

---

## 4. Hard Constraints for All Agents

1. **Strictly Fixed-Point Arithmetic:** Never use SystemVerilog `real` or floating-point types in synthesizable code. Standardize on $Q8.8$ (16-bit signed, 8-bit integer, 8-bit fractional) or $Q16.16$ where large coordinate ranges are required.
2. **Keep the Baseline De-risked:** Do not attempt custom 371.25 MHz TMDS serialization or DDR3 memory controllers during Week 1. Use the provided RealDigital `hdmi_tx` IP and on-chip BRAM.
3. **Mid-Checkpoint Target (Nov 20):** All work in Week 1 must directly support the Week 2 mid-checkpoint goal: **a live hardware demo where the TA can move the USB mouse to look around and click to carve a hole out of 3D geometry in real time.**
4. **Maintain the Git Tree Clean:** Keep all generated files within the `.gitignore` rules. Commit verified RTL modules incrementally with descriptive messages.

---

## 5. Important File Locations

| File / Directory | Purpose |
| :--- | :--- |
| `Documentation/ECE385_Final_Project_Proposal.pdf` | Official signed-off project proposal |
| `Documentation/ECE385_Final_Project_Proposal.md` | Proposal Markdown source |
| `Documentation/agents_week_1.md` | **This file** (Agent context handoff) |
| `Final_Project/Final_Project.xpr` | Active Vivado project file |
| `.gitignore` | Project git exclusions (Vivado & Vitis build caches) |
