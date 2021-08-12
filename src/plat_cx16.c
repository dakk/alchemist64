#ifdef __CX16__

#include <cx16.h>
#include <conio.h>
#include "plat.h"
#include "data.h"


#define gfx_address  0x4000

void pinit() {
	int i;
	const char *pData;
	unsigned char *pRam = (char *) 0xF800;
	unsigned char *vConf = (char *) 0x9f34;

	videomode(VIDEOMODE_40COL);

	pData = &charset[0][0];
	for(i = 0; i < CHARSET_COUNT; ++i) {
		vpoke(*pData++, pRam + i);
	}

	*vConf = 0x28;
}


void pdrawcxy(int x, int y, char c) {
	vpoke(c, y*256+x*2);
	vpoke(colors[0][c], y*256+x*2+1);
}



#endif