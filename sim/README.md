# HARPU 3D Raymarching Simulator (Verilator + SDL2)

Live interactive hardware simulation of the HARPU FPGA raymarching processor.

Compiles synthesizable SystemVerilog HDL directly into native multithreaded x86 machine code via Verilator, displaying the $320 \times 240$ dual-port BRAM framebuffer upscaled $2\times$ ($640 \times 480$) in an SDL2 window.

---

## Prerequisites (MSYS2 UCRT64)

Install the required packages in MSYS2 (`C:\msys64\ucrt64.exe`):
```bash
pacman -S mingw-w64-ucrt-x86_64-verilator mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-SDL2 make
```

---

## How to Run

### Method 1: Double-Click Batch File
Simply double-click `run_sim.bat` inside this `sim/` folder.

### Method 2: From MSYS2 UCRT64 Terminal
```bash
cd "/f/ECE 385 Final Project/sim"
make run
```

---

## Controls

The simulator intercepts keyboard events and translates them into identical USB HID keycodes fed to `carve_controller.sv`:

| Key | Action | Hardware Keycode |
| :--- | :--- | :--- |
| **W** | Move Carve Y (+) (Up) | `8'h1A` |
| **S** | Move Carve Y (-) (Down) | `8'h16` |
| **A** | Move Carve X (-) (Left) | `8'h04` |
| **D** | Move Carve X (+) (Right) | `8'h07` |
| **Q** | Move Carve Z (-) (Near/Front) | `8'h14` |
| **E** | Move Carve Z (+) (Far/Back) | `8'h08` |
| **R** | Expand Hole Radius ($R$) | `8'h15` |
| **F** | Shrink Hole Radius ($R$) | `8'h09` |
| **Space** | Toggle CSG Carve (ON / OFF) | `8'h2C` |
| **Esc** | Exit Simulator | — |

---

## Window Telemetry
The window title continuously displays live simulation telemetry:
`HARPU 3D | 45.2 FPS | Carve:[0.35, 0.35, -0.85] R:0.35 [ON]`
