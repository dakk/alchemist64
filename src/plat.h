#ifndef ARCH_H__
#define ARCH_H__

typedef unsigned char u8_t;
typedef unsigned short u16_t;

void pinit(void);
void pdrawcxy(u8_t x, u8_t y, u8_t c);
unsigned long ptime(void);

#endif