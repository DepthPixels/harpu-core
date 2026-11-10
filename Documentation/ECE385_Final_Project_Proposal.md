# ECE 385 Final Project Proposal
## Project Name: Real-Time Dynamic SDF Raymarching & Fluid Physics Sandbox
**Students:** pdeswal2 & ac176  
**Target Platform:** RealDigital Urbana Board (AMD/Xilinx Spartan-7 `XC7S50-CSGA324-1`)

---

### 1. Idea and Overview

We propose to design and implement a **real-time 3D implicit surface (Signed Distance Field) raymarching graphics accelerator and interactive physical fluid sandbox** on the FPGA. Rather than using conventional polygon rasterization (which requires heavy vertex transformation pipelines, triangle clipping, and Z-buffer memory traffic), our system computes continuous mathematical surfaces on-the-fly using pipelined fixed-point arithmetic. 

The baseline engine natively features an **infinite procedural background** (featuring undulating terrain and organic 3D Gyroid caverns generated purely in math with zero RAM overhead: `sin(x)cos(y) + sin(y)cos(z) + sin(z)cos(x) = 0`) alongside a comprehensive **geometric sculpting toolbox** consisting of four native analytic primitives (**Sphere, Sharp Box, Capsule, and Torus**) and three surface texture modifiers (**Rock Craggle noise, Excavator Ribbing, and Bevel rounding**). The system supports real-time **Constructive Solid Geometry (CSG)**, allowing a user to walk around in first-person and dynamically sculpt, hollow out, and carve true 3D caves, flat-floored chambers, and cylindrical shafts without polygonal re-meshing or frame stutter.

To elevate this beyond a static graphics demo into an interactive physical digital system, we couple the raymarcher with an interactive **Position-Based Fluids (PBD) liquid simulation**. Liquid droplets flow across the landscape, collide against the terrain distance field in O(1) time, and coalesce into continuous liquid bodies using polynomial smooth-minimum (`smin`) metaball blending. The rendering engine incorporates **Crevice Ambient Occlusion (AO)** directly in the baseline shading path, providing deep visual realism to subterranean caverns.

The architecture is fully parameterized (`RENDER_WIDTH`, `NUM_PRIMITIVES`, `NUM_CORES`), establishing a rock-solid **320x180 or 320x240 baseline** upscaled to a standard **640x480 @ 60 Hz** video signal over HDMI using the provided RealDigital IP, with modular extensions for advanced space-warping tools, 3D spatial binning, and dual-core scaling.

#### Hardware vs. Software Partitioning (SoC Architecture):
* **Hardware (SystemVerilog):**
  * **Pipelined Raymarch Processing Unit (RPU):** Pipelined fixed-point ALU running at 100–125 MHz computing ray generation, procedural terrain/Gyroid math, analytic distance estimators (Sphere, Sharp Box, Capsule, Torus), surface modifiers (Craggle, Ribbing, Bevel), and polynomial `smin`/`smax` CSG operations.
  * **Dynamic Primitive Buffer:** On-chip BRAM array holding active CSG primitives with bounding-box early-exit culling and smart compaction.
  * **Surface Normal, Lighting & AO Engine:** 4-tap tetrahedral finite-difference gradient estimator, Blinn-Phong specular highlights, distance fog, and single-tap forward crevice ambient occlusion.
  * **HDMI Video Scanout & Compositor:** Built upon the verified RealDigital `hdmi_tx` IP (`encode.v` + `serdes_10_to_1`), driven by our custom video sync generator, with an on-chip dual-line buffer / BRAM scanout engine performing 2x upscaling to 640x480 @ 60 Hz.
  * **Hardware Overlays & Audio:** Hardware crosshair, holographic tool preview wireframe, FPS counter font ROM, and PWM audio tone synthesizer.
* **Software (MicroBlaze C Code):**
  * **I/O & Player Kinematics:** Polls USB HID packets via the MAX3421E host controller; computes camera rotation matrices and player WASD walking with terrain collision.
  * **Dynamic CSG Manager with Smart Merge:** Manages the active primitive list in BRAM; detects overlapping crater spheres and expands their radii rather than consuming new slots.
  * **Fluid Physics Solver:** Computes droplet velocities, gravitational acceleration, particle-particle repulsion, and boundary restitution against the distance field.
  * **Interactive Undo Stack:** Maintains an edit history stack in memory to pop primitives and revert terrain modifications on demand.

