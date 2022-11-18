#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "pio_i2c.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "registers.h"
#include "adps_registers.h"
#include "C:\picoo\pico-sdk\src\boards\include\boards\adafruit_qtpy_rp2040.h"
#include "ws2812.h"
#include "ws2812.pio.h"

#define PIN_SDA 22
#define PIN_SCL 23

#define IS_RGBW true
#define NUM_PIXELS 150
#define PICO_DEFAULT_WS2812_POWER_PIN 11

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

void set_neopixel_color(uint32_t color_num)
{
    uint32_t r_num = color_num >> 16;
    uint32_t g_num = color_num << 16;
    g_num = g_num >> 24;
    uint32_t b_num = color_num << 24;
    b_num = b_num >> 24;
    uint32_t color_f = ((r_num << 8) |
                            (g_num << 16)|
                            (b_num));
    
    printf("The Colour Packet to ws2812(grb): 0x%06x\n", (color_f));                   
    pio_sm_put_blocking(pio0, 0, color_f << 8u);
}

void config_adps(PIO pio, uint sm){
    // to power on APDS Sensor
    // The register address for the slave needs to be prepended to the data.
    uint8_t txbuf[2] = {0};

    // Setting Color Integration time to '1' i.e. 256 = 0xFF
    txbuf[0] = ATIME_REGISTER;
    txbuf[1] = (uint8_t)(0xFF);
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, txbuf, 2);

    // Config the Cotrol Register.
    txbuf[0] = ADPS_CONTROL_ONE_REGISTER;
    txbuf[1] = ADPS_CONTROL_ONE_AGAIN;
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, txbuf, 2);

    // Enable Ambient Light and Proximity Sensor
    txbuf[0] = ADPS_ENABLE_REGISTER;
    txbuf[1] = ADPS_ENABLE_PON | ADPS_ENABLE_AEN | ADPS_ENABLE_PEN;
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, txbuf, 2);
}

void adps_read(PIO pio, uint sm, uint8_t reg_addr, uint8_t *rxbuf, uint num_bytes) {
    // Read from `reg_addr`.
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, &reg_addr, 1);  
    pio_i2c_read_blocking(pio, sm, ADPS_ADDRESS, rxbuf, num_bytes);
}

uint32_t read_prox_and_color(PIO pio, uint sm)
{
    // Check the status register, to know if we can read the values
    // from the ALS and Proximity engine.
    uint8_t rxbuf[1] = {0};
    adps_read(pio, sm, STATUS_REGISTER, rxbuf, 1);
    adps_read(pio, sm, ID_REGISTER, rxbuf, 1);

    // Initialize Color Data
    uint16_t c_val = 0;
    uint16_t r_val = 0;
    uint16_t g_val = 0;
    uint16_t b_val =0;

    // Use the mask to check if our Proximity and color data is ready to be read.
    uint8_t data_arr[8] = {0};
    if ((rxbuf[0] & STATUS_REGISTER_PVALID) == STATUS_REGISTER_PVALID) {
        adps_read(pio, sm, PROXIMITY_DATA_REGISTER, data_arr, 1);
        printf("The Proximity Data : %d\n", data_arr[0] - 230);
    } 
    if ((rxbuf[0] & STATUS_REGISTER_AVALID) == STATUS_REGISTER_AVALID) {
        adps_read(pio, sm, RGBC_DATA_REGISTER_CDATAL, data_arr, 8);
        c_val = (data_arr[1] << 8 | data_arr[0]); 
        r_val = (data_arr[3] << 8 | data_arr[2]); 
        g_val = (data_arr[5] << 8 | data_arr[4]); 
        b_val = (data_arr[7] << 8 | data_arr[6]); 
        printf("The Color Data : (%d, %d, %d, %d)\n", r_val, g_val, b_val, c_val);
    }
    uint32_t final_color_packet = 0;
    if ((r_val > g_val) && (r_val > b_val)) {
        final_color_packet = ((uint8_t)((r_val*255) / 65536) << 16);
    } else if ((g_val > r_val) && (g_val > b_val)) {
        final_color_packet = ((uint8_t)((g_val*255) / 65536) << 8);
    } else if ((b_val > r_val) && (b_val > g_val)) 
    {
        final_color_packet = (uint8_t)((b_val*255) / 65536);
    }
    return final_color_packet;
}

int main() {
    const uint POWER_PIN_NAME = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POWER_PIN_NAME);
    gpio_set_dir(POWER_PIN_NAME, GPIO_OUT);
    gpio_put(POWER_PIN_NAME, 1);
    stdio_init_all();
    
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    PIO pio_1 = pio1;//changed from pio0 to pio1
    uint sm_1 = 1;
    uint offset_1 = pio_add_program(pio_1, &i2c_program);
    i2c_program_init(pio_1, sm_1, offset_1, PIN_SDA, PIN_SCL);
    
    // Wait until USB is connected.
    while(!stdio_usb_connected());

    printf("Starting PIO I2C ADPS9960 Interface\n");

    // Configure the ADPS Sensor.
    config_adps(pio_1, sm_1);
    
    // Initialize the Color Packet
    uint32_t color_data = 0;

    while(1) {
        // Call the read_prox_and_color function
        color_data = read_prox_and_color(pio_1, sm_1);
        printf("The Color Packet to pio(rgb): 0x%06x\n", color_data);
        set_neopixel_color(color_data);
        sleep_ms(500);
        set_neopixel_color(0);
    }
 
    return 0;
}
