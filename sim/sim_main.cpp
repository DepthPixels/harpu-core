#include <iostream>
#include <iomanip>
#include <cstdint>
#include <chrono>

#if defined(__has_include)
  #if __has_include(<SDL2/SDL.h>)
    #include <SDL2/SDL.h>
  #else
    #include <SDL.h>
  #endif
#else
  #include <SDL2/SDL.h>
#endif

#include "Vsim_top.h"
#include "verilated.h"

// Required by Verilator for simulation time tracking
static uint64_t main_time = 0;
double sc_time_stamp() {
    return (double)main_time;
}

// Screen specifications (identical to Urbana hardware)
static const int FB_WIDTH   = 320;
static const int FB_HEIGHT  = 240;
static const int WIN_WIDTH  = 640;
static const int WIN_HEIGHT = 480;

// USB HID Keycodes matching MicroBlaze firmware
enum USB_HID_Keycode {
    KEY_NONE  = 0x00,
    KEY_A     = 0x04,
    KEY_D     = 0x07,
    KEY_E     = 0x08,
    KEY_F     = 0x09,
    KEY_Q     = 0x14,
    KEY_R     = 0x15,
    KEY_S     = 0x16,
    KEY_W     = 0x1A,
    KEY_SPACE = 0x2C
};

static uint8_t translate_sdl_key(SDL_Keycode key) {
    switch (key) {
        case SDLK_w:      return KEY_W;
        case SDLK_s:      return KEY_S;
        case SDLK_a:      return KEY_A;
        case SDLK_d:      return KEY_D;
        case SDLK_e:      return KEY_E;
        case SDLK_q:      return KEY_Q;
        case SDLK_r:      return KEY_R;
        case SDLK_f:      return KEY_F;
        case SDLK_SPACE:  return KEY_SPACE;
        default:          return KEY_NONE;
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    std::cout << "======================================================" << std::endl;
    std::cout << " HARPU 3D Raymarching Simulator (Verilator + SDL2)    " << std::endl;
    std::cout << " Controls:                                            " << std::endl;
    std::cout << "   [W/S] Move Carve Y (Up/Down)                       " << std::endl;
    std::cout << "   [A/D] Move Carve X (Left/Right)                    " << std::endl;
    std::cout << "   [Q/E] Move Carve Z (Near/Far)                      " << std::endl;
    std::cout << "   [R/F] Radius (Expand/Shrink)                       " << std::endl;
    std::cout << "   [Space] Toggle CSG Carving                         " << std::endl;
    std::cout << "   [ESC] Exit Simulator                               " << std::endl;
    std::cout << "======================================================" << std::endl;

    std::cout << "[1/4] Initializing SDL2..." << std::flush;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << " FAIL: " << SDL_GetError() << std::endl;
        return 1;
    }
    std::cout << " OK." << std::endl;

    std::cout << "[2/4] Creating Window (" << WIN_WIDTH << "x" << WIN_HEIGHT << ")..." << std::flush;
    SDL_Window* window = SDL_CreateWindow(
        "HARPU 3D Raymarching Hardware Preview [11 FPS Target]",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_WIDTH, WIN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        std::cerr << " FAIL: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    std::cout << " OK." << std::endl;

    std::cout << "[3/4] Creating Renderer & Framebuffer Texture..." << std::flush;
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "0"); // Disable VSync to prevent DWM/GPU throttling the simulation
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); // Clean 2x hardware pixel look

    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        FB_WIDTH, FB_HEIGHT
    );
    std::cout << " OK." << std::endl;

    // Precompute 12-bit RGB (4:4:4) to 32-bit ARGB (8:8:8:8) lookup table
    uint32_t color_lut[4096];
    for (int i = 0; i < 4096; i++) {
        uint8_t r = (i >> 8) & 0xF;
        uint8_t g = (i >> 4) & 0xF;
        uint8_t b = i & 0xF;
        r = (r << 4) | r;
        g = (g << 4) | g;
        b = (b << 4) | b;
        color_lut[i] = (0xFF << 24) | (r << 16) | (g << 8) | b;
    }

    uint32_t fb_pixels[FB_WIDTH * FB_HEIGHT];
    for (int i = 0; i < FB_WIDTH * FB_HEIGHT; i++) {
        fb_pixels[i] = 0xFF101020; // Background navy
    }

    // Initial presentation so window is never blank/black
    SDL_UpdateTexture(texture, NULL, fb_pixels, FB_WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    std::cout << "[4/4] Powering on Verilated Hardware Core..." << std::flush;
    // Instantiate Verilated DUT
    Vsim_top* top = new Vsim_top;

    // Power-on Reset Sequence
    top->clk = 0;
    top->reset = 1;
    top->keycode = 0;
    for (int i = 0; i < 10; i++) {
        top->clk = !top->clk;
        top->eval();
    }
    top->reset = 0;
    std::cout << " OK." << std::endl;
    std::cout << ">> Simulator running! Press ESC in the SDL window to exit. <<" << std::endl;

    bool running = true;
    uint8_t current_keycode = KEY_NONE;

    auto last_fps_time = std::chrono::steady_clock::now();
    auto last_render_time = std::chrono::steady_clock::now();
    int frames_rendered = 0;
    float current_fps = 0.0f;
    const int BATCH_SIZE = 1024;

    while (running && !Verilated::gotFinish()) {
        // Poll SDL Events once per batch (every 1024 clock cycles)
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                } else {
                    current_keycode = translate_sdl_key(event.key.keysym.sym);
                }
            } else if (event.type == SDL_KEYUP) {
                if (translate_sdl_key(event.key.keysym.sym) == current_keycode) {
                    current_keycode = KEY_NONE;
                }
            }
        }
        top->keycode = current_keycode;

        bool frame_done_flag = false;

        // Step hardware in tight batch to maximize CPU instruction cache and branch prediction
        for (int step = 0; step < BATCH_SIZE; ++step) {
            top->clk = 1;
            top->eval();

            if (top->fb_we) {
                uint32_t addr = top->fb_addr;
                if (addr < (uint32_t)(FB_WIDTH * FB_HEIGHT)) {
                    fb_pixels[addr] = color_lut[top->fb_din & 0x0FFF];
                }
            }

            if (top->frame_done) {
                frame_done_flag = true;
            }

            top->clk = 0;
            top->eval();
        }
        main_time += (BATCH_SIZE * 2);

        auto now = std::chrono::steady_clock::now();

        // Progressive scanline blit throttled to ~30 FPS (33ms) or immediate upon frame completion
        if (frame_done_flag || (now - last_render_time) >= std::chrono::milliseconds(33)) {
            last_render_time = now;
            SDL_UpdateTexture(texture, NULL, fb_pixels, FB_WIDTH * sizeof(uint32_t));
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }

        if (frame_done_flag) {
            frames_rendered++;
            std::chrono::duration<float> elapsed = now - last_fps_time;
            if (elapsed.count() >= 0.5f) {
                current_fps = frames_rendered / elapsed.count();
                frames_rendered = 0;
                last_fps_time = now;

                float cx = (float)(int16_t)top->carve_x / 256.0f;
                float cy = (float)(int16_t)top->carve_y / 256.0f;
                float cz = (float)(int16_t)top->carve_z / 256.0f;
                float cr = (float)(int16_t)top->carve_radius / 256.0f;

                char title[128];
                snprintf(title, sizeof(title),
                    "HARPU 3D | %.1f FPS | Carve:[%.2f, %.2f, %.2f] R:%.2f %s",
                    current_fps, cx, cy, cz, cr, top->carve_en ? "[ON]" : "[OFF]");
                SDL_SetWindowTitle(window, title);
            }
        }
    }

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete top;
    return 0;
}
