#ifdef __CX16__

#include <cx16.h>
#include <conio.h>
#include "plat.h"
#include "data.h"

void pinit() {
	videomode(VIDEOMODE_320x200);
}


void pdrawcxy(int x, int y, char c) {
	revers(1);
	textcolor(colors[c]);
	cputcxy(x,y, c-128);
	revers(0);
}


#endif