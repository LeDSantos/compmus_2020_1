#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../read_write_wav.h"
#include <cmath>
using namespace std;


// lets generate a oscillator with a single pure sine wave 
int main(int c, char** argv)
{
    const float duration = 4.0;//3.5; //seconds
    const float Fs = 44100; //sample rate (samples /second)
    const int buffer_len = round(duration*Fs); // samples
    float audio_buffer[buffer_len];

    // OSCILLATOR
    // sine wave
    float freq = 261.62; // C3 // Midi note 48
    float freq_origin = 261.62; // C3 // Midi note 48

    float amp = 0.8f;    
    for (int n=0; n<buffer_len; n++)
    {
       audio_buffer[n] = amp * (sin(2*M_PI*freq*(n/Fs)) + 2*M_PI*0.1*freq*(n/Fs))/2;
       freq=freq_origin-(n % 250);
       
    }

    string wav_name = "oscillator_" + std::to_string(freq) + "Hz.wav";
    write_wave_file (wav_name.c_str(), audio_buffer, buffer_len, Fs);
    
    cout << "done." << endl;
    return 0;
}

