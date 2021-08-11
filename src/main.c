#include <stdio.h>
#include <conio.h>
#include "logic.h"
#include "draw.h"
#include "plat.h"
#include "sound.h"


void gameloop () {
	char cc = 'x';

	draw_curblock();
	draw_info();

	while(update());
	
	draw_info();

	if (gameover)
		return;


	do {
		if(!kbhit()) continue;

		cc = cgetc();
		
		switch(cc) {
			case 'd':
				if (curblock_pos < GRID_WIDTH - 2) {
					curblock_pos ++;
					draw_curblock();
				}
				break;

			case 'a':
				if (curblock_pos > 0) {
					curblock_pos --;
					draw_curblock();
				}
				break;

			case 'w':
				curblock_rot = (curblock_rot+1)%4;
				draw_curblock();
				break;

			case ' ':
				drop_curblock();
				generate_nextblock();
				break;
			
		}
	} while(cc != ' ');
}


void main(void) {
	int i;

	pinit();

	clrscr();
	bgcolor(BACKGROUND);

	while(1) {
		bordercolor(BORDERCOLOR);
		draw_initialscreen();

		bordercolor(BACKGROUND);
		new_game ();
		clrscr();
		
		draw_container();

		sound_init();

		while(!gameover){
			gameloop();
		}

		draw_gameover();
	}
}
