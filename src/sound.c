#include <stdio.h>
#include "sound.h"

// https://stackoverflow.com/questions/40950140/how-to-include-a-sid-file-into-a-cc65-program-on-a-c64 
// music will be played along the game using interrupts; sound effects in the main thread
// idea: usare una canzone reggae tipo quella con le trombette o sattamassagana
 
u16_t freqs[8] = {
    0x22cd,
    0x2710,
    0x2bd8,
    0x2e74,
    // 0x3424,
    // 0x3a87,
    // 0x41b2,
    // 0x459a
};

u8_t* sid_base = (u8_t*) 0xd400;


// void set_volume(u8_t volume)
// {
//     sid_base[24] = volume | (1 << 4);
// }
 
void sound_init()
{
    u8_t i = 0;
    for (i; i < 24; i++) sid_base[i] = 0;
    
    // Set volume
    sid_base[24] = 15 | (1 << 4);


    sid_base[23] = 7;
    sid_base[22] = 10;
}
 
// void set_freq(u8_t voice, u16_t freqIndex)
// {
//     u16_t freq = freqs[freqIndex];
//     sid_base[7 * voice] = freq & 0xff;
//     sid_base[7 * voice + 1] = freq >> 8;
// }

 
// void start_triangle(u8_t voice)
// {
//     sid_base[7 * voice + 4] = (1 << 4) | 1;
// }
 
// void stop_triangle(u8_t voice)
// {
//     sid_base[7 * voice + 4] = 1 << 4;
// }
 
// void set_adsr(u8_t voice, u8_t attack, u8_t decay, u8_t sustain, u8_t release)
// {
//     sid_base[7 * voice + 5] = (attack << 4) | decay;
//     sid_base[7 * voice + 6] = (sustain << 4) | release;
// }
 
 
void play_tone(u8_t freqIndex)
{
    u16_t i = 0;

    // Set frequency
    u16_t freq = freqs[freqIndex];
    sid_base[0] = freq & 0xff;
    sid_base[1] = freq >> 8;

    // Set adsr
    sid_base[5] = (2 << 4) | 1;
    sid_base[6] = (15 << 4) | 1;

    // Start triangle
    sid_base[4] = (1 << 4) | 1;

    // Delay
    for (i; i < 500; i++);

    // Stop triangle
    sid_base[4] = 1 << 4;
}
 
