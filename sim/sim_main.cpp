#include <iostream>
#include <iomanip>
#include <cstdint>
#include <chrono>
#include <algorithm>

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

static uint8_t axis_to_u8(int16_t val) {
    int shifted = ((int)val + 32768) >> 8;
    return (uint8_t)std::max(0, std::min(255, shifted));
}

static uint8_t trigger_to_u8(int16_t val) {
    int shifted = (int)val >> 7;
    return (uint8_t)std::max(0, std::min(255, shifted));
}

// Encode SDL D-Pad buttons into DualSense HID 4-bit hat value (0..7 clockwise from N, 8 = neutral)
static uint8_t encode_dpad(SDL_GameController* pad) {
    bool up    = SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_UP);
    bool down  = SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
    bool left  = SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
    bool right = SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);

    if (up && right)   return 1;
    if (up && left)    return 7;
    if (down && right) return 3;
    if (down && left)  return 5;
    if (up)            return 0;
    if (right)         return 2;
    if (down)          return 4;
    if (left)          return 6;
    return 8;
}

// Pack DualSense state into exact 64-bit usb_data_in format expected by carve_controller.sv
static uint64_t pack_gamepad_packet(SDL_GameController* pad, uint8_t strobe) {
    uint8_t lx = axis_to_u8(SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTX));
    uint8_t ly = axis_to_u8(SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTY));
    uint8_t rx = axis_to_u8(SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_RIGHTX));
    uint8_t ry = axis_to_u8(SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_RIGHTY));

    uint32_t stick_word = ((uint32_t)ry << 24) |
                          ((uint32_t)rx << 16) |
                          ((uint32_t)ly << 8)  |
                          ((uint32_t)lx);

    uint8_t lt   = trigger_to_u8(SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_TRIGGERLEFT));
    uint8_t rt   = trigger_to_u8(SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT));
    uint8_t dpad = encode_dpad(pad) & 0x0F;

    uint32_t btn_word = ((uint32_t)lt) |
                        ((uint32_t)rt << 8) |
                        ((uint32_t)dpad << 16);

    // PS5 DualSense mapping via SDL_GameController (X=Square, A=Cross, B=Circle, Y=Triangle)
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_X))             btn_word |= (1u << 20); // Square
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_A))             btn_word |= (1u << 21); // Cross
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_B))             btn_word |= (1u << 22); // Circle
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_Y))             btn_word |= (1u << 23); // Triangle
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_LEFTSHOULDER))  btn_word |= (1u << 24); // L1
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) btn_word |= (1u << 25); // R1
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_LEFTSTICK))     btn_word |= (1u << 26); // L3
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_RIGHTSTICK))    btn_word |= (1u << 27); // R3
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_BACK))          btn_word |= (1u << 28); // Share
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_START))         btn_word |= (1u << 29); // Options

    btn_word |= (1u << 30);                  // Is Gamepad = 1
    btn_word |= ((uint32_t)(strobe & 1) << 31); // Strobe

    return ((uint64_t)btn_word << 32) | (uint64_t)stick_word;
}

