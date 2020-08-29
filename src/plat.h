#ifndef ARCH_H__
#define ARCH_H__

#define VIC_BASE_RAM			(0x8000)
#define COLOUR_RAM				((char*)0xd800)
#define	SCREEN_RAM				((char*)VIC_BASE_RAM+0x0400)

void pinit(void);
void pdrawcxy(int x, int y, char c);

#endif