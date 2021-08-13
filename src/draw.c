#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "sound.h"
#include "logic.h"
#include "draw.h"
#include "data.h"
#include "plat.h"

u8_t vtable[][4] = {
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
	// Weapons
	{90,91,122,123},
	{92,93,124,125},
	{94,95,126,127},
};

void draw_custom(u8_t x, u8_t y, u8_t v) {
	pdrawcxy(x,y,vtable[v-1][0]+64);
	pdrawcxy(x+1,y,vtable[v-1][1]+64);
	pdrawcxy(x,y+1,vtable[v-1][2]+64);
	pdrawcxy(x+1,y+1,vtable[v-1][3]+64);
}


void draw_cell (u8_t x, u8_t y, u8_t v) {
	if (v == 0) {
		cputcxy(x, y, ' ');
		cputcxy(x+1, y, ' ');
		cputcxy(x+1, y+1, ' ');
		cputcxy(x, y+1, ' ');
		return;
	}

	draw_custom(x, y, v);
}

void draw_grid_cell (u8_t x, u8_t y) {
	draw_cell((GRID_PADDING_X+x)*CELL_SIZE, GRID_PADDING_Y+(y+1)*CELL_SIZE, grid[y][x]);
}

void draw_curblock() {
	u8_t a,b,c,d;
	
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
	u8_t i;
	
	textcolor(GRIDCOLOR);
	revers(1);
	cputcxy(GRID_PADDING_X, 0, 86);
	cputcxy(GRID_PADDING_X+GRID_WIDTH*CELL_SIZE+1, 0, 87);
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		cputcxy(GRID_PADDING_X+i, 0, 88);
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		cputcxy(GRID_PADDING_X+i, GRID_PADDING_Y, 88);
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		cputcxy(GRID_PADDING_X+i, (GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE), 88);
	for(i=1; i < 1 + (GRID_HEIGHT) * CELL_SIZE+1+GRID_PADDING_Y;i++)
		cputcxy(GRID_PADDING_X, i, 89);
		
	for(i=1; i < 1 + (GRID_HEIGHT) * CELL_SIZE+1+GRID_PADDING_Y;i++)
		cputcxy(GRID_PADDING_X+(GRID_WIDTH*CELL_SIZE)+1, i, 185-128);
	cputcxy(GRID_PADDING_X, GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE, 182-128);
	cputcxy(GRID_PADDING_X + GRID_WIDTH * CELL_SIZE +1, (GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE), 183-128);
	revers(0);
}

void draw_info () {
	u8_t c[14];
	u8_t i = 0;
	u8_t j = 0;

	textcolor(TEXTCOLOR);
	cputsxy(26, 3, "next");
	textcolor(TEXTCOLOR2);

	// revers(1);
	textcolor(nextblock[0]);
	draw_cell(28, 4, nextblock[0]);
	textcolor(nextblock[1]);
	draw_cell(30, 4, nextblock[1]);
	// revers(0);

	textcolor(TEXTCOLOR);
	cputsxy(26, 7, "score");
	textcolor(TEXTCOLOR2);
	sprintf(c, "%d", score);
	cputsxy(28, 8, c);

	textcolor(TEXTCOLOR);
	cputsxy(26, 10, "highscore");
	textcolor(TEXTCOLOR2);
	sprintf(c, "%d", highscore);
	cputsxy(28, 11, c);

	textcolor(TEXTCOLOR);
	cputsxy(26, 13, "time (m)");
	textcolor(TEXTCOLOR2);
	sprintf(c, "%d", elapsed);
	cputsxy(28, 14, c);

	textcolor(TEXTCOLOR);
	sprintf(c, "elements (%d)", elements);
	cputsxy(26, 16, c);

	for(i;i<elements;i++) {
		if (i % 5 == 0)
			j++;
		draw_custom(28 + i*2 - (j-1)*10, 15+j*2, i+1);
	}
}


void draw_gameover() {
	textcolor(TEXTCOLOR);
	cputsxy(5, 3, "gameover!");
	cputsxy(5, 4, "press f1 key");
	while(!kbhit() && cgetc() != 0x85);
}

void draw_initialscreen() {
	u8_t c[8];
	u8_t i;
	u8_t j = 0;
	u8_t dir = 1;

	clrscr();

	textcolor(255);

	gotoxy(0,1);
	printf("   _____ _     _             _     _   \n");
	printf("  |  _  | |___| |_ ___ _____|_|___| |_ \n");
	printf("  |     | |  _|   | -_|     | |_ -|  _|\n");
	printf("  |__|__|_|___|_|_|___|_|_|_|_|___|_|  \n");
	
	textcolor(2);
	cputsxy(11, 6, "2021 davide gessa");
	
	textcolor(TEXTCOLOR);
	cputsxy(6, 11, "highscore");
	textcolor(TEXTCOLOR2);
	sprintf(c, "%d", highscore);
	cputsxy(32, 11, c);

	textcolor(TEXTCOLOR);
	cputsxy(6, 13, "controls");
	textcolor(TEXTCOLOR2);
	cputsxy(24, 13, "wad - space");


	textcolor(TEXTCOLOR);
	cputsxy(19, 23, "press f1 to start...");

	while (1) {
		if (kbhit())
			if (cgetc() == 0x85) 
				break;

		cputcxy(6+j-6,18, ' ');
		cputcxy(6+j-6,19, ' ');

		for(i=0;i<14;i++) 
			draw_custom(6 + i*2 + j - 5, 18, i+1);

		cputcxy(6+2*14+j - 5,18, ' ');
		cputcxy(6+2*14+j - 5,19, ' ');

		if (dir == 1) j++; else j--;
		if (j >= 10) {
			dir = 0; 
		} else if (j == 0) {
			dir = 1;
		}
	}
}