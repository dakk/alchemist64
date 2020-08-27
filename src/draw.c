#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "logic.h"
#include "draw.h"
#include "data.h"

// #define VIC_BASE_RAM			(0xC000)
// #define CHARMAP_RAM				((char*)VIC_BASE_RAM + 0x2800)
// extern char charset[1024];

// void load_charset() {
// 	memcpy((char*)CHARMAP_RAM, (char*)charset+256*8,256*8);
// }

char vtable[][4] = {
	{64,65,96,97},
	{66,67,98,99},
	{68,69,100,101},
	{70,71,102,103},
	{72,73,104,105},
	{74,75,106,107},
	{76,77,108,109},
	{78,79,110,111},
	{80,81,112,113},
	{82,83,114,115},
	{84,85,116,117},
};

void draw_custom(int x, int y, char v) {
	COLOUR_RAM[y*40+x] = charset_colors[0][vtable[v-1][0]];
	SCREEN_RAM[y*40+x] = vtable[v-1][0];
	COLOUR_RAM[y*40+x+1] = charset_colors[0][vtable[v-1][1]];
	SCREEN_RAM[y*40+x+1] = vtable[v-1][1];
	COLOUR_RAM[(y+1)*40+x] = charset_colors[0][vtable[v-1][2]];
	SCREEN_RAM[(y+1)*40+x] = vtable[v-1][2];
	COLOUR_RAM[(y+1)*40+x+1] = charset_colors[0][vtable[v-1][3]];
	SCREEN_RAM[(y+1)*40+x+1] = vtable[v-1][3];
}


void draw_cell (int x, int y, char v) {
	if (v == 0) {
		textcolor(4);
		cputcxy(x, y, ' ');
		cputcxy(x+1, y, ' ');
		cputcxy(x+1, y+1, ' ');
		cputcxy(x, y+1, ' ');
		return;
	}

	draw_custom(x, y, v);
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
		case 0: a = curblock[0]; b = curblock[1]; c = 0; d = 0; break;
		case 1: a = curblock[0]; c = curblock[1]; b = 0; d = 0; break;
		case 2: b = curblock[0]; a = curblock[1]; c = 0; d = 0; break;
		case 3: c = curblock[0]; a = curblock[1]; b = 0; d = 0; break;
	}
		
	draw_cell (((GRID_PADDING_X+curblock_pos)*CELL_SIZE), 1, a);
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE+CELL_SIZE, 1, b);	
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE, CELL_SIZE+1, c);	
	draw_cell ((GRID_PADDING_X+curblock_pos)*CELL_SIZE+CELL_SIZE, CELL_SIZE+1, d);	
}

void draw_container () {
	int i;
	revers(1);
	textcolor(6);
	
	chlinexy (GRID_PADDING_X, 0, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, GRID_PADDING_Y, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, 2+GRID_PADDING_Y+(GRID_HEIGHT)*CELL_SIZE, 2 + (GRID_WIDTH)*CELL_SIZE);
	cvlinexy (GRID_PADDING_X, 0, GRID_PADDING_Y + (GRID_HEIGHT + 1) * CELL_SIZE);
	cvlinexy (GRID_PADDING_X+(GRID_WIDTH)*CELL_SIZE+1, 0, GRID_PADDING_Y + (GRID_HEIGHT + 1)*CELL_SIZE);
	
	revers(0);	

	textcolor(6);
	SCREEN_RAM[GRID_PADDING_X] = 86;
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		SCREEN_RAM[GRID_PADDING_X+i] = 88;
	SCREEN_RAM[1+GRID_PADDING_X + (GRID_WIDTH) * CELL_SIZE] = 87;
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		SCREEN_RAM[GRID_PADDING_Y*40+GRID_PADDING_X+i] = 88;
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		SCREEN_RAM[(GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE)*40+GRID_PADDING_X+i] = 88;
	SCREEN_RAM[(GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE)*40+GRID_PADDING_X] = 118;
	SCREEN_RAM[(GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE)*40+GRID_PADDING_X + GRID_WIDTH * CELL_SIZE+1] = 119;
	for(i=1; i < 1 + (GRID_HEIGHT) * CELL_SIZE+1+GRID_PADDING_Y;i++)
		SCREEN_RAM[(i)*40+GRID_PADDING_X] = 89;
	for(i=1; i < 1 + (GRID_HEIGHT) * CELL_SIZE+1+GRID_PADDING_Y;i++)
		SCREEN_RAM[(i)*40+GRID_PADDING_X+(GRID_WIDTH*CELL_SIZE)+1] = 121;
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
	char c[14];
	int i;
	int j;

	textcolor(7);
	cputsxy(26, 3, "next");
	textcolor(4);

	// revers(1);
	textcolor(nextblock[0]);
	draw_cell(28, 4, nextblock[0]);
	textcolor(nextblock[1]);
	draw_cell(30, 4, nextblock[1]);
	// revers(0);

	textcolor(7);
	cputsxy(26, 7, "score");
	textcolor(4);
	sprintf(c, "%d", score);
	cputsxy(28, 8, c);

	textcolor(7);
	cputsxy(26, 10, "highscore");
	textcolor(4);
	sprintf(c, "%d", highscore);
	cputsxy(28, 11, c);

	textcolor(7);
	cputsxy(26, 13, "time (m)");
	textcolor(4);
	sprintf(c, "%d", elapsed);
	cputsxy(28, 14, c);

	textcolor(7);
	sprintf(c, "elements (%d)", elements);
	cputsxy(26, 16, c);

	j=0;
	for(i=0;i<elements;i++) {
		if (i % 5 == 0)
			j++;
		draw_custom(28 + i*2 - (j-1)*10, 15+j*2, i+1);
	}
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

	textcolor(7);

	cputsxy(5, 3, "alchemist64!");
	
	cputsxy(5, 10, "highscore");
	textcolor(4);
	sprintf(c, "%d", highscore);
	cputsxy(5, 11, c);

	textcolor(6);
	cputsxy(5, 13, "press any key...");
	cgetc();
}