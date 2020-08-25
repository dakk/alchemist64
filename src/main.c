// The game has 15 different sprites, each one with a different value
// we represent them with 15 sprites
// the rest of the board is defined by petscii characters


#include <stdio.h>
#include <conio.h>
#include "logic.h"
#include "draw.h"


void gameloop () {
	char cc;

	
	draw_curblock();
	draw_info();

	do {
		draw_game_grid();	
	} while(update());
	
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
	bgcolor(0);
   	new_game ();
	clrscr();
    
	draw_container();

	while(!gameover){
		gameloop();
	}

	draw_gameover();
}
