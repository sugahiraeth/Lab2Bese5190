#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "D:\Course Stuff\Fall'22\ESE 519\lab\SDK\pico-sdk\src\boards\include\boards\adafruit_qtpy_rp2040.h"
#define PICO_PIN 23
#define blue_led 
#define red_led 
const uint led_pin = PICO_PIN;
#define IS_RGBW true
Pio stuff
PIO pio = pio0;
int sm = 0;


void morseCode(char *input);

//Sub-function to toggle leds
void blink_dot(uint led_pin){
    pio_sm_put(pio,sm, 1);
    sleep_ms(200);
    pio_sm_put(pio,sm, 0);
    sleep_ms(500);
}

void blink_dash(uint led_pin){
    pio_sm_put(pio,sm, 1);
    sleep_ms(1000);
    pio_sm_put(pio,sm, 0);
    sleep_ms(500);
}


// function to encode a alphabet as
// Morse code
void morseEncode(char x)
{
    switch (x) {
    case 'a':
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf(".-\n");
        return;
    case 'b':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("-...\n");
        return;
    case 'c':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf("-.-.\n");
        return;
    case 'd':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("-..\n");
        return;
    case 'e':
        blink_dot(led_pin);
        printf(".\n");
        return;
    case 'f':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf("..-.\n");
        return;
    case 'g':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf("--.\n");
        return;
    case 'h':
        blink_dot(led_pin);
        blink_dot(led_pin); 
        blink_dot(led_pin);
        blink_dot(led_pin); 
        printf("....\n");
        return;
    case 'i':
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("..\n");
        return;
    case 'j':
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf(".---\n");
        return;
    case 'k':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf("-.-\n");
        return;
    case 'l':
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf(".-..\n");
        return;
    case 'm':
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf("--\n");
        return;
    case 'n':
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf("-.\n");
        return;
    case 'o':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf("---\n");
        return;
    case 'p':
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf(".--.\n");
        return;
    case 'q':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf("--.-\n");
        return;
    case 'r':
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf(".-.\n");
        return;
    case 's':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("...\n");
        return;
    case 't':
        blink_dash(led_pin);
        printf("-\n");
        return;
    case 'u':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf("..-\n");
        return;
    case 'v':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf("...-\n");
        return;
    case 'w':
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf(".--\n");
        return;
    case 'x':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf("-..-\n");
        return;
    case 'y':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf("-.--\n");
        return;
    case 'z':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("--..\n");
        return;
    case '1':
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf(".----\n");
        return;
    case '2':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf("..---\n");
        return;
    case '3':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf("...--\n");
        return;
    case '4':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dash(led_pin);
        printf("....-\n");
        return;
    case '5':
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf(".....\n");
        return;
    case '6':
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("-....\n");
        return;
    case '7':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("--...\n");
        return;
    case '8':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        blink_dot(led_pin);
        printf("---..\n");
        return;
    case '9':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dot(led_pin);
        printf("----.\n");
        return;
    case '0':
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        blink_dash(led_pin);
        printf("-----\n");
        return;
    default:
        printf("Invalid character\n");
        return;
    }
}

void morseCode(char *input)
{

    // character by character print
    // Morse code
    int i;
    while(input[i]!='\0'){
        morseEncode(input[i]);
        i++;
    }
}

int main() {

    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, PICO_PIN, 800000, IS_RGBW);
    

    while(!stdio_usb_connected());
    while (true) 
    {
        char input;
        printf("Enter character:\n");
        scanf("%c",&input);
        printf("%c\n",input);
        sleep_ms(200);
        morseEncode(input);
        
    }
}
