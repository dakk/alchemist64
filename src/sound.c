#include <stdio.h>
#include "sound.h"


 
uint16_t g_freq[8] = {
    0x22cd,
    0x2710,
    0x2bd8,
    0x2e74,
    0x3424,
    0x3a87,
    0x41b2,
    0x459a
};

uint8_t* sid_base = (char*) 0xd400;


void set_volume(uint8_t volume)
{
    sid_base[24] = volume | (1 << 4);
}
 
void sound_init()
{
    uint8_t i = 0;
    for (i = 0; i < 24; i++) sid_base[i] = 0;
    set_volume(15);


    sid_base[23] = 7;
    sid_base[22] = 10;
}
 
void set_freq(uint8_t voice, uint16_t freqIndex)
{
    uint16_t freq = g_freq[freqIndex];
    sid_base[7 * voice] = freq & 0xff;
    sid_base[7 * voice + 1] = freq >> 8;
}
 
void set_adsr(uint8_t voice, uint8_t attack, uint8_t decay, uint8_t sustain, uint8_t release)
{
    sid_base[7 * voice + 5] = (attack << 4) | decay;
    sid_base[7 * voice + 6] = (sustain << 4) | release;
}
 
void start_triangle(uint8_t voice)
{
    sid_base[7 * voice + 4] = (1 << 4) | 1;
}
 
void stop_triangle(uint8_t voice)
{
    sid_base[7 * voice + 4] = 1 << 4;
}
 
void delay()
{
    long i;
    for (i = 0; i < 500; i++);
}
 
void start_tone(uint8_t voice, uint8_t freqIndex)
{
    set_freq(voice, freqIndex);
    set_adsr(voice, 2, 1, 15, 1);
    start_triangle(voice);
}
 
void stop_tone(uint8_t voice)
{
    stop_triangle(voice);
}
 
void playOneTone(uint8_t freqIndex)
{
    start_tone(0, freqIndex);
    delay();
    stop_tone(0);
}
 
void play_three_tones(uint8_t freqIndex0, uint8_t freqIndex1, uint8_t freqIndex2)
{
    start_tone(0, freqIndex0);
    start_tone(1, freqIndex1);
    start_tone(2, freqIndex2);
    delay();
    stop_tone(0);
    stop_tone(1);
    stop_tone(2);
}
 

int run()
{
    sid_base[23] = 7;
    sid_base[22] = 10;
    while (1) {
        uint8_t i;
        for (i = 0; i < 8; i++) {
            playOneTone(i);
        }
        delay();
        
        play_three_tones(0, 2, 5);
        play_three_tones(2, 5, 7);
        play_three_tones(1, 2, 5);
        play_three_tones(0, 2, 5);
        play_three_tones(0, 2, 4);
        play_three_tones(0, 2, 5);
        delay();
    }
    return 0;
}



void play_bomb() {

}

void play_dynamite() {

}

void play_press() {

}

void play_explode() {

}