static SDL_GameController* open_first_controller() {
    for (int i = 0; i < SDL_NumJoysticks(); ++i) {
        if (SDL_IsGameController(i)) {
            SDL_GameController* pad = SDL_GameControllerOpen(i);
            if (pad) {
                std::cout << ">> Gamepad connected: " << SDL_GameControllerName(pad) << std::endl;
                return pad;
            }
        }
    }
    return nullptr;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    std::cout << "======================================================" << std::endl;
    std::cout << " HARPU 3D Raymarching Simulator (Verilator + SDL2)    " << std::endl;
    std::cout << " PS5 DualSense Controls (auto-detected):              " << std::endl;
    std::cout << "   [L-Stick] Move X/Y (or Light Azimuth/Elev)         " << std::endl;
    std::cout << "   [R-Stick] Radius (X) / Depth Z (Y)                 " << std::endl;
    std::cout << "   [Square] Mode | [Triangle/Cross] Carve | [O] Reset " << std::endl;
    std::cout << "   [L1/R1] Material Palette | [D-Pad] Modifiers       " << std::endl;
    std::cout << " Mouse / Keyboard Fallback:                           " << std::endl;
    std::cout << "   [Mouse] Pan/Toggle/Z/R | [WASD/QE/RF/Space] | [ESC]" << std::endl;
    std::cout << "======================================================" << std::endl;

    std::cout << "[1/4] Initializing SDL2 (Video + GameController)..." << std::flush;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0) {
        std::cerr << " FAIL: " << SDL_GetError() << std::endl;
        return 1;
    }
    std::cout << " OK." << std::endl;

    SDL_GameController* gamepad = open_first_controller();

    std::cout << "[2/4] Creating Window (" << WIN_WIDTH << "x" << WIN_HEIGHT << ")..." << std::flush;
    SDL_Window* window = SDL_CreateWindow(
        "HARPU 3D Raymarching Hardware Preview [24-Bit TrueColor]",
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
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "0");
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        FB_WIDTH, FB_HEIGHT
    );
    std::cout << " OK." << std::endl;

    uint32_t fb_pixels[FB_WIDTH * FB_HEIGHT];
    for (int i = 0; i < FB_WIDTH * FB_HEIGHT; i++) {
        fb_pixels[i] = 0xFF101820;
    }

    SDL_UpdateTexture(texture, NULL, fb_pixels, FB_WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    std::cout << "[4/4] Powering on Verilated Hardware Core..." << std::flush;
    Vsim_top* top = new Vsim_top;

    // Power-on Reset Sequence
    top->clk = 0;
    top->reset = 1;
    top->usb_data = 0;
    for (int i = 0; i < 10; i++) {
        top->clk = !top->clk;
        top->eval();
    }
    top->reset = 0;
    std::cout << " OK." << std::endl;
    std::cout << ">> Simulator running! Press ESC in the SDL window to exit. <<" << std::endl;

    bool running = true;
    uint8_t current_keycode = KEY_NONE;
    uint8_t mouse_strobe = 0;
    uint8_t gamepad_strobe = 0;
    uint8_t mouse_buttons = 0;
    int accum_dx = 0;
    int accum_dy = 0;

    auto last_fps_time = std::chrono::steady_clock::now();
    auto last_render_time = std::chrono::steady_clock::now();
    int frames_rendered = 0;
    float current_fps = 0.0f;
    const int BATCH_SIZE = 1024;
    const char* mode_names[4] = {"CARVE", "LIGHT", "CAM", "MODE3"};

    while (running && !Verilated::gotFinish()) {
        SDL_Event event;
        bool mouse_active = false;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_CONTROLLERDEVICEADDED) {
                if (!gamepad) {
                    gamepad = open_first_controller();
                }
            } else if (event.type == SDL_CONTROLLERDEVICEREMOVED) {
                if (gamepad && event.cdevice.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(gamepad))) {
                    std::cout << ">> Gamepad disconnected." << std::endl;
                    SDL_GameControllerClose(gamepad);
                    gamepad = open_first_controller();
                }
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
            } else if (event.type == SDL_MOUSEMOTION) {
                accum_dx += event.motion.xrel;
                accum_dy += event.motion.yrel;
                mouse_active = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT)   mouse_buttons |= 0x01;
                if (event.button.button == SDL_BUTTON_RIGHT)  mouse_buttons |= 0x02;
                if (event.button.button == SDL_BUTTON_MIDDLE) mouse_buttons |= 0x04;
                mouse_active = true;
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT)   mouse_buttons &= ~0x01;
                if (event.button.button == SDL_BUTTON_RIGHT)  mouse_buttons &= ~0x02;
                if (event.button.button == SDL_BUTTON_MIDDLE) mouse_buttons &= ~0x04;
                mouse_active = true;
            }
        }

        if (gamepad) {
            gamepad_strobe ^= 1;
            top->usb_data = pack_gamepad_packet(gamepad, gamepad_strobe);
        } else if (mouse_active) {
            mouse_strobe ^= 1;
            int8_t dx = (int8_t)std::max(-128, std::min(127, accum_dx));
            int8_t dy = (int8_t)std::max(-128, std::min(127, accum_dy));
            accum_dx = 0;
            accum_dy = 0;

            top->usb_data = ((uint64_t)mouse_strobe << 25) |
                            ((uint64_t)1 << 24)            | // is_mouse = 1
                            ((uint64_t)mouse_buttons << 16) |
                            ((uint64_t)(uint8_t)dy << 8)   |
                            ((uint64_t)(uint8_t)dx);
        } else if (current_keycode != KEY_NONE) {
            top->usb_data = (uint64_t)current_keycode; // is_mouse = 0, is_gamepad = 0
        } else {
            top->usb_data = 0;
        }

        bool frame_done_flag = false;

        for (int step = 0; step < BATCH_SIZE; ++step) {
            top->clk = 1;
            top->eval();

            if (top->fb_we) {
                uint32_t addr = top->fb_addr;
                if (addr < (uint32_t)(FB_WIDTH * FB_HEIGHT)) {
                    fb_pixels[addr] = 0xFF000000u | (top->fb_din & 0x00FFFFFFu);
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

                char title[160];
                snprintf(title, sizeof(title),
                    "HARPU 3D | %.1f FPS | %s | Mat:%u | Carve:[%.2f, %.2f, %.2f] R:%.2f %s",
                    current_fps, mode_names[top->control_mode & 3], top->sphere_material & 3,
                    cx, cy, cz, cr, top->carve_en ? "[ON]" : "[OFF]");
                SDL_SetWindowTitle(window, title);
            }
        }
    }

    if (gamepad) SDL_GameControllerClose(gamepad);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete top;
    return 0;
}
