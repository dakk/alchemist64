#include <stdio.h>
#include <conio.h>

#include "logic.h"
#include "draw.h"

void draw_cell (int x, int y, char v) {
	if (v == 0) {
		textcolor(4);
		cputcxy(x, y, ' ');
		cputcxy(x+1, y, ' ');
		cputcxy(x+1, y+1, ' ');
		cputcxy(x, y+1, ' ');
		return;
	}
	
	revers(1);
	textcolor(v);
	cputcxy(x, y, 64+v);
	cputcxy(x+1, y, 64+v);
	cputcxy(x+1, y+1, 64+v);
	cputcxy(x, y+1, 64+v);
	revers(0);
	textcolor(15);
}

void draw_curblock() {
	char a,b,c,d;

	textcolor(15);
	
	cclearxy (GRID_PADDING_X+1, 0, GRID_WIDTH * CELL_SIZE);
	cclearxy (GRID_PADDING_X+1, 1, GRID_WIDTH * CELL_SIZE);
	cclearxy (GRID_PADDING_X+1, 2, GRID_WIDTH * CELL_SIZE);
	cclearxy (GRID_PADDING_X+1, 3, GRID_WIDTH * CELL_SIZE);
	
	switch(curblock_rot) {
		case 0: a = curblock[0]; b = curblock[1]; c = ' '; d = ' '; break;
		case 1: a = curblock[0]; c = curblock[1]; b = ' '; d = ' '; break;
		case 2: c = curblock[0]; a = curblock[1]; b = ' '; d = ' '; break;
		case 3: b = curblock[0]; a = curblock[1]; c = ' '; d = ' '; break;
	}
		
	draw_cell (((GRID_PADDING_X+curblock_pos)*CELL_SIZE), 0, a);
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE+CELL_SIZE, 0, b);	
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE, CELL_SIZE, c);	
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE+CELL_SIZE, CELL_SIZE, d);	
}

void draw_game_grid () {
	int i,j;
	revers(1);
	textcolor(15);
	
	chlinexy (GRID_PADDING_X, GRID_PADDING_Y, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, 2+(GRID_PADDING_Y+GRID_HEIGHT)*CELL_SIZE, 2 + (GRID_WIDTH)*CELL_SIZE);
	cvlinexy (GRID_PADDING_X, 0, GRID_PADDING_Y + (GRID_HEIGHT + 3) * CELL_SIZE);
	cvlinexy (GRID_PADDING_X+(GRID_WIDTH)*CELL_SIZE+1, 0, GRID_PADDING_Y + (GRID_HEIGHT + 3)*CELL_SIZE);
	
	revers(0);

	textcolor(4);
	for(i=0; i < GRID_WIDTH; i++) {
		for(j=0; j < GRID_HEIGHT; j++) {
			draw_cell((GRID_PADDING_X+i)*CELL_SIZE, (GRID_PADDING_Y+j+1)*CELL_SIZE, grid[j][i]);		
		}
	}
}

void draw_info () {
	char c[8];

	textcolor(12);
	cputsxy(26, 3, "Next      =>");
	textcolor(4);

	revers(1);
	textcolor(nextblock[0]);
	cputcxy(28, 4, nextblock[0] + 64);
	textcolor(nextblock[1]);
	cputcxy(29, 4, nextblock[1] + 64);
	revers(0);

	textcolor(12);
	cputsxy(26, 6, "Score     =>");
	textcolor(4);
	sprintf(c, "%d", score);
	cputsxy(28, 7, c);

	textcolor(12);
	cputsxy(26, 9, "Highscore =>");
	textcolor(4);
	sprintf(c, "%d", score);
	cputsxy(28, 10, c);

	textcolor(12);
	cputsxy(26, 12, "Time (m)  =>");
	textcolor(4);
	sprintf(c, "%d", elapsed);
	cputsxy(28, 13, c);
}
