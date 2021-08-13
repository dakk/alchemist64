#ifdef __C64__

#include <cbm.h>
#include <string.h>
#include "plat.h"
#include "data.h"

#define VIC_BASE_RAM			(0x8000)
#define COLOUR_RAM				((char*)0xd800)
#define	SCREEN_RAM				((char*)VIC_BASE_RAM+0x0400)
#define CHARMAP_RAM				((char*)VIC_BASE_RAM+0x0800)

#define MEM_KRNL_PRNT			((char*)0x288)

void pinit() {
	unsigned short i = 0;
	const u8_t *pData = &charset[0][0];

	CIA2.ddra |= 0x03;
	CIA2.pra = (CIA2.pra & 0xfc) | (3-(VIC_BASE_RAM / 0x4000));
	VIC.addr = ((((short)(SCREEN_RAM - VIC_BASE_RAM) / 0x0400) << 4) + (((short)(CHARMAP_RAM - VIC_BASE_RAM) / 0x0800) << 1));
	VIC.ctrl2 |= 16;
	VIC.ctrl1 = 0x1b;
	VIC.bordercolor = VIC.bgcolor0 = COLOR_LIGHTBLUE;
	VIC.bgcolor1 = COLOR_BROWN;
	VIC.bgcolor2 = 11;

	*MEM_KRNL_PRNT = (short)SCREEN_RAM / 256;

	for(i; i < CHARSET_COUNT; ++i)
		CHARMAP_RAM[i] = *pData++;
}

void pdrawcxy(u8_t x, u8_t y, u8_t c) {
	COLOUR_RAM[y*40+x] = colors[0][c-128];
	SCREEN_RAM[y*40+x] = c;
}

#endif