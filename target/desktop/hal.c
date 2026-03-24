#include "hal.h"
#include "display.h"
#include <stdio.h>
#include <SDL2/SDL.h>

#define SCALE 4
#define OLED_W 128
#define OLED_H 32

static SDL_Window   *window   = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture   = NULL;
static bool gpio_state[32]    = {0};

uint32_t hal_time_ms(void) {
    return SDL_GetTicks();
}

void hal_sleep_ms(uint32_t ms) {
    SDL_Delay(ms);
}

void hal_gpio_init(uint8_t pin, bool output) {
    // desktop doesn't need shit
}

void hal_gpio_set(uint8_t pin, bool value) {
    if (pin < 32) gpio_state[pin] = value;
}

bool hal_gpio_get(uint8_t pin) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) exit(0);
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            gpio_state[5] = true;
        if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE)
            gpio_state[5] = false;
    }
    return (pin < 32) ? gpio_state[pin] : false;
}

void hal_display_init(void) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "noahshpad",
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        OLED_W * SCALE, OLED_H * SCALE,
        0
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        OLED_W,
        OLED_H
    );
}

void hal_display_flush(void) {
    uint32_t pixels[OLED_W * OLED_H];

    for (uint8_t x = 0; x < OLED_W; x++) {
        for (uint8_t y = 0; y < OLED_H; y++) {
            uint16_t byte_idx = x + (y / 8) * 128;
            uint8_t bit_idx = y % 8;
            bool on = (framebuffer[byte_idx] >> bit_idx) & 1;

            pixels[y * OLED_W + x] = on ? 0xFFFFFFFF
                                        : 0x000000FF;
        }
    }

    SDL_UpdateTexture(texture, NULL, pixels, OLED_W * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}