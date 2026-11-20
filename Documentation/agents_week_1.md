# HARPU: Week 1 Progress Tracker & Milestones

> **NOTE FOR ALL AI ASSISTANTS:**  
> Before reading this file, review and comply with **`Documentation/agent_rules.md`**.  
> **Rule Reminder:** Your primary role is planning and debugging. **Do NOT generate or modify source code unless explicitly commanded by the user.** Record all actions in `Documentation/AI_Documentation/session_log.md`.

---

## 1. Project Quick Reference

* **Project:** **HARPU** (Hardware-Accelerated Raymarching Processing Unit)
* **Target:** AMD/Xilinx Spartan-7 `XC7S50-CSGA324-1` (Urbana Board)
* **Repo:** `https://github.com/DepthPixels/harpu-core.git`
* **Team:** `pdeswal2` & `ac176`
* **Current Phase:** Week 1 — Project Inception, Repository Setup & Video Bring-Up
* **Upcoming Critical Deadline:** **Friday, Nov 20 — Mid-Project Checkpoint (5 pts)**

---

## 2. Week 1 Progress Checklist (Nov 9 – Nov 15)

### Status Legend
- [x] Completed
- [/] In Progress
- [ ] Not Started
- [!] Blocked / Needs Attention

---

### Step 1: Environment & Project Setup
- [x] Initial proposal drafted, peer-reviewed, and submitted.
- [x] Proposal exported to PDF (`Documentation/ECE385_Final_Project_Proposal.pdf`).
- [x] Git repository initialized (`main` branch) and linked to GitHub (`DepthPixels/harpu-core`).
- [x] Vivado-tailored `.gitignore` configured and verified against `Final_Project/`.
- [x] Vivado project created in `Final_Project/Final_Project.xpr`.
- [x] Agent rules (`agent_rules.md`) and session log established.

---

### Step 2: Video Path Bring-Up (Days 1–2 Target)
- [x] Import RealDigital `hdmi_tx` IP (`encode.v`, `serdes_10_to_1.v`) into Vivado project.
- [x] Integrate standard $640 \times 480$ @ 60 Hz VGA controller timing ($25\text{ MHz}$ pixel clock).
- [x] Create simple color-bar / keyboard-reactive test-pattern top-level module (`harpu_top.sv`).
- [x] Map differential TMDS clock/data pins and USB/UART/Hex displays in `mb_harpu.xdc`.
- [x] Synthesize, program bitstream, and verify rock-solid video output and keycode handling on physical hardware.
- [x] Implement $2\times$ pixel upscaler / frame buffer BRAM integration ($320 \times 240 \to 640 \times 480$) — verified glitch-free on hardware.

---

### Step 3: Raymarch Pipeline & 3D Hardware Bring-Up
- [x] Implement fixed-point ray direction generator ($(u,v) \to \vec{r}_d$ in $Q8.8$) — verified with `ray_gen_tb.sv` in simulation (<0.8% error).
- [x] Implement non-restoring fixed-point square root core (`math_sqrt.sv`) — verified bit-accurate.
- [x] Implement Sphere SDF ALU (`sdf_scene.sv`): $\|\vec{p} - \vec{c}\| - r$ — verified in hardware.
- [x] Implement sphere-tracing step FSM / pipeline (`raymarch_core.sv`): verified on hardware.
- [x] Implement Blinn-Phong specular & Lambertian diffuse lighting engine (`sphere_shader.sv`): verified on hardware.
- [x] Live hardware milestone: Render real-time 3D shaded sphere onto monitor via on-chip BRAM framebuffer ($320 \times 240 \to 640 \times 480$).
- [x] Implement Dynamic CSG Carving ALU: $d_{\text{carved}} = \max(d_{\text{sphere}}, -d_{\text{carve}})$.
- [x] Implement Analytical Surface Normal Engine ($\nabla d$) in `raymarch_core.sv`.
- [x] Connect MicroBlaze USB registers to CSG carve inputs for real-time interactive carving.

---

### Step 4: Hardware Integration & First 3D Output (Day 5 Target)
- [x] Connect raymarcher pixel output stream to dual-port BRAM buffer.
- [x] Scan out raymarched scene to physical HDMI monitor.
- [x] Milestone Deliverable: A static or rotating 3D sphere/box on the monitor at 60 FPS (achieved 164 FPS internal throughput).

---

## 3. Active Blockers & Debugging Log
*All Week 1 hardware bring-up and video integration milestones fully completed and closed.*

---

## 4. Transition to Week 2
* **Status:** Week 1 baseline fully achieved. Interactive USB HID DualSense integration, real-time CSG carving, and Midpoint Checkpoint features transitioned to `Documentation/agents_week_2.md`.*

