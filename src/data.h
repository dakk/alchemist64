#ifndef DATA_H__
#define DATA_H__


#define CHAR_Y 8

#define VIC_BASE_RAM			(0x8000)
#define VIC_BASE_RAM2			((char*)VIC_BASE_RAM)
#define	SCREEN_RAM				((char*)VIC_BASE_RAM+0x0400)
#define CHARMAP_RAM				((char*)VIC_BASE_RAM+0x0800)
#define COLOUR_RAM				((char*)0xd800)

#define CHARMAP_RAM2 ((char*)0x1ffe)


#define COLORS_COUNT 256

extern const char charset_colors[][CHAR_Y*2];


void load_font(void);

#endif