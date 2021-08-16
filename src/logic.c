#include <unistd.h>
#include <stdlib.h>

#include "logic.h"
#include "draw.h"
#include "sound.h"


u8_t grid[GRID_HEIGHT][GRID_WIDTH];
u8_t score;
u8_t gameover = 1;
unsigned long start_time;
u8_t elapsed;
u8_t highscore = 0;
u8_t limit;
u8_t elements;
u8_t nextblock[2];
u8_t curblock[2];
u8_t curblock_rot;
u8_t curblock_pos = GRID_WIDTH/2-1;

void generate_nextblock() {
	curblock[0] = nextblock[0];
	curblock[1] = nextblock[1];
	curblock_rot = 0;

	if (rand() % 40 == 25)
		nextblock[0] = (u8_t) (rand() % 3) + 12;
	else
		nextblock[0] = (u8_t) (rand() % limit) + 1;
	nextblock[1] = (u8_t) (rand() % limit) + 1;
}

u8_t on_board(u8_t x, u8_t y) {
	return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
}

u8_t test(u8_t x, u8_t y, u8_t t) {
	return on_board(x,y) && grid[y][x] == t;
}

// u8_t test2(u8_t x, u8_t y, short dx1, short dy1, short dx2, short dy2, u8_t t) {
// 	return on_board(x+dx1,y+dy1) 
// 		&& on_board(x+dx2,y+dy2) 
// 		&& grid[y+dy1][x+dx1] == t 
// 		&& grid[y+dy2][x+dx2] == t;
// }


void change_cell(u8_t x, u8_t y, u8_t newvalue) {
	if (!on_board (x, y)) 
		return;

	grid[y][x] = newvalue;
	draw_grid_cell(x, y);
}
		

void explode(u8_t x, u8_t y, u8_t t){
	if(grid[y][x] == t) 
		change_cell(x,y,0);
	if (y > 0 && grid[y-1][x] == t) 
		explode(x,y-1,t);
	if (y < GRID_HEIGHT && grid[y+1][x] == t) 
		explode(x,y+1,t);
	if (x > 0 && grid[y][x-1] == t) 
		explode(x-1,y,t);
	if  (x < GRID_WIDTH && grid[y][x+1] == t) 
		explode(x+1,y,t);
}

// Move down blocks, explode when combination is found, return 0 if no update occured
u16_t update() {
	u8_t x,y;
	u16_t r = 0;

	if (gameover)
		return 0;
	
	// Move down
	for(y=0; y <= GRID_HEIGHT-2; y++) {
		for(x=0; x < GRID_WIDTH; x++) {
			if (grid[y][x] != 0 && grid[y+1][x] == 0) {
				grid[y+1][x] = grid[y][x];
				grid[y][x] = 0;

				draw_grid_cell(x, y); draw_grid_cell(x, y+1);
				r++;
			}
		}
	}
	if (r) return r;
	
	// Exploding
	for(y=0; y < GRID_HEIGHT; y++) {
		for(x=0; x < GRID_WIDTH; x++) {
			switch(grid[y][x]) {
				// Dynamite
				case 12:
					change_cell(x, y, 0);

					change_cell(x-1, y, 0);
					change_cell(x+1, y, 0);
					change_cell(x, y+1, 0);
					change_cell(x, y-1, 0);

					play_tone(TONE_DYNAMITE);
					return 1;

				// Press
				case 13:
					if (y < GRID_HEIGHT-1)  
						change_cell(x, y+1, 13);
					
					change_cell(x, y, 0);

					play_tone(TONE_PRESS);
					return 1;

				// Bomb
				case 14:	
					change_cell(x, y, 0);

					change_cell(x, y-1, 0);
					change_cell(x, y+1, 0);
					change_cell(x+1, y, 0);
					change_cell(x-1, y, 0);
					change_cell(x-1, y-1, 0);
					change_cell(x+1, y+1, 0);
					change_cell(x+1, y-1, 0);
					change_cell(x-1, y+1, 0);
					change_cell(x, y-2, 0);
					change_cell(x, y+2, 0);
					change_cell(x+2, y, 0);
					change_cell(x-2, y, 0);

					play_tone(TONE_BOMB);
					return 1;

				default:
					if (grid[y][x] != 0 && grid[y][x] < 12) {
						u8_t t = grid[y][x];
						if (
							(test (x, y+1, t) && test (x, y-1, t)) 
							||
							(test (x+1, y, t) && test (x-1, y, t)) 
							|| 
							(test (x+1, y, t) && test (x, y+1, t))
							||
							(test (x-1, y, t) && test (x, y-1, t))
							|| 
							(test (x-1, y, t) && test (x, y+1, t))
							||						
							(test (x+1, y, t) && test (x, y-1, t))
						) {
							// upgrade our center piece
							if (t < 12)
								grid[y][x] ++;
							else
								grid[y][x] = 0;

							if (elements < grid[y][x])
								elements = grid[y][x];

							draw_grid_cell(x, y);
							
							// explode the touching pieces
							explode (x,y,t);

							play_tone(TONE_EXPLODE);
							
							score += (t * 10) + t * t;

							if (score > highscore)
								highscore = score;

							if (t-1 > limit && t-1 < 12)
								limit++;
							return 1;
						}
					}
			}
		}
	}

	// Check for gameover
	for(x = 0; x < GRID_WIDTH; x++) {
		if (grid[0][x] != 0 || grid[1][x] != 0) {
			gameover = 1;
		}
	}
	
	elapsed = (ptime() - start_time) / 60;
	return r;
}

void new_game() {
	u8_t i = 0,j;

   	_randomize();
	   
	for(i; i < GRID_WIDTH; i++) {
		for(j=0; j < GRID_HEIGHT; j++) {
			grid[j][i] = 0;
		}
	}	
	
	limit = 3;
	elements = 3;
	score = 0;	
	
	nextblock[0] = 1;
	nextblock[1] = 1;
	
	gameover = 0;

	generate_nextblock();

	start_time = ptime();
	elapsed = 0;
}

void drop_curblock() {
	u8_t a,b,c,d;
	
	switch(curblock_rot) {
		case 0: a = curblock[0]; b = curblock[1]; c = 0; d = 0; break;
		case 1: a = curblock[0]; c = curblock[1]; b = 0; d = 0; break;
		case 2: b = curblock[0]; a = curblock[1]; c = 0; d = 0; break;
		case 3: c = curblock[0]; a = curblock[1]; b = 0; d = 0; break;
	}
			
	if(a) grid[0][curblock_pos] = a;
	if(b) grid[0][curblock_pos+1] = b;
	if(c) grid[1][curblock_pos] = c;
	if(d) grid[1][curblock_pos+1] = d;
}