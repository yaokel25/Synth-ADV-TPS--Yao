#include <stdlib.h>
#include <math.h>
#include <pciprop.h>

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

    