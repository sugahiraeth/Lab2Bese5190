/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "D:\Course Stuff\Fall'22\ESE 519\lab\SDK\pico-sdk\src\boards\include\boards\adafruit_qtpy_rp2040.h"
#define IS_RGBW true
#define NUM_PIXELS 150
#define QTPY_GPIO0_REG ((volatile uint32_t *)(IO_BANK0_BASE + 0x004))

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else

// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif
#define PICO_DEFAULT_WS2812_POWER_PIN 11
#define QTPY_BOOT_PIN 21

typedef          uint32_t   VALUE;
typedef volatile uint32_t * ADDRESS;

VALUE register_read(ADDRESS address) {
    return *address;
}
void register_write(ADDRESS address, VALUE value) {
    *address = value;
}


static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

typedef struct{
    uint32_t val;
} status;

int main() {
    //set_sys_clock_48();
    const uint POW_PIN = PICO_DEFAULT_WS2812_POWER_PIN;
    const uint bootpin = QTPY_BOOT_PIN;
    gpio_init(POW_PIN);
    gpio_set_dir(POW_PIN, GPIO_OUT);
    gpio_put(POW_PIN,1);
    stdio_init_all();

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    uint32_t value_input;
    uint32_t bit_alias_input;

    while(!stdio_usb_connected());
    while (1){
            uint32_t reg_value = register_read(QTPY_GPIO0_REG);
            printf("Register Value this instant: 0x%08x\n", reg_value);
            printf("Enter Value to write in register:\n");
            scanf("%x", &value_input);
            register_write(QTPY_GPIO0_REG, value_input);
            reg_value = register_read(QTPY_GPIO0_REG);
            printf("Register Value this instant: 0x%08x\n", reg_value);
            printf("One cycle complete\n");
            sleep_ms(1000);
    }
}
