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
- [ ] Import RealDigital `hdmi_tx` IP (`encode.v`, `serdes_10_to_1.v`) into Vivado project.
- [ ] Design custom `sync_generator.sv` for standard $640 \times 480$ @ 60 Hz timing ($25.175\text{ MHz}$ pixel clock).
- [ ] Create simple color-bar / test-pattern top-level module.
- [ ] Map differential TMDS clock/data pins in `urbana.xdc`.
- [ ] Synthesize, program bitstream, and verify rock-solid video output on physical monitor.
- [ ] Implement $2\times$ pixel upscaler / dual-line buffer ($320 \times 240 \to 640 \times 480$).

---

### Step 3: Raymarch RTL Architecture in Simulation (Days 3–4 Target)
- [ ] Implement fixed-point ray direction generator ($(u,v) \to \vec{r}_d$ in $Q8.8$).
- [ ] Implement core distance ALUs in SystemVerilog:
  - [ ] Sphere SDF: $\|\vec{p} - \vec{c}\| - r$
  - [ ] Sharp Box SDF: Inigo Quilez exact box logic
  - [ ] Procedural Gyroid ALU: $\sin(x)\cos(y) + \sin(y)\cos(z) + \sin(z)\cos(x)$
- [ ] Implement sphere-tracing step FSM / pipeline ($t \leftarrow t + d$).
- [ ] Implement 4-tap tetrahedral normal estimator ($\nabla d$).
- [ ] Implement Blinn-Phong diffuse/specular lighting + 1-tap Crevice Ambient Occlusion.
- [ ] Verify raymarcher output in ModelSim / Vivado testbench against reference images.

---

### Step 4: Hardware Integration & First 3D Output (Day 5 Target)
- [ ] Connect raymarcher pixel output stream to dual-port BRAM buffer.
- [ ] Scan out raymarched scene to physical HDMI monitor.
- [ ] Milestone Deliverable: A static or rotating 3D sphere/box on the monitor at 60 FPS.

---

## 3. Active Blockers & Debugging Log
*Currently no active blockers. Project setup and documentation complete.*

---

## 4. Current Workstream & Next Immediate Task
* **Immediate Task:** Bring up the $640 \times 480$ @ 60 Hz video test pattern using the provided RealDigital `hdmi_tx` IP and verify stable sync on the monitor.
