#include <stdio.h>
#include <conio.h>
#include "logic.h"

void draw_curblock() {
	char a,b,c,d;

	textcolor(15);
	
	chlinexy (GRID_PADDING_X+1, 0, GRID_WIDTH);
	chlinexy (GRID_PADDING_X+1, 1, GRID_WIDTH);
	
	switch(curblock_rot) {
		case 0: a = curblock[0]; b = curblock[1]; c = ' '; d = ' '; break;
		case 1: a = curblock[0]; c = curblock[1]; b = ' '; d = ' '; break;
		case 2: c = curblock[0]; a = curblock[1]; b = ' '; d = ' '; break;
		case 3: b = curblock[0]; a = curblock[1]; c = ' '; d = ' '; break;
	}
		
	cputcxy(GRID_PADDING_X+curblock_pos+1, 0, a);	
	cputcxy(GRID_PADDING_X+curblock_pos+2, 0, b);	
	cputcxy(GRID_PADDING_X+curblock_pos+1, 1, c);	
	cputcxy(GRID_PADDING_X+curblock_pos+2, 1, d);	
}

void draw_game_grid () {
	int i,j;
	revers(1);
	textcolor(15);
	
	chlinexy (GRID_PADDING_X, GRID_PADDING_Y, GRID_WIDTH+2);
	chlinexy (GRID_PADDING_X, GRID_PADDING_Y+GRID_HEIGHT+1, GRID_WIDTH+2);
	cvlinexy (GRID_PADDING_X, 0, GRID_HEIGHT+2+GRID_PADDING_Y);
	cvlinexy (GRID_PADDING_X+GRID_WIDTH+1, 0, GRID_HEIGHT+2+GRID_PADDING_Y);
	
	revers(0);

	textcolor(4);
	for(i=0; i < GRID_WIDTH; i++) {
		for(j=0; j < GRID_HEIGHT; j++) {
			if (grid[j][i] != 0) {
				revers(1);
				textcolor(grid[j][i]);
				cputcxy(GRID_PADDING_X+i+1, GRID_PADDING_Y+j+1, grid[j][i] + 64);
				revers(0);
				textcolor(15);
			}
			else 
				cputcxy(GRID_PADDING_X+i+1, GRID_PADDING_Y+j+1, ' ');			
		}
	}
}

void draw_info () {
	char c[8];

	textcolor(12);
	cputsxy(22, 3, "Next      =>");
	textcolor(4);

	revers(1);
	textcolor(nextblock[0]);
	cputcxy(35, 3, nextblock[0] + 64);
	textcolor(nextblock[1]);
	cputcxy(36, 3, nextblock[1] + 64);
	revers(0);

	textcolor(12);
	cputsxy(22, 5, "Score     =>");
	textcolor(4);
	sprintf(c, "%d", score);
	cputsxy(35, 5, c);
	textcolor(12);
	cputsxy(22, 7, "Highscore =>");
	textcolor(4);
	sprintf(c, "%d", score);
	cputsxy(35, 7, c);
	textcolor(12);
	cputsxy(22, 9, "Time (m)  =>");
	textcolor(4);
	sprintf(c, "%d", elapsed);
	cputsxy(35, 9, c);
}
