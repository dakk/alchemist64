#ifndef LOGIC_H__
#define LOGIC_H__


#define GRID_HEIGHT 	8
#define GRID_WIDTH 		10

#include "plat.h"

extern u8_t gameover;
extern unsigned int elapsed;
extern unsigned int highscore;
extern unsigned int score;
extern u8_t limit;
extern u8_t elements;
extern u8_t nextblock[2];
extern u8_t curblock[2];
extern u8_t curblock_rot;
extern u8_t curblock_pos;
extern u8_t grid[GRID_HEIGHT][GRID_WIDTH];

unsigned short update(void);
void drop_curblock(void);
void generate_nextblock(void);
void new_game(void);

#endif