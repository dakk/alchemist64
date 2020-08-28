#ifndef SOUND_H__
#define SOUND_H__

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

void sound_init(void);

void play_bomb(void);
void play_dynamite(void);
void play_press(void);
void play_explode(void);

#endif