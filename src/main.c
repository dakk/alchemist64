#include <stdio.h>
#include <conio.h>
#include "logic.h"
#include "draw.h"


void gameloop () {
	char cc;

	
	draw_curblock();
	draw_info();

	// do {	draw_game_grid(); } 
	while(update());
	
	draw_info();

	if (gameover)
		return;
	
	do {
		cc = cgetc();
		
		switch(cc) {
			case 'd':
				if (curblock_pos < GRID_WIDTH - 2)
					curblock_pos ++;
				break;
			case 'a':
				if (curblock_pos > 0)
					curblock_pos --;
				break;
			case 'w':
				curblock_rot = (curblock_rot+1)%4;
				break;
			case ' ':
				drop_curblock();
				generate_nextblock();
				break;
			
		}
		draw_curblock();
	} while(cc != ' ');
}

void main(void) {
	bordercolor(0);
	bgcolor(0);

	while(1) {
		draw_initialscreen();

		new_game ();
		clrscr();
		
		draw_container();

		while(!gameover){
			gameloop();
		}

		draw_gameover();
	}
}
