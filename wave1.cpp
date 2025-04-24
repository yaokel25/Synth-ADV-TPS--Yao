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

    
