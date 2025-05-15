#include <math.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include <stdio.h>
#include <time.h> //sleep function
#include <gpio.h> //control input/output pins - gpio_init gpio_put

#define SAMPLE_RATE 8000    // 8kHz sample rate
#define FREQUENCY 440       // A4/440hz
#define GPIO_BASE 0         // beginning of pins
#define PI 3.14159265

// generate 8-bit unsigned integer
uint8_t float_to_byte(float a) {
    a = (a + 1.0f) / 2.0f;   // Convert from [-1,1] to [0,1]
    return (uint8_t)(a * 255);
}

// sine wave 
uint8_t sine_wave(float phase) {
    float value = sinf(2.0f * PI * phase);  // phase in [0,1]
    return float_to_byte(value);
}

// Generate square wave value
uint8_t square_wave(float phase) {
    float value = (phase < 0.5f) ? 1.0f : -1.0f;
    return float_to_byte(value);
}

// Generate sawtooth wave value
uint8_t sawtooth_wave(float phase) {
    float value = 2.0f * phase - 1.0f;  // maps [0,1] to [-1,1]
    return float_to_byte(value);
}

// Output byte to GPIO 0–7
void output_byte(uint8_t value) {
    gpio_put_masked(0xFF, value);  // Set bits 0-7
}

int main() {
    stdio_init_all();

    // GPIO 0–7 
    for (int i = 0; i < 8; i++) {
        gpio_init(GPIO_BASE + i);
        gpio_set_dir(GPIO_BASE + i, GPIO_OUT);
    }

    const float samples_per_cycle = SAMPLE_RATE / (float)FREQUENCY;
    int sample_index = 0;

    while (true) {
        // phases 0 to 1 over one cycle
        float phase = (float)sample_index / samples_per_cycle;
        if (phase >= 1.0f) {
            sample_index = 0;
            phase = 0.0f;
        }

        // Choose waveform:
        // uint8_t value = sine_wave(phase);
        // uint8_t value = square_wave(phase);
        uint8_t value = sawtooth_wave(phase);  // comment out as change

        output_byte(value);
        sample_index++;

        sleep_us(1000000 / SAMPLE_RATE);  // 125 µs for 8 kHz
    }

    return 0;
}
