#include <math.h>//wave functions like sin
#include <stdio.h>//input/output functions
#include "pico/stdlib.h"//pico sdk functions - input/output
#include <stdio.h>
#include <time.h> //sleep function
#include <gpio.h> //control input/output pins - gpio_init gpio_put

#define SAMPLE_RATE 8000        // samples per second (pitch and timing)
#define FREQUENCY 440           // frequency (A4 note or 440 Hz)
#define GPIO_BASE 0             // the starting GPIO pin (GPIO 0–7) for DAC
#define PI 3.14159265            //trig constant pi for calculations 

int main() {
    stdio_init_all();    //initialize
    uint8_t value;        //needed to hold output

    // GPIO 0-7 as outputs
    for (int i = 0; i < 8; i++) {
        gpio_init(GPIO_BASE + i);    //initialize the GPIO pins
        gpio_set_dir(GPIO_BASE + i, GPIO_OUT);    //set pins as output
    }

    const float samples_per_cycle = SAMPLE_RATE / FREQUENCY;    //calculates how many smaples are in 1 cycle of freq
    while(true){    //generate the sound
        for(int i =0; i < 8; i++){    //for every sample point in the wave
            float phase = ((float)i)/samples_per_cycle;

            //square
            if(phase < 0.5){
                value = 255; //high - all bits are 1
            }
            else{
                value = 0;    //low - all bits are 0
            }

            //output to gpio pins 0-7
            gpio_put_masked(0xFF, value);

            //wait for 1/samplr_rate seconds before next sample
            sleep_ms(1000000/SAMPLE_RATE);    //microseconds to milliseconds
            
        }

    }
    return 0;

}  
