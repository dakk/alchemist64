#include <stdio.h>
#include <conio.h>

#include "logic.h"
#include "draw.h"


char vtable[] = {
	65 + 64,
	83 + 64,
	90 + 64,
	88 + 64,
	81 + 64,
	87 + 64
};

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
	cputcxy(x, y, vtable[v-1]);
	cputcxy(x+1, y, vtable[v-1]);
	cputcxy(x+1, y+1, vtable[v-1]);
	cputcxy(x, y+1, vtable[v-1]);
	revers(0);
}

void draw_grid_cell (int x, int y) {
	draw_cell((GRID_PADDING_X+x)*CELL_SIZE, GRID_PADDING_Y+(y+1)*CELL_SIZE, grid[y][x]);
}

void draw_curblock() {
	char a,b,c,d;

	textcolor(15);
	
	cclearxy (GRID_PADDING_X+1, 1, GRID_WIDTH * CELL_SIZE);
	cclearxy (GRID_PADDING_X+1, 2, GRID_WIDTH * CELL_SIZE);
	cclearxy (GRID_PADDING_X+1, 3, GRID_WIDTH * CELL_SIZE);
	cclearxy (GRID_PADDING_X+1, 4, GRID_WIDTH * CELL_SIZE);
	
	switch(curblock_rot) {
		case 0: a = curblock[0]; b = curblock[1]; c = ' '; d = ' '; break;
		case 1: a = curblock[0]; c = curblock[1]; b = ' '; d = ' '; break;
		case 2: b = curblock[0]; a = curblock[1]; c = ' '; d = ' '; break;
		case 3: c = curblock[0]; a = curblock[1]; b = ' '; d = ' '; break;
	}
		
	draw_cell (((GRID_PADDING_X+curblock_pos)*CELL_SIZE), 1, a);
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE+CELL_SIZE, 1, b);	
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE, CELL_SIZE+1, c);	
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE+CELL_SIZE, CELL_SIZE+1, d);	
}

void draw_container () {
	revers(1);
	textcolor(15);
	
	chlinexy (GRID_PADDING_X, 0, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, GRID_PADDING_Y, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, 2+GRID_PADDING_Y+(GRID_HEIGHT)*CELL_SIZE, 2 + (GRID_WIDTH)*CELL_SIZE);
	cvlinexy (GRID_PADDING_X, 0, GRID_PADDING_Y + (GRID_HEIGHT + 1) * CELL_SIZE);
	cvlinexy (GRID_PADDING_X+(GRID_WIDTH)*CELL_SIZE+1, 0, GRID_PADDING_Y + (GRID_HEIGHT + 1)*CELL_SIZE);
	
	revers(0);	
}

// void draw_game_grid () {
// 	int i,j;

// 	for(i=0; i < GRID_WIDTH; i++) {
// 		for(j=0; j < GRID_HEIGHT; j++) {
// 			draw_grid_cell(i, j);
// 		}
// 	}
// }

void draw_info () {
	char c[8];

	textcolor(12);
	cputsxy(26, 3, "next");
	textcolor(4);

	revers(1);
	textcolor(nextblock[0]);
	draw_cell(28, 4, nextblock[0]);
	textcolor(nextblock[1]);
	draw_cell(30, 4, nextblock[1]);
	revers(0);

	textcolor(12);
	cputsxy(26, 7, "score");
	textcolor(4);
	sprintf(c, "%d", score);
	cputsxy(28, 8, c);

	textcolor(12);
	cputsxy(26, 10, "highscore");
	textcolor(4);
	sprintf(c, "%d", highscore);
	cputsxy(28, 11, c);

	textcolor(12);
	cputsxy(26, 13, "time (m)");
	textcolor(4);
	sprintf(c, "%d", elapsed);
	cputsxy(28, 14, c);
}


void draw_gameover() {
	textcolor(12);
	cputsxy(5, 3, "gameover!");
	cputsxy(5, 4, "press any key");
	cgetc();
}

void draw_initialscreen() {
	char c[8];
	clrscr();

	textcolor(12);

	cputsxy(5, 3, "alchemist64!");
	
	cputsxy(5, 10, "highscore");
	textcolor(4);
	sprintf(c, "%d", highscore);
	cputsxy(5, 11, c);

	textcolor(12);
	cputsxy(5, 13, "press any key...");
	cgetc();
}