#### Equipment & Demo Plan:
* **Demo Equipment:** RealDigital Urbana board, standard USB mouse and keyboard (connected via USB hub to the on-board MAX3421E host port), micro-USB programming cable, and an HDMI monitor.
* **Demo Execution:** The user walks through the landscape using WASD and looks around with the mouse. The user can switch sculpting tools (sharp boxes for flat rooms, capsules for tunnels, toruses for arches, craggly rock for rough mining) and carve subterranean passages. The user then spawns liquid droplets and carves a trench, demonstrating live fluid flowing down the mountain and pooling into the hollowed basin at a steady 60 FPS.
* **Existing Code / Libraries:** We will utilize the course-provided USB HID software stack for the MAX3421E (Lab 7) and the RealDigital HDMI serialization IP (`hdmi_tx`). All raymarching math, CSG pipelines, video sync generators, and fluid solvers will be developed from scratch in SystemVerilog and C.

---

### 2. Block Diagram

```
                                  URBANA FPGA BOARD TOP-LEVEL
 ┌────────────────────────────────────────────────────────────────────────────────────────────┐
 │                                                                                            │
 │   ┌───────────────────────┐                                                                │
 │   │   MAX3421E USB Host   │                                                                │
 │   │   (Mouse & Keyboard)  │                                                                │
 │   └──────────┬────────────┘                                                                │
 │              │ (SPI)                                                                       │
 │              ▼                                                                             │
 │   ┌───────────────────────────────────────────────────┐                                    │
 │   │           MicroBlaze Soft-Core Processor          │                                    │
 │   │  • USB HID Parsing & Camera 6-DOF Math            │                                    │
 │   │  • Fluid Physics Solver (8-Droplet PBD)           │                                    │
 │   │  • CSG Allocator with Smart Sphere Merging        │                                    │
 │   │  • Dynamic "Undo" History Stack                   │                                    │
 │   └──────────┬────────────────────────────┬───────────┘                                    │
 │              │ (AXI-Lite Registers)       │ (Direct BRAM Write Port)                       │
 │              ▼                            ▼                                                │
 │      [ Camera Matrix,            [ Dynamic Primitive BRAM Array ]                          │
 │        Fluid Droplet States,     [ 64-128 Primitives @ 128-bit  ]                          │
 │        Tool Parameters ]                  │                                                │
 │              │                            │ (Single-Cycle Read Port)                       │
 │              ├────────────────────────────┤                                                │
 │              ▼                            ▼                                                │
 │   ┌──────────────────────────────────────────────────────────────────┐                     │
 │   │        Pipelined Raymarch Processing Unit (100–125 MHz)          │                     │
 │   │  • Fixed-Point Ray Direction Generator (Matrix Transform)        │                     │
 │   │  • Procedural Bedrock ALU (Gyroid Caverns & Terrain Waves)       │                     │
 │   │  • Native Primitives Core: Sphere, Sharp Box, Capsule, Torus     │                     │
 │   │  • Surface Modifiers: Rock Craggle Noise, Ribbing, Bevel         │                     │
 │   │  • Modular Domain Warpers (Arc Bend, Taper, Twist, Shear)        │                     │
 │   │  • CSG Combiner (smin Add, smax Carve, 8 Fluid Metaballs)        │                     │
 │   │  • Tetrahedral Surface Normal Estimator (4 Taps)                 │                     │
 │   │  • Shading Engine: Blinn-Phong + Crevice Ambient Occlusion (AO)  │                     │
 │   └────────────────────────────────┬─────────────────────────────────┘                     │
 │                                    │ (Pixel Stream Writes)                                 │
 │                                    ▼                                                       │
 │   ┌──────────────────────────────────────────────────────────────────┐                     │
 │   │     Dual-Port Framebuffer / Line-Buffer BRAM (320x180 / 320x240) │                     │
 │   └────────────────────────────────┬─────────────────────────────────┘                     │
 │                                    │ (25.175 MHz Scanout Read Port)                        │
 │                                    ▼                                                       │
 │   ┌──────────────────────────────────────────────────────────────────┐                     │
 │   │              Custom Video Timing Generator & Compositor          │                     │
 │   │  • 2x Hardware Pixel Upscaler to 640x480 @ 60 Hz                 │                     │
 │   │  • Hardware Crosshair & Holographic Tool Wireframe Overlay       │                     │
 │   │  • Hardware FPS Counter (Font ROM Overlay)                       │                     │
 │   └────────────────────────────────┬─────────────────────────────────┘                     │
 │                                    │ (RGB Data + Sync)                                     │
 │                                    ▼                                                       │
 │   ┌──────────────────────────────────────────────────────────┐      ┌───────────────────┐  │
 │   │          Provided RealDigital HDMI IP (hdmi_tx)          │      │  PWM Audio Core   │  │
 │   │  • 3x 8b/10b TMDS Encoders (encode.v)                    ├─────►│  • Carve Rumble   │  │
 │   │  • 10:1 DDR Serializer (serdes_10_to_1.v @ 125 MHz)      │      │  • Splash Impact  │  │
 │   └────────────────────────────┬─────────────────────────────┘      └─────────┬─────────┘  │
 └────────────────────────────────┼──────────────────────────────────────────────┼────────────┘
                                  ▼                                              ▼
                        HDMI Port (640x480@60)                            Audio 3.5mm Jack
```

