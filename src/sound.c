#include <stdio.h>
#include "sound.h"

// https://stackoverflow.com/questions/40950140/how-to-include-a-sid-file-into-a-cc65-program-on-a-c64 
// music will be played along the game using interrupts; sound effects in the main thread
// idea: usare una canzone reggae tipo quella con le trombette o sattamassagana
 
uint16_t freqs[8] = {
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
    uint16_t freq = freqs[freqIndex];
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
 
void play_one_tone(uint8_t freqIndex)
{
    start_tone(0, freqIndex);
    delay();
    stop_tone(0);
}
 
 


void play_bomb() {
	play_one_tone(3);
}

void play_dynamite() {
	play_one_tone(2);
}

void play_press() {
	play_one_tone(1);
}

void play_explode() {
	play_one_tone(0);
}