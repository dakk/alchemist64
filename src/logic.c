#include "logic.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char grid[GRID_HEIGHT][GRID_WIDTH];
int score = 0;
time_t start_time;
int elapsed = 0;
int highscore = 0;
char limit = 3;
char nextblock[2];
char curblock[2];
int curblock_rot = 0;
int curblock_pos = GRID_WIDTH/2-1;

void generate_nextblock() {
	curblock[0] = nextblock[0];
	curblock[1] = nextblock[1];
	curblock_rot = 0;
	nextblock[0] = (char) (rand() % limit) + 1;
	nextblock[1] = (char) (rand() % limit) + 1;
}

int on_board(int x, int y) {
	return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
}

int test(int x, int y, int dx1, int dy1, int dx2, int dy2, char t) {
	return on_board(x+dx1,y+dy1) && on_board(x+dx2,y+dy2) && grid[y+dy1][x+dx1] == t && grid[y+dy2][x+dx2] == t;
}


void explode(int x, int y, char t){
	if(grid[y][x] == t)
		grid[y][x] = 0;
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

	elapsed = (time(NULL) - start_time) / 60;
	
	// Move down
	for(j=GRID_HEIGHT-2; j >= 0; j--) {
		for(i=0; i < GRID_WIDTH; i++) {
			if (grid[j][i] != 0 && grid[j+1][i] == 0) {
				grid[j+1][i] = grid[j][i];
				grid[j][i] = 0;
				r++;
			}
		}
	}
	if (r) return r;
	
	// Exploding
	for(y=0; y < GRID_HEIGHT; y++) {
		for(x=0; x < GRID_WIDTH; x++) {
			if (grid[y][x] != 0 && grid[y][x] < 13) {
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
					
					// explode the touching pieces
					explode (x,y,t);
					score += (t * 10) + t * t;

					if (score > highscore)
						highscore = score;

					if (t-1 > limit && t-1 < 13)
						limit++;
					return 1;
				}
			}
		}
	}
	
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
	score = 0;	
	
	nextblock[0] = 1;
	nextblock[1] = 1;
	
	generate_nextblock();

	start_time = time(NULL);
}

void drop_curblock() {
	char a,b,c,d;
	
	switch(curblock_rot) {
		case 0: a = curblock[0]; b = curblock[1]; c = 0; d = 0; break;
		case 1: a = curblock[0]; c = curblock[1]; b = 0; d = 0; break;
		case 2: c = curblock[0]; a = curblock[1]; b = 0; d = 0; break;
		case 3: b = curblock[0]; a = curblock[1]; c = 0; d = 0; break;
	}
			
	grid[0][curblock_pos] = a;
	grid[0][curblock_pos+1] = b;
	grid[1][curblock_pos] = c;
	grid[1][curblock_pos+1] = d;
}