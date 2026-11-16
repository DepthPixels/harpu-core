# Verilator + SDL2 Makefile for HARPU 3D Raymarching Simulator

VERILATOR = verilator
VERILATOR_FLAGS = -cc --exe -O3 --x-assign fast --x-initial fast --noassert -Wall -Wno-fatal -Wno-WIDTH -Wno-CASEINCOMPLETE

# Hardware Sources Directory
HDL_DIR = ../Final_Project/Final_Project.srcs/sources_1/new

SRCS = sim_top.sv \
       $(HDL_DIR)/raymarch_core.sv \
       $(HDL_DIR)/carve_controller.sv \
       $(HDL_DIR)/sdf_scene.sv \
       $(HDL_DIR)/math_sqrt.sv \
       $(HDL_DIR)/sphere_shader.sv \
       $(HDL_DIR)/ray_gen.sv \
       $(HDL_DIR)/lut_inv_sqrt.sv

CPP_SRC = sim_main.cpp

# SDL2 Flags (auto-detect via sdl2-config, pkg-config, or explicit MSYS2 UCRT64/MINGW64 paths)
MSYS_INCS = -I/ucrt64/include/SDL2 -I/mingw64/include/SDL2 -I/ucrt64/include -I/mingw64/include \
            -I"C:/msys64/ucrt64/include/SDL2" -I"C:/msys64/mingw64/include/SDL2"
MSYS_LIBS = -L/ucrt64/lib -L/mingw64/lib -L"C:/msys64/ucrt64/lib" -L"C:/msys64/mingw64/lib" \
            -lmingw32 -lSDL2main -lSDL2 -mconsole

SDL_CFLAGS := $(shell sdl2-config --cflags 2>/dev/null || pkg-config --cflags sdl2 2>/dev/null || echo $(MSYS_INCS))
SDL_LIBS   := $(shell sdl2-config --libs 2>/dev/null || pkg-config --libs sdl2 2>/dev/null || echo $(MSYS_LIBS))

# Pass C++ compiler flags into Verilator
CXXFLAGS = -O3 -march=native -std=c++17 $(SDL_CFLAGS)
LDFLAGS  = $(SDL_LIBS)

.PHONY: all run clean

all: obj_dir/Vsim_top

obj_dir/Vsim_top: $(SRCS) $(CPP_SRC)
	$(VERILATOR) $(VERILATOR_FLAGS) \
		-CFLAGS "$(CXXFLAGS)" \
		-LDFLAGS "$(LDFLAGS)" \
		--top-module sim_top \
		$(SRCS) $(CPP_SRC)
	$(MAKE) -j -C obj_dir -f Vsim_top.mk OPT_FAST="-O3 -march=native" Vsim_top

run: all
	./obj_dir/Vsim_top

clean:
	rm -rf obj_dir
