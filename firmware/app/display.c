#include <stdint.h>
#include <stdbool.h>
#include "font.h"
#include <string.h>

uint8_t framebuffer[512];

void set_pixel(uint8_t x, uint8_t y, bool on) {
    uint16_t byte_idx = x + (y/8) * 128;
    uint8_t bit_idx = y % 8;
    if (on)
        framebuffer[byte_idx] |= (1 << bit_idx);
    else 
        framebuffer[byte_idx] &= ~(1 << bit_idx);
}

void draw_char(uint8_t cx, uint8_t cy, char c) {
    if (c < 32 || c > 127) return;

    uint16_t offset = (c - 32) * 5;

    for (uint8_t col = 0; col < 5; col++) {
        uint8_t column_bits = font[offset + col];

        for (uint8_t row = 0; row < 7; row++) {
            bool pixel_on = (column_bits >> row) & 1;
            set_pixel(cx + col, cy + row, pixel_on);
        }
    }
}

void draw_char_without_offset(uint8_t cx, uint8_t cy, char c) {
    if (c > 127) return;

    uint16_t offset = (c) * 5;

    for (uint8_t col = 0; col < 5; col++) {
        uint8_t column_bits = font[offset + col];

        for (uint8_t row = 0; row < 7; row++) {
            bool pixel_on = (column_bits >> row) & 1;
            set_pixel(cx + col, cy + row, pixel_on);
        }
    }
}

void draw_string(uint8_t x, uint8_t y, const char *str) {
    while (*str) {
        draw_char(x, y, *str);
        x +=6;
        str++;
    }
}

void draw_string_wo(uint8_t x, uint8_t y, const char *str) {
    while (*str) {
        draw_char_without_offset(x, y, *str);
        x +=6;
        str++;
    }
}

void display_clear(void) {
    memset(framebuffer, 0, sizeof(framebuffer));
}