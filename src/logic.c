#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "logic.h"
#include "draw.h"

char grid[GRID_HEIGHT][GRID_WIDTH];
int score;
int gameover;
time_t start_time;
int elapsed;
int highscore = 0;
char limit;
char elements;
char nextblock[2];
char curblock[2];
int curblock_rot;
int curblock_pos = GRID_WIDTH/2-1;

void generate_nextblock() {
	curblock[0] = nextblock[0];
	curblock[1] = nextblock[1];
	curblock_rot = 0;

	if (rand() % 25 == 30)
		nextblock[0] = (char) (rand() % 3) + 12;
	else
		nextblock[0] = (char) (rand() % limit) + 1;
	nextblock[1] = (char) (rand() % limit) + 1;
}

int on_board(int x, int y) {
	return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
}

int test(int x, int y, int dx1, int dy1, int dx2, int dy2, char t) {
	return on_board(x+dx1,y+dy1) && on_board(x+dx2,y+dy2) && grid[y+dy1][x+dx1] == t && grid[y+dy2][x+dx2] == t;
}

void change_cell(int x, int y, char newvalue) {
	if (on_board (x, y)) {
		grid[y][x] = newvalue;
		draw_grid_cell(x, y);
	}
}
		

void explode(int x, int y, char t){
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
int update() {
	int i,j,x,y;
	int r = 0;

	
	// Move down
	for(j=GRID_HEIGHT-2; j >= 0; j--) {
		for(i=0; i < GRID_WIDTH; i++) {
			if (grid[j][i] != 0 && grid[j+1][i] == 0) {
				grid[j+1][i] = grid[j][i];
				grid[j][i] = 0;

				draw_grid_cell(i, j); draw_grid_cell(i, j+1);
				r++;
			}
		}
	}
	if (r) return r;
	
	// Exploding
	for(y=0; y < GRID_HEIGHT; y++) {
		for(x=0; x < GRID_WIDTH; x++) {
			// Dynamite
			if (grid[y][x] == 12) {
				change_cell(x, y, 0);

				change_cell(x-1, y, 0);
				change_cell(x+1, y, 0);
				change_cell(x, y+1, 0);
				change_cell(x, y-1, 0);
				return 1;
			}
			// Press
			else if (grid[y][x] == 13) {
				if (y < GRID_HEIGHT-1)  
					change_cell(x, y+1, 13);
				
				change_cell(x, y, 0);
				return 1;
			}
			// Bomb
			else if (grid[y][x] == 14) {
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
				return 1;
			}
			// Normal
			else if (grid[y][x] != 0 && grid[y][x] < 12) {
				char t = grid[y][x];
				if (test (x, y, 0, 1, 0, -1, t) 
				 || test (x, y, 1, 0, -1, 0, t) 
				 || test (x, y, 1, 0, 0, 1, t) 
				 || test (x, y, -1, 0, 0, -1, t) 
				 || test (x, y, -1, 0, 0, 1, t) 
				 || test (x, y, 1, 0, 0, -1, t)) {
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

	// Check for gameover
	for(i = 0; i < GRID_WIDTH; i++) {
		if (grid[0][i] != 0 || grid[1][i] != 0) {
			gameover = 1;
		}
	}
	
	elapsed = (time(NULL) - start_time) / 60;
	return r;
}

void new_game() {
	int i,j;

   	_randomize();
	   
	for(i=0; i < GRID_WIDTH; i++) {
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

	start_time = time(NULL);
	elapsed = 0;
}

void drop_curblock() {
	char a,b,c,d;
	
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