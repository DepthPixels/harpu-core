# HARPU: Real-Time FPGA Raymarching Accelerator

[![SystemVerilog](https://img.shields.io/badge/Language-SystemVerilog-blue.svg)](https://en.wikipedia.org/wiki/SystemVerilog)
[![FPGA](https://img.shields.io/badge/Target-AMD%20Spartan--7%20(XC7S50)-red.svg)](https://www.xilinx.com/products/silicon-devices/fpga/spartan-7.html)
[![Vivado](https://img.shields.io/badge/EDA-Xilinx%20Vivado%202022.2-orange.svg)](https://www.xilinx.com/products/design-tools/vivado.html)
[![HDMI](https://img.shields.io/badge/Video-HDMI%20640x480%4060Hz-brightgreen.svg)](https://en.wikipedia.org/wiki/HDMI)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

**HARPU** (Hardware Accelerated Raymarching Processing Unit) is a dedicated 3D graphics and physics coprocessor implemented in SystemVerilog on an AMD Spartan-7 FPGA. 

Traditional raymarching algorithms for Signed Distance Fields (SDFs) are compute-heavy and typically executed on massive multi-threaded GPUs using pixel shaders. HARPU demonstrates that a custom, deeply pipelined silicon microarchitecture can compute, shade, and render real-time 3D procedural scenes at **164 FPS** directly on constrained FPGA fabric with **zero external memory** overhead.

---

## Architecture Overview

```
                      +---------------------------------------+
                      |       Ray Generation Engine           |
                      |   (Camera Origin & Screen Vectors)    |
                      +-------------------+-------------------+
                                          |
                                          v
                      +---------------------------------------+
                      |     16-Ray Wavefront Scheduler        |
                      |    (Synchronous Slot & Ray FIFO)      |
                      +-------------------+-------------------+
                                          |
                      +-------------------+-------------------+
                      |   12-Stage Pipelined SDF Evaluator    |
                      |  - Q8.8 Fixed-Point Pipelined ALUs   |
                      |  - Pipelined Square Root Engine       |
                      |  - Procedural Gyroid / Surface Math   |
                      |  - Dynamic CSG Boolean Carving        |
                      +-------------------+-------------------+
                                          |
                                          v
                      +---------------------------------------+
                      |         Sphere Shader & Normal        |
                      |  (Central Differences & Lambertian)   |
                      +-------------------+-------------------+
                                          |
                                          v
      +---------------------------------------------------------------+
      |              Dual-Port Block RAM Framebuffer                  |
      |   Port A (Write @ 100 MHz)   <--->   Port B (Read @ 25 MHz)   |
      +---------------------------------------------------------------+
                                          |
                                          v
                      +---------------------------------------+
                      |       HDMI Scanout & TMDS Encoder     |
                      |      (DVI 10:1 Serializer @ 125 MHz)  |
                      +-------------------+-------------------+
                                          |
                                     HDMI Output
                                 (640x480 @ 60 Hz)
```

---

## Key Hardware Features

### 1. 16-Ray Interleaved Wavefront Pipeline
* **Throughput Optimization**: Naive single-ray marchers stall constantly while waiting for iterative distance checks to resolve. HARPU architects an interleaved wavefront pipeline managing **16 simultaneous active ray contexts** in flight.
* **100% Pipeline Occupancy**: While Ray $N$ calculates distance bounds across the 12-stage math pipeline, Rays $N+1$ through $N+15$ advance through position accumulation, normal extraction, and memory dispatch.
* **Performance Benchmark**: Boosted effective rendering throughput from **11.7 FPS to 164 FPS** at native 640x480 resolution, computing over **120 Million fixed-point distance evaluations per second**.

### 2. Zero-BRAM Procedural Surface Math
* Rather than storing dense 3D voxel grids in memory, HARPU generates complex organic caverns and undulating terrain on the fly using purely arithmetic trigonometric and geometric ALUs.
* Evaluates mathematical SDF primitives and Constructive Solid Geometry (CSG) boolean differences with **0 bytes of Block RAM overhead**, preserving all FPGA memory for video buffering.

### 3. Dynamic Interactive CSG Carving
* Integrated real-time boolean subtraction hardware (`carve_controller.sv`) allows live interactive destruction/modification of the 3D SDF geometry without re-synthesizing or rebuilding bitstreams.
* Computes analytical smooth-minimum and boolean carving operations in deterministic fixed-point cycles.

### 4. Heterogeneous MicroBlaze Co-Processor
* Coupled with an onboard 32-bit **Xilinx MicroBlaze** RISC soft-core running bare-metal C.
* The CPU computes Position-Based Dynamics (PBD) particle fluids and physics simulation with $O(1)$ distance-field collision detection, streaming state updates across memory-mapped AXI registers to the hardware rasterizer.

### 5. Multi-Clock Domain Video Pipeline
* **System Clock Domain (100 MHz)**: MicroBlaze, AXI interconnect, and Raymarching execution cores.
* **Pixel Clock Domain (25 MHz)**: VGA/DVI timing generator and scanout counter.
* **Serializer Clock Domain (125 MHz)**: 10:1 Double Data Rate (DDR) TMDS serializers driving differential HDMI clock and data pairs.
* **Dual-Port Framebuffer BRAM**: Bridges clock domains cleanly: Port A writes at 100 MHz; Port B reads asynchronously at 25 MHz with zero tear or bus contention.

---

## Directory Structure

```
Final_Project.srcs/sources_1/new/
├── harpu_top.sv            # Top-level hardware integration, clock distribution & pin mapping
├── raymarch_core.sv        # 16-ray interleaved wavefront pipeline & context management
├── sdf_scene.sv            # 12-stage pipelined signed distance field ALU & scene evaluator
├── carve_controller.sv     # Dynamic CSG carving controller and coordinate transform
├── sphere_shader.sv        # Numerical normal estimation & surface shading pipeline
├── math_sqrt.sv            # Pipelined fixed-point square root arithmetic unit
├── lut_inv_sqrt.sv         # Fast reciprocal square root lookup table & interpolator
├── fb_test_writer.sv       # Video buffer test generator and diagnostic pattern unit
└── memory.sv               # Memory interface and arbitration logic
```

---

## Hardware & Toolchain

* **Target Device**: AMD Spartan-7 FPGA (`XC7S50CSGA324-1`)
* **Development Board**: RealDigital Blackboard / Digilent Arty S7-50
* **Synthesis & Implementation**: Xilinx Vivado ML Edition 2022.2
* **Software Toolchain**: Xilinx Vitis 2022.2 (Bare-metal C for MicroBlaze)
* **Video Standard**: DVI / HDMI 1.0 (640x480 @ 60 Hz, 25 MHz pixel clock)

---

## Author

**Parav Deswal**  
Computer Engineering, University of Illinois at Urbana-Champaign  
GitHub: [@DepthPixels](https://github.com/DepthPixels) | LinkedIn: [parav-deswal](https://www.linkedin.com/in/parav-deswal)
