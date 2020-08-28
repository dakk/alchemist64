#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>

#include "logic.h"
#include "draw.h"
#include "data.h"

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
	// Weapons
	{90,91,122,123},
	{92,93,124,125},
	{94,95,126,127},
};

void draw_custom(int x, int y, char v) {
	COLOUR_RAM[y*40+x] = colors[0][vtable[v-1][0]+64];
	SCREEN_RAM[y*40+x] = vtable[v-1][0]+64;
	COLOUR_RAM[y*40+x+1] = colors[0][vtable[v-1][1]+64];
	SCREEN_RAM[y*40+x+1] = vtable[v-1][1]+64;
	COLOUR_RAM[(y+1)*40+x] = colors[0][vtable[v-1][2]+64];
	SCREEN_RAM[(y+1)*40+x] = vtable[v-1][2]+64;
	COLOUR_RAM[(y+1)*40+x+1] = colors[0][vtable[v-1][3]+64];
	SCREEN_RAM[(y+1)*40+x+1] = vtable[v-1][3]+64;
}


void draw_cell (int x, int y, char v) {
	if (v == 0) {
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
	textcolor(GRIDCOLOR);
	
	chlinexy (GRID_PADDING_X, 0, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, GRID_PADDING_Y, 2 + (GRID_WIDTH) * CELL_SIZE);
	chlinexy (GRID_PADDING_X, 2+GRID_PADDING_Y+(GRID_HEIGHT)*CELL_SIZE, 2 + (GRID_WIDTH)*CELL_SIZE);
	cvlinexy (GRID_PADDING_X, 0, GRID_PADDING_Y + (GRID_HEIGHT + 1) * CELL_SIZE);
	cvlinexy (GRID_PADDING_X+(GRID_WIDTH)*CELL_SIZE+1, 0, GRID_PADDING_Y + (GRID_HEIGHT + 1)*CELL_SIZE);
	
	revers(0);	

	textcolor(6);
	SCREEN_RAM[GRID_PADDING_X] = 86+64;
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		SCREEN_RAM[GRID_PADDING_X+i] = 88+64;
	SCREEN_RAM[1+GRID_PADDING_X + (GRID_WIDTH) * CELL_SIZE] = 87+64;
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		SCREEN_RAM[GRID_PADDING_Y*40+GRID_PADDING_X+i] = 88+64;
	for(i=1; i < 1 + (GRID_WIDTH) * CELL_SIZE;i++)
		SCREEN_RAM[(GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE)*40+GRID_PADDING_X+i] = 88+64;
	SCREEN_RAM[(GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE)*40+GRID_PADDING_X] = 118+64;
	SCREEN_RAM[(GRID_PADDING_Y+(GRID_HEIGHT + 1) * CELL_SIZE)*40+GRID_PADDING_X + GRID_WIDTH * CELL_SIZE+1] = 119+64;
	for(i=1; i < 1 + (GRID_HEIGHT) * CELL_SIZE+1+GRID_PADDING_Y;i++)
		SCREEN_RAM[(i)*40+GRID_PADDING_X] = 89+64;
	for(i=1; i < 1 + (GRID_HEIGHT) * CELL_SIZE+1+GRID_PADDING_Y;i++)
		SCREEN_RAM[(i)*40+GRID_PADDING_X+(GRID_WIDTH*CELL_SIZE)+1] = 121+64;
}

void draw_info () {
	char c[14];
	int i;
	int j;

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

	j=0;
	for(i=0;i<elements;i++) {
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
	char c[8];
	int i;
	int j;
	int dir = 0;

	clrscr();

	textcolor(1);

	gotoxy(0,1);
	printf("   _____ _     _             _     _   \n");
	printf("  |  _  | |___| |_ ___ _____|_|___| |_ \n");
	printf("  |     | |  _|   | -_|     | |_ -|  _|\n");
	printf("  |__|__|_|___|_|_|___|_|_|_|_|___|_|  \n");
	
	// cputsxy(14, 3, "alchemist64");
	
	textcolor(TEXTCOLOR);
	cputsxy(6, 9, "highscore");
	textcolor(TEXTCOLOR2);
	sprintf(c, "%d", highscore);
	cputsxy(32, 9, c);

	textcolor(TEXTCOLOR);
	cputsxy(6, 11, "controls");
	textcolor(TEXTCOLOR2);
	cputsxy(24, 11, "wad - space");

	textcolor(2);
	cputsxy(5, 18, "created by davide (dakk) gessa");

	textcolor(TEXTCOLOR);
	cputsxy(19, 23, "press f1 to start...");

	j = 0;
	dir = 1;
	while (1) {
		if (kbhit())
			if (cgetc() == 0x85) 
				break;

		cputcxy(6+j-1,15, ' ');
		cputcxy(6+j-1,16, ' ');

		for(i=0;i<14;i++) 
			draw_custom(6 + i*2 + j, 15, i+1);

		cputcxy(6+2*14+j,15, ' ');
		cputcxy(6+2*14+j,16, ' ');

		if (dir == 1) j++; else j--;
		if (j >= 5) dir = -1; else if (j <= -5) dir = 1;
	}
}