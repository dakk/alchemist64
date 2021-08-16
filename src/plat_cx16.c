#ifdef __CX16__

#include <cx16.h>
#include <conio.h>
#include <time.h>
#include "plat.h"
#include "data.h"


#define gfx_address  0x4000

void pinit() {
	short i = 0;
	const u8_t *pData = &charset[0][0];
	u8_t *pRam = (u8_t *) 0xF800;
	u8_t *vConf = (u8_t *) 0x9f34;

	videomode(VIDEOMODE_40COL);

	for(i; i < CHARSET_COUNT; i++) {
		vpoke(*pData++, pRam + i);
	}
	vera_layer_enable(0b10);

	*vConf = 0b0101000;
}


void pdrawcxy(u8_t x, u8_t y, u8_t c) {
	vpoke(c, y*256+x*2);
	vpoke(colors[0][c - 128], y*256+x*2+1);
}


unsigned long ptime(void) {
	return time(NULL);
}



#endif