# AI Agent Session Audit Log

This file maintains an ongoing record of file changes, terminal commands executed, architectural decisions made, and debugging notes across agent threads for later reference during ECE 385 final report preparation.

---

## Session: 2026-11-08 to 2026-11-10 (Project Inception & Week 1 Setup)

### Summary of Actions
* Evaluated initial project proposal against Urbana board hardware specs (`XC7S50-CSGA324-1`) and ECE 385 grading rubric.
* Converted project architecture to an implicit 3D SDF raymarcher with dynamic CSG carving, 8-droplet PBD fluid simulation, and procedural Gyroid caverns.
* Parameterized internal resolution ($320 \times 180$ / $320 \times 240$ upscaled to $640 \times 480$ @ 60 Hz) to guarantee locked 60 FPS timing within BRAM budget.
* Formatted, verified, and exported official project proposal documents (`.md`, `.html`, `.pdf`).
* Organized project directory structure (`Documentation/`, `Documentation/AI_Documentation/`).
* Initialized local Git repository on branch `main`, verified `.gitignore` against Vivado and Vitis build paths, and linked remote to `https://github.com/DepthPixels/harpu-core.git`.
* Codified agent guidelines (`agent_rules.md`) and Week 1 progress tracking (`agents_week_1.md`).

### Files Created / Modified
* `Documentation/ECE385_Final_Project_Proposal.md` — Complete ECE 385 project proposal.
* `Documentation/ECE385_Final_Project_Proposal.html` — Print-styled HTML proposal.
* `Documentation/ECE385_Final_Project_Proposal.pdf` — Compiled PDF proposal.
* `.gitignore` — Tailored ignore rules for Vivado (`.cache`, `.hw`, `.sim`, `.runs`) and Vitis (`.metadata`, `Debug/`, `Release/`).
* `Documentation/agent_rules.md` — AI agent rules (planning/debugging only, no unsolicited code, mandatory audit logging).
* `Documentation/agents_week_1.md` — Week 1 progress keeping and milestone checklist.
* `Documentation/AI_Documentation/session_log.md` — Initial audit log.

### Key Terminal Commands Run
```powershell
# Directory setup and file relocation
New-Item -ItemType Directory -Force 'F:\ECE 385 Final Project\Documentation'
Move-Item -Force 'F:\ECE 385 Final Project\ECE385_Final_Project_Proposal.*' 'F:\ECE 385 Final Project\Documentation\'

# Edge headless PDF compilation
& 'C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe' --headless --disable-gpu --no-sandbox --user-data-dir='F:\ECE 385 Final Project\.tmp_edge' --print-to-pdf='F:\ECE 385 Final Project\ECE385_Final_Project_Proposal.pdf' 'F:\ECE 385 Final Project\ECE385_Final_Project_Proposal.html'

# Git initialization & configuration
git init -b main
git config user.name 'pdeswal2'
git config user.email 'pdeswal2@illinois.edu'
git remote set-url origin https://github.com/DepthPixels/harpu-core.git
```

### Architectural Decisions & Debugging Notes
* **Resolution Budgeting:** Confirmed that native 720p raymarching requires $>500\text{ M}$ evaluations/sec, exceeding dual-core Spartan-7 limits. Internal buffer of $320 \times 240$ with $2\times$ hardware pixel doubling safely fits 60 FPS ($\approx 184\text{ M}$ evaluations/sec) and takes only $76.8\text{ KB}$ of BRAM.
* **Primitive Struct Sizing:** Corrected block diagram primitive descriptor from 64-bit to 128-bit to accommodate Capsule endpoints ($A, B$) and Sharp Box extents in fixed-point $Q8.8$.
* **Video Pipeline De-risking:** Standardized on verified RealDigital `hdmi_tx` IP (`encode.v` + `serdes_10_to_1.v`) at $640 \times 480$ @ 60 Hz to ensure video stability for the Nov 20 mid-checkpoint.