---

### 3. List of Features

#### i. Baseline Features (Required for Core Working Functionality)
1. **Pipelined Fixed-Point 3D Raymarcher:** Hardware sphere-tracing core executing at 100–125 MHz, evaluating fixed-point Q8.8 distance arithmetic.
2. **Procedural Infinite Terrain & Caverns:** Real-time evaluation of wavy terrain and 3D Gyroid cavern equations (`sin(x)cos(y) + sin(y)cos(z) + sin(z)cos(x) = 0`) directly in logic with 0 bytes of RAM.
3. **Four Native Geometric Primitives:**
   * **Sphere:** Organic boulders, craters, and smooth excavation blobs.
   * **Sharp Box:** Inigo Quilez exact box formula for crisp architectural doorways, flat walking floors, and steps.
   * **Capsule (Swept Sphere):** Continuous cylindrical tunnel boring between 3D vectors.
   * **Torus:** Architectural arches, circular rings, and floating portals.
4. **Three Native Surface Texture Modifiers (Post-Ops):**
   * **Rock Craggle Noise:** High-frequency surface displacement simulating rough, blasted volcanic rock.
   * **Excavator Ribbing:** Concentric circular periodic ridges mimicking Tunnel Boring Machine (TBM) cutter marks.
   * **Rounding / Bevel (d' = d - r):** Softens sharp edges into smooth river stones or puffy clay.
5. **HDMI Video Display (640x480 @ 60 Hz):** Verified scanout using the provided RealDigital `hdmi_tx` IP paired with our custom video timing generator and a 2x pixel-doubling scanout path.
6. **USB 6-DOF Camera Navigation:** First-person camera control (WASD walking, mouse look) driven by MicroBlaze via the Lab 7 MAX3421E USB Host controller.
7. **Interactive CSG Carving with Smart Merging:** Real-time boolean subtraction (`smax(d_scene, -d_tool)`) allowing the player to carve tunnels on mouse click. MicroBlaze dynamically merges overlapping spheres to preserve primitive capacity.
8. **Lighting Engine with Crevice Ambient Occlusion (AO):** 4-tap tetrahedral normal estimator, Lambertian diffuse, Blinn-Phong specular highlights, and 1-tap forward AO probe darkening cave crevices.

#### ii. Additional Features (Extra Difficulty & Modular Extensions)
1. **Interactive Liquid Simulation (PBD Fluid + `smin` Metaballs):** 8 dynamic fluid droplets simulated in MicroBlaze and rendered in hardware with smooth-minimum surface tension to simulate flowing, pooling water (with an optional toggle for glowing emissive molten lava).
2. **Domain Space Warping Operators (Pre-Ops):**
   * **Arc Bend:** Coordinate warp along circular arcs to bore curved 90° and 180° U-turn tunnels.
   * **Taper:** Linear axis scaling creating conical drill shafts, stalactites, and pyramids.
   * **Twist:** Corkscrew coordinate warping creating Archimedes screw tunnels and spiral spires.
   * **Shear / Skew:** Horizontal coordinate shift creating clean 45° walking ramps and slopes.
3. **Interactive "Undo" Functionality:** MicroBlaze maintains an edit history stack; pressing an Undo key (`Z`) pops the last dynamic edit and instantly restores the terrain geometry.
4. **3D Spatial Acceleration Bins (32x32x16):** Coarse BRAM spatial hash table allowing scaling up to 2,048 simultaneous edits across a massive 128m x 128m x 64m world.
5. **Holographic Tool Reticle & On-Screen Display:** Native resolution crosshair, FPS counter, and a 3D wireframe preview showing where the carving tool will hit before clicking.
6. **Hardware PWM Audio:** Procedural audio rumble when excavating rock and impact splash sounds when fluid hits terrain.
7. **Dual-Core 60 FPS Scaling (Modular Stretch Goal):** Instantiation of a second parallel raymarch core to double frame throughput if synthesis timing and DSP margins allow.
8. **720p Video Mode (Modular Stretch Goal):** Optional 1280x720 video timing generator if the 371.25 MHz serialization clock passes timing closure.

---

### 4. Expected Difficulty and Justification

* **Baseline Difficulty:** **12 – 13 / 15**
* **Final Expected Difficulty with Additional Features:** **15 / 15**

#### Technical Justification & Compute Budget:
1. **High-Throughput Fixed-Point Arithmetic:** Unlike conventional polygon rasterization or Lab 7's text controller (which performs one font ROM lookup per pixel), raymarching evaluates non-linear vector equations iteratively. At 320x180 @ 60 FPS, the engine computes 3.45 M pixels/sec. With an average of 35 march steps per pixel, the hardware processes **approx 120 million distance evaluations per second**. Sustaining this across 4 distinct primitive types and surface modifiers without pipeline stalls requires deeply pipelined DSP multiplier stages and custom reciprocal square-root lookups.
2. **Elimination of SIMD Thread Divergence:** On desktop GPUs, raymarching suffers severe warp stalls when neighboring rays branch between air and solid terrain. On the FPGA, our pipeline is fully deterministic and systolic: rays stream through fixed pipeline stages with zero thread-divergence stalls, fully exploiting FPGA architectural strengths over GPUs.
3. **Hardware/Software Heterogeneous Computing:** The MicroBlaze handles dynamic kinematics, smart CSG compaction, undo history, and fluid particle physics, while the custom FPGA fabric acts as an instantaneous O(1) collision and surface normal coprocessor via the distance field.
4. **Dynamic Topology Without Meshes:** Achieving real-time 3D solid carving, organic procedural gyroids, and fluid coalescing without polygonal mesh generation or frame stutter demonstrates advanced digital signal processing and graphics systems architecture.

#### Spartan-7 (`XC7S50-CSGA324-1`) Resource Budget Table:

| Resource | Available on Chip | Estimated Baseline Usage | % Utilization | Status |
| :--- | :--- | :--- | :--- | :--- |
| **LUTs** | 32,600 | approx 16,000 – 19,000 (Ray Core + MicroBlaze + AXI) | ~52% | **SAFE** |
| **DSPs (DSP48E1)** | 120 | approx 32 – 40 (Ray Gen + Primitives + Normals + AO) | ~32% | **SAFE** (Dual-core: ~60) |
| **BRAM (36Kb blocks)** | 75 (337.5 KB) | 26 blocks (Framebuffer 58KB + Primitives 8KB + CPU) | ~35% | **SAFE** (Bins: ~39 blks) |
| **Clock Domains** | MMCM / PLL | 100–125 MHz (Raymarch) / 25.175 MHz (HDMI) | N/A | **TIMING SAFE** |

---

### 5. Proposed Timeline

* **Week 1 (Nov 9 – Nov 15): Video Path & Core Raymarch Sim**
  * *Days 1–2:* Set up the provided RealDigital `hdmi_tx` IP with our custom video timing generator; verify stable 640x480 @ 60 Hz color bars on the monitor.
  * *Days 3–5:* Write and simulate the fixed-point Ray Generator, Gyroid terrain ALU, 4 geometric primitives (Sphere, Box, Capsule, Torus), and surface modifiers in Vivado/ModelSim; stream static 3D test patterns to the monitor with Crevice AO.
* **Week 2 (Nov 16 – Nov 20): Interactive Integration [MID-PROJECT CHECKPOINT]**
  * *Software:* Integrate MAX3421E USB mouse and keyboard drivers on MicroBlaze; stream camera matrix over AXI-Lite.
  * *Hardware:* Connect raymarch core to video buffer; implement real-time CSG carving across all 4 primitives and smart sphere merging.
  * **Mid-Checkpoint Deliverable (Nov 20):** Working live demo showing a 3D scene on an HDMI monitor where the user walks/looks with USB controls and carves flat-floored rooms (sharp box) and tunnels (capsule) out of geometry in real time.
* **Fall Break (Nov 21 – Nov 29): Space Warps, Undo Stack & Tools**
  * Expand primitive buffer to 64 slots with bounding-box early exit and Undo stack.
  * Implement space warps (Arc Bend, Taper, Twist, Shear).
* **Week 3 (Nov 30 – Dec 6): Fluid Simulation & Visual Overlays**
  * *Physics:* Implement MicroBlaze 8-droplet PBD fluid loop; wire droplet coordinates to hardware `smin` metaball blending (water/lava toggle).
  * *Graphics:* Add holographic tool preview outline and hardware FPS counter font ROM.
  * *Advanced:* Test 3D spatial bin grid integration and clock scaling (100 vs 125 MHz).
* **Week 4 (Dec 7 – Dec 11): Audio, Polish & Showcase Demo**
  * Connect PWM audio synthesizer for excavation rumble and fluid splashes.
  * Timing closure verification, system stability testing, and final project demo on **Dec 11**.

---

### 6. Fallback & Scaling Ladder ("If It Slips, We Demo This")

To ensure a guaranteed working demo on Dec 11 regardless of debugging obstacles:
1. **If Fluid Simulation is Unstable:** Drop fluid particle attraction and demo **rigid bouncing physics spheres** (simple elastic reflection off grad d).
2. **If Complex Space Warps Timing Fails:** Disable Twist/Shear and fall back strictly to the **baseline 4 primitives (Sphere, Box, Capsule, Torus)**.
3. **If Frame Rate Drops on Complex Scenes:** Adjust top-level parameters: drop render resolution from 320x240 to 320x180, or cap raymarch steps to 28.
4. **If 720p Serialization Fails Timing:** Maintain the verified baseline of **640x480 @ 60 Hz** using the provided RealDigital IP.

---

### 7. References & Prior Art

1. **TinyGPUs (Silice Hardware Graphics):** S. Lefebvre, *"TinyGPUs: A collection of small GPUs for FPGAs,"* [github.com/sylefeb/tinygpus](https://github.com/sylefeb/tinygpus). *(Course-recommended hardware graphics reference).*
2. **Dynamic Signed Distance Fields in Game Engines:** M. Turitzin, *"I'm making a game engine based on dynamic signed distance fields (SDFs),"* 2023. [youtube.com/watch?v=il-TXbn5iMA](https://youtu.be/il-TXbn5iMA). *(Core visual and architectural inspiration).*
3. **Signed Distance Field Modeling & Raymarching:** I. Quilez, *"Distance Functions and Raymarching Techniques,"* [iquilezles.org/articles/distfunctions](https://iquilezles.org/articles/distfunctions). *(Canonical reference for exact box, capsule, and smooth boolean algebra).*
4. **RealDigital Urbana Reference Design:** RealDigital Inc., *"HDMI Transmitter IP & Urbana Board Technical Documentation,"* [realdigital.org](https://realdigital.org). *(Hardware IP for DVI 8b/10b and 10:1 DDR serialization).*
5. **Position-Based Dynamics:** M. Müller et al., *"Position Based Dynamics,"* Journal of Virtual Reality and Broadcasting, 2007. *(Foundational reference for lightweight, unconditionally stable particle-based fluid solvers).*
6. **ECE 385 Laboratory Reference (Lab 7 SoC & USB):** University of Illinois Urbana-Champaign, *"Lab 7: MicroBlaze SoC with USB Host & Video Display,"* 2026. *(Platform reference for MAX3421E USB SPI driver and AXI-Lite memory mapping).*
