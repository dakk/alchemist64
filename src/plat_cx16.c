#ifdef __CX16__

#include <cx16.h>
#include <conio.h>
#include "plat.h"
#include "data.h"


#define gfx_address  0x4000

void pinit() {
	unsigned char i;
	const char *pData;
	unsigned char *pRam = (unsigned char *) 0xF800;
	unsigned char *vConf = (unsigned char *) 0x9f34;

	videomode(VIDEOMODE_40COL);

	pData = &charset[0][0];
	for(i = 0; i < CHARSET_COUNT; ++i) {
		vpoke(*pData++, pRam + i);
	}
	vera_layer_enable(0b10);

	*vConf = 0b0101000;
}


void pdrawcxy(unsigned char x, unsigned char y, unsigned char c) {
	vpoke(c, y*256+x*2);
	vpoke(colors[0][c], y*256+x*2+1);
}



#endif