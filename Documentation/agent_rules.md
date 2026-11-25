# AI Agent Operating Rules & Guidelines

> **CRITICAL INSTRUCTION FOR ALL AI ASSISTANTS / AGENTS:**  
> Read this file in full before interacting with the user or working on the HARPU repository. These rules are mandatory and strictly enforced across all threads and sessions.

---

## 1. Primary Role & "No Unsolicited Code" Policy

1. **Planning, Architecture & Debugging First:**
   * Your primary function is **high-level planning, mathematical verification, architectural design, timing/resource assessment, and debugging support**.
2. **Do NOT Make Unsolicited Code Changes:**
   * **Never modify, create, or edit source code files (`.sv`, `.v`, `.vhd`, `.c`, `.h`, `.xdc`) unless the user explicitly asks you to do so.**
3. **Do NOT Output Code Dumps Unless Requested:**
   * Do not provide full module code implementations or long code blocks unless the user directly commands: *"write this module"*, *"generate the code"*, or *"give me the SystemVerilog"*.
   * When explaining ideas or reviewing bugs, prefer concise pseudocode, mathematical equations, signal timing diagrams, or bullet-point logic flows.

---

## 2. Mandatory Record Keeping & Audit Logging

To maintain academic integrity and build a comprehensive audit trail for the ECE 385 final lab report:

1. **Log Location:**
   * All session actions must be recorded in the directory:
     `Documentation/AI_Documentation/`
2. **What Must Be Logged:**
   Whenever you perform actions in a session (or before ending a conversation turn where work occurred), record:
   * **Files Changed / Created:** Exact relative file paths.
   * **Terminal Commands Executed:** The command string, exit code, and brief purpose.
   * **Debugging Log:** Root causes identified, synthesis/timing errors diagnosed, simulation mismatches caught, and their resolutions.
3. **Log Format & Author Differentiation:**
   * Append entries to `Documentation/AI_Documentation/session_log_post_checkpoint.md` with timestamps and brief bullet points (legacy Week 1–2 log is archived in `session_log.md`).
   * **Explicit Attribution:** Every logged task, file change, diagnostic step, or test must explicitly state who performed it using clear tags: **`[USER]`** or **`[AGENT]`** (e.g., `* [USER] Implemented ray_gen.sv`, `* [AGENT] Diagnosed 16-bit intermediate truncation in math expressions`).

---

## 3. Project Architectural Constraints

Keep these project hardware invariants in mind at all times:

* **Target Device:** RealDigital Urbana FPGA Board — AMD/Xilinx Spartan-7 **`XC7S50-CSGA324-1`**.
  * 32,600 LUTs, 65,200 FFs, 120 DSP48E1 slices, 75 36Kb BRAM blocks (337.5 KB).
* **Strict Fixed-Point Math:**
  * All distance fields, ray vectors, and coordinate warps must use fixed-point arithmetic ($Q8.8$ standard; $Q16.16$ for wide ranges).
  * **Never introduce floating-point (`real`) types** into synthesizable HDL.
* **No External DDR3 in Weeks 1–2:**
  * The internal render buffer ($320 \times 180$ or $320 \times 240$) and primitive arrays must fit entirely inside on-chip BRAM. Do not introduce DDR3 controllers to avoid memory arbitration complexity.
* **HDMI Display Path:**
  * Use the provided RealDigital `hdmi_tx` IP (`encode.v` + `serdes_10_to_1.v`) at $640 \times 480$ @ 60 Hz ($25.175\text{ MHz}$ pixel clock).
* **Mid-Checkpoint Deliverable (Friday, Nov 20):**
  * Every design choice must protect the mid-checkpoint requirement: a working hardware demo on the monitor where the user can move the USB mouse to look around and carve a 3D hole out of an object in real time.

---

## 4. Documentation Structure

* `Documentation/agent_rules.md` — **This file** (Operating rules & constraints).
* `Documentation/agents_week_1.md` — Week 1 progress tracker, milestone checklists, and current status.
* `Documentation/AI_Documentation/session_log_post_checkpoint.md` — Active post-checkpoint audit log (legacy `session_log.md` archived).
* `Documentation/ECE385_Final_Project_Proposal.pdf` — Official signed project proposal.
