#include <iostream>
#include <fstream>
#include <cmath>

const int SAMPLE_RATE = 44100; // samples per second
const float DURATION = 2.0;    // 2 seconds
const int FREQUENCY = 440;     // Hz (A4 note)
const int AMPLITUDE = 127;     // Half of 255 (8-bit R-2RDAC)

using namespace std;
int main() {//generate square wave
    ofstream out("square_wave.raw", std::ios::binary);//generate .wave file
int samples = SAMPLE_RATE * DURATION;

    for (int i = 0; i < samples; i++) {
        float t = (float)i / SAMPLE_RATE;
        int value = (sin(2 * M_PI * FREQUENCY * t) > 0) ? 255 : 0; // square wave
        out.put((char)value);
    }

    out.close();
    cout << "Output done \n";
    return 0;
}

    
