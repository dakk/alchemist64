#ifndef SOUND_H__
#define SOUND_H__

#include "plat.h"

void sound_init(void);
void play_tone(u8_t);

#define TONE_EXPLODE 0
#define TONE_BOMB 3
#define TONE_DYNAMITE 2
#define TONE_PRESS 1

#endif