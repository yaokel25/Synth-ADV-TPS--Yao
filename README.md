# Synth-ADV-TPS--Yao
update 4/25:
const int SAMPLE_RATE = 44100;
Audio is made up of samples played back quickly—44,100 per second
- audio will contain 44100 samples for every second of audio
- float t = (float)i /sample_rate;
- every each sample i, convert its index into a time value t in seconds.
- example:
  - i = 0 , t=0
  - i= 44100 t = 1.0 sec
- sound waves are time-based
- sin(2 * M_PI * FREQUENCY * t)

calculates the value of a sine wave at specific point in time
- sin() -sine function
- oscillates between -1 and 1
- 2 * M_PI converts frequency into angular frequency
- makes sine wave complete a full cycle (2π radians) every 1/frequency seconds.
- 2 * M_PI * FREQUENCY * t gives angle (in radians) at time t
  If sine positive output 255, max voltage on DAC
  if sinenegative output 0, min voltage

-high-low-high-low pattern at 440 Hz

TODO: make compatible with rasbpi with library? add other waves like sine waves



