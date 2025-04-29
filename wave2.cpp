#include "pico/stdlib.h"
#include <math.h>

#define SAMPLE_RATE 8000        // 8 kHz (playable, but not too fast for delays)
#define FREQUENCY 440           // A4 note
#define GPIO_BASE 0             // GPIO 0–7 for DAC
#define PI 3.14159265

int main() {
    stdio_init_all();

    // GPIO 0-7 as outputs
    for (int i = 0; i < 8; i++) {
        gpio_init(GPIO_BASE + i);
        gpio_set_dir(GPIO_BASE + i, GPIO_OUT);
    }

    const float samples_per_cycle = SAMPLE_RATE / FREQUENCY;

    while (true) {
        for (int i = 0; i < samples_per_cycle; i++) {
            float phase = (float)i / samples_per_cycle;

            // Square wave: high for half cycle, low for half
            uint8_t value = (phase < 0.5) ? 255 : 0;

            // Output to GPIOs
            gpio_put_masked(0xFF, value);  // 0xFF mask for GPIO 0–7

            // Wait 1/sample_rate seconds
            sleep_us(1000000 / SAMPLE_RATE);
        }
    }

    return 0;
}
