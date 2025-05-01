#include <math.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include <stdio.h>
#include <time.h> //sleep function
#include <gpio.h> //control input/output pins - gpio_init gpio_put

#define SAMPLE_RATE 8000        // 8 kHz (playable, but not too fast for delays)
#define FREQUENCY 440           // A4 note
#define GPIO_BASE 0             // GPIO 0–7 for DAC
#define PI 3.14159265

int main() {
    stdio_init_all();
    uint8_t value;

    // GPIO 0-7 as outputs
    for (int i = 0; i < 8; i++) {
        gpio_init(GPIO_BASE + i);
        gpio_set_dir(GPIO_BASE + i, GPIO_OUT);
    }

    const float samples_per_cycle = SAMPLE_RATE / FREQUENCY;
    while(true){
        for(int i =0; i < 8; i++){
            float phase = (float)i /samples_per_cycle;

            //square
            if(phase < 0.5){
                value = 255; //byte so 0-255
            }
            else{
                value = 0;
            }

            //output
            gpio_put_masked(0xFF, value);

            //wait for 1/samplr_rate seconds
            sleep_ms(1000000/SAMPLE_RATE);
            
        }

    }
    return 0;

}  