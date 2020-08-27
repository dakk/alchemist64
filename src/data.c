#define CHAR_Y 8

#define CHARSET_COUNT 2048
const char charset[][CHAR_Y * 2] = {
	{ 0x3c,0x66,0x6e,0x6e,0x60,0x62,0x3c,0x00,0x18,0x3c,0x66,0x7e,0x66,0x66,0x66,0x00 },
	{ 0x7c,0x66,0x66,0x7c,0x66,0x66,0x7c,0x00,0x3c,0x66,0x60,0x60,0x60,0x66,0x3c,0x00	},
	{ 0x78,0x6c,0x66,0x66,0x66,0x6c,0x78,0x00,0x7e,0x60,0x60,0x78,0x60,0x60,0x7e,0x00	},
	{ 0x7e,0x60,0x60,0x78,0x60,0x60,0x60,0x00,0x3c,0x66,0x60,0x6e,0x66,0x66,0x3c,0x00	},
	{ 0x66,0x66,0x66,0x7e,0x66,0x66,0x66,0x00,0x3c,0x18,0x18,0x18,0x18,0x18,0x3c,0x00	},
	{ 0x1e,0x0c,0x0c,0x0c,0x0c,0x6c,0x38,0x00,0x66,0x6c,0x78,0x70,0x78,0x6c,0x66,0x00	},
	{ 0x60,0x60,0x60,0x60,0x60,0x60,0x7e,0x00,0x63,0x77,0x7f,0x6b,0x63,0x63,0x63,0x00	},
	{ 0x66,0x76,0x7e,0x7e,0x6e,0x66,0x66,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x3c,0x00	},
	{ 0x7c,0x66,0x66,0x7c,0x60,0x60,0x60,0x00,0x3c,0x66,0x66,0x66,0x66,0x3c,0x0e,0x00	},
	{ 0x7c,0x66,0x66,0x7c,0x78,0x6c,0x66,0x00,0x3c,0x66,0x60,0x3c,0x06,0x66,0x3c,0x00	},
	{ 0x7e,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00	},
	{ 0x66,0x66,0x66,0x66,0x66,0x3c,0x18,0x00,0x63,0x63,0x63,0x6b,0x7f,0x77,0x63,0x00	},
	{ 0x66,0x66,0x3c,0x18,0x3c,0x66,0x66,0x00,0x66,0x66,0x66,0x3c,0x18,0x18,0x18,0x00	},
	{ 0x7e,0x06,0x0c,0x18,0x30,0x60,0x7e,0x00,0x3c,0x30,0x30,0x30,0x30,0x30,0x3c,0x00	},
	{ 0x0c,0x12,0x30,0x7c,0x30,0x62,0xfc,0x00,0x3c,0x0c,0x0c,0x0c,0x0c,0x0c,0x3c,0x00	},
	{ 0x00,0x18,0x3c,0x7e,0x18,0x18,0x18,0x18,0x00,0x10,0x30,0x7f,0x7f,0x30,0x10,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x00,0x18,0x00	},
	{ 0x66,0x66,0x66,0x00,0x00,0x00,0x00,0x00,0x66,0x66,0xff,0x66,0xff,0x66,0x66,0x00	},
	{ 0x18,0x3e,0x60,0x3c,0x06,0x7c,0x18,0x00,0x62,0x66,0x0c,0x18,0x30,0x66,0x46,0x00	},
	{ 0x3c,0x66,0x3c,0x38,0x67,0x66,0x3f,0x00,0x06,0x0c,0x18,0x00,0x00,0x00,0x00,0x00	},
	{ 0x0c,0x18,0x30,0x30,0x30,0x18,0x0c,0x00,0x30,0x18,0x0c,0x0c,0x0c,0x18,0x30,0x00	},
	{ 0x00,0x66,0x3c,0xff,0x3c,0x66,0x00,0x00,0x00,0x18,0x18,0x7e,0x18,0x18,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x03,0x06,0x0c,0x18,0x30,0x60,0x00	},
	{ 0x3c,0x66,0x6e,0x76,0x66,0x66,0x3c,0x00,0x18,0x18,0x38,0x18,0x18,0x18,0x7e,0x00	},
	{ 0x3c,0x66,0x06,0x0c,0x30,0x60,0x7e,0x00,0x3c,0x66,0x06,0x1c,0x06,0x66,0x3c,0x00	},
	{ 0x06,0x0e,0x1e,0x66,0x7f,0x06,0x06,0x00,0x7e,0x60,0x7c,0x06,0x06,0x66,0x3c,0x00	},
	{ 0x3c,0x66,0x60,0x7c,0x66,0x66,0x3c,0x00,0x7e,0x66,0x0c,0x18,0x18,0x18,0x18,0x00	},
	{ 0x3c,0x66,0x66,0x3c,0x66,0x66,0x3c,0x00,0x3c,0x66,0x66,0x3e,0x06,0x66,0x3c,0x00	},
	{ 0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x18,0x18,0x30	},
	{ 0x0e,0x18,0x30,0x60,0x30,0x18,0x0e,0x00,0x00,0x00,0x7e,0x00,0x7e,0x00,0x00,0x00	},
	{ 0x70,0x18,0x0c,0x06,0x0c,0x18,0x70,0x00,0x3c,0x66,0x06,0x0c,0x18,0x00,0x18,0x00	},
	{ 0x00,0x01,0x02,0x02,0x02,0x08,0x08,0x2f,0x00,0x40,0x80,0x80,0x80,0x20,0xe0,0xf8	},
	{ 0x00,0x01,0x02,0x02,0x02,0x08,0x08,0x2f,0x00,0x40,0x80,0x80,0x80,0x20,0xe0,0xf8	},
	{ 0x00,0x01,0x02,0x02,0x02,0x08,0x08,0x2f,0x00,0x40,0x80,0x80,0x80,0x20,0xe0,0xf8	},
	{ 0x00,0x01,0x02,0x02,0x02,0x08,0x08,0x2f,0x00,0x40,0x80,0x80,0x80,0x20,0xe0,0xf8	},
	{ 0x00,0x01,0x02,0x02,0x02,0x08,0x08,0x2f,0x00,0x40,0x80,0x80,0x80,0x20,0xe0,0xf8	},
	{ 0x00,0x01,0x02,0x02,0x02,0x08,0x08,0x2f,0x00,0x40,0x80,0x80,0x80,0x20,0xe0,0xf8	},
	{ 0x00,0x00,0x00,0x00,0x01,0x05,0x05,0x15,0x00,0x30,0xf0,0xc0,0x40,0x50,0x50,0x54	},
	{ 0x00,0x00,0x00,0x00,0x02,0x08,0x08,0x20,0x00,0x00,0x00,0x00,0x80,0x20,0x20,0x08	},
	{ 0x00,0x00,0x00,0x00,0x03,0x0f,0x0f,0x3d,0x00,0x00,0x00,0x00,0xc0,0xf0,0xf0,0x7c	},
	{ 0x00,0x00,0x00,0x00,0x02,0x0a,0x0a,0x29,0x00,0x00,0x00,0x00,0x80,0xa0,0xa0,0x68	},
	{ 0x00,0x0c,0x33,0x0f,0xc3,0x33,0x0f,0xc3,0x00,0xc0,0x30,0xc0,0x0c,0x30,0xc0,0x0c	},
	{ 0x00,0x00,0x00,0x00,0x03,0x04,0x08,0x08,0x00,0x00,0x00,0x00,0xc0,0x20,0x10,0x10	},
	{ 0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08	},
	{ 0x00,0x00,0x00,0x02,0x0f,0x0f,0x0f,0x0f,0x00,0x10,0x80,0x00,0xc0,0xc0,0xc0,0xc0	},
	{ 0x00,0x00,0x0a,0x02,0x03,0x02,0x03,0x0a,0x00,0x00,0xa0,0xc0,0x80,0xc0,0x80,0xa0	},
	{ 0x00,0x00,0x01,0x02,0x0a,0x0a,0x2a,0x2a,0x30,0x40,0x00,0x80,0xa0,0xa0,0xa8,0xa8	},
	{ 0x2f,0x2f,0x2f,0x0b,0x0b,0x02,0x00,0x00,0xf8,0xf8,0xf8,0xe0,0xe0,0x80,0x00,0x00	},
	{ 0x2f,0x2f,0x2f,0x0b,0x0b,0x02,0x00,0x00,0xf8,0xf8,0xf8,0xe0,0xe0,0x80,0x00,0x00	},
	{ 0x2f,0x2f,0x2f,0x0b,0x0b,0x02,0x00,0x00,0xf8,0xf8,0xf8,0xe0,0xe0,0x80,0x00,0x00	},
	{ 0x2f,0x2f,0x2f,0x0b,0x0b,0x02,0x00,0x00,0xf8,0xf8,0xf8,0xe0,0xe0,0x80,0x00,0x00	},
	{ 0x2f,0x2f,0x2f,0x0b,0x0b,0x02,0x00,0x00,0xf8,0xf8,0xf8,0xe0,0xe0,0x80,0x00,0x00	},
	{ 0x2f,0x2f,0x2f,0x0b,0x0b,0x02,0x00,0x00,0xf8,0xf8,0xf8,0xe0,0xe0,0x80,0x00,0x00	},
	{ 0x15,0x15,0x15,0x05,0x05,0x01,0x00,0x00,0x54,0x54,0x54,0x50,0x50,0x40,0x00,0x00	},
	{ 0x21,0x20,0x20,0x08,0x08,0x02,0x00,0x00,0x08,0x48,0x08,0x20,0x20,0x80,0x00,0x00	},
	{ 0x3d,0x3d,0x3d,0x0f,0x0f,0x03,0x00,0x00,0xfc,0xfc,0x7c,0xf0,0xf0,0xc0,0x00,0x00	},
	{ 0x25,0x25,0x29,0x0a,0x0a,0x02,0x00,0x00,0x58,0x58,0x68,0xa0,0xa0,0x80,0x00,0x00	},
	{ 0x33,0x0d,0x01,0x01,0x01,0x01,0x00,0x00,0x30,0xc0,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x08,0x08,0x04,0x03,0x00,0x00,0x00,0x00,0x10,0x10,0x20,0xc0,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10	},
	{ 0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x00	},
	{ 0x27,0x2d,0x27,0x2d,0x27,0x2d,0x2a,0x00,0xd8,0x78,0xd8,0x78,0xd8,0x78,0xa8,0x00	},
	{ 0x2a,0x2a,0x2a,0x2a,0x0a,0x0a,0x02,0x00,0xa8,0xa8,0xa8,0xa8,0xa0,0xa0,0x80,0x00	},
	{ 0xc3,0x99,0x91,0x91,0x9f,0x99,0xc3,0xff,0xe7,0xc3,0x99,0x81,0x99,0x99,0x99,0xff	},
	{ 0x83,0x99,0x99,0x83,0x99,0x99,0x83,0xff,0xc3,0x99,0x9f,0x9f,0x9f,0x99,0xc3,0xff	},
	{ 0x87,0x93,0x99,0x99,0x99,0x93,0x87,0xff,0x81,0x9f,0x9f,0x87,0x9f,0x9f,0x81,0xff	},
	{ 0x81,0x9f,0x9f,0x87,0x9f,0x9f,0x9f,0xff,0xc3,0x99,0x9f,0x91,0x99,0x99,0xc3,0xff	},
	{ 0x99,0x99,0x99,0x81,0x99,0x99,0x99,0xff,0xc3,0xe7,0xe7,0xe7,0xe7,0xe7,0xc3,0xff	},
	{ 0xe1,0xf3,0xf3,0xf3,0xf3,0x93,0xc7,0xff,0x99,0x93,0x87,0x8f,0x87,0x93,0x99,0xff	},
	{ 0x9f,0x9f,0x9f,0x9f,0x9f,0x9f,0x81,0xff,0x9c,0x88,0x80,0x94,0x9c,0x9c,0x9c,0xff	},
	{ 0x99,0x89,0x81,0x81,0x91,0x99,0x99,0xff,0xc3,0x99,0x99,0x99,0x99,0x99,0xc3,0xff	},
	{ 0x83,0x99,0x99,0x83,0x9f,0x9f,0x9f,0xff,0xc3,0x99,0x99,0x99,0x99,0xc3,0xf1,0xff	},
	{ 0x83,0x99,0x99,0x83,0x87,0x93,0x99,0xff,0xc3,0x99,0x9f,0xc3,0xf9,0x99,0xc3,0xff	},
	{ 0x81,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xff,0x99,0x99,0x99,0x99,0x99,0x99,0xc3,0xff	},
	{ 0x99,0x99,0x99,0x99,0x99,0xc3,0xe7,0xff,0x9c,0x9c,0x9c,0x94,0x80,0x88,0x9c,0xff	},
	{ 0x99,0x99,0xc3,0xe7,0xc3,0x99,0x99,0xff,0x99,0x99,0x99,0xc3,0xe7,0xe7,0xe7,0xff	},
	{ 0x81,0xf9,0xf3,0xe7,0xcf,0x9f,0x81,0xff,0xc3,0xcf,0xcf,0xcf,0xcf,0xcf,0xc3,0xff	},
	{ 0xf3,0xed,0xcf,0x83,0xcf,0x9d,0x03,0xff,0xc3,0xf3,0xf3,0xf3,0xf3,0xf3,0xc3,0xff	},
	{ 0xff,0xe7,0xc3,0x81,0xe7,0xe7,0xe7,0xe7,0xff,0xef,0xcf,0x80,0x80,0xcf,0xef,0xff	},
	{ 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xe7,0xff,0xff,0xe7,0xff	},
	{ 0x99,0x99,0x99,0xff,0xff,0xff,0xff,0xff,0x99,0x99,0x00,0x99,0x00,0x99,0x99,0xff	},
	{ 0xe7,0xc1,0x9f,0xc3,0xf9,0x83,0xe7,0xff,0x9d,0x99,0xf3,0xe7,0xcf,0x99,0xb9,0xff	},
	{ 0xc3,0x99,0xc3,0xc7,0x98,0x99,0xc0,0xff,0xf9,0xf3,0xe7,0xff,0xff,0xff,0xff,0xff	},
	{ 0xf3,0xe7,0xcf,0xcf,0xcf,0xe7,0xf3,0xff,0xcf,0xe7,0xf3,0xf3,0xf3,0xe7,0xcf,0xff	},
	{ 0xff,0x99,0xc3,0x00,0xc3,0x99,0xff,0xff,0xff,0xe7,0xe7,0x81,0xe7,0xe7,0xff,0xff	},
	{ 0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xcf,0xff,0xff,0xff,0x81,0xff,0xff,0xff,0xff	},
	{ 0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xff,0xfc,0xf9,0xf3,0xe7,0xcf,0x9f,0xff	},
	{ 0xc3,0x99,0x91,0x89,0x99,0x99,0xc3,0xff,0xe7,0xe7,0xc7,0xe7,0xe7,0xe7,0x81,0xff	},
	{ 0xc3,0x99,0xf9,0xf3,0xcf,0x9f,0x81,0xff,0xc3,0x99,0xf9,0xe3,0xf9,0x99,0xc3,0xff	},
	{ 0xf9,0xf1,0xe1,0x99,0x80,0xf9,0xf9,0xff,0x81,0x9f,0x83,0xf9,0xf9,0x99,0xc3,0xff	},
	{ 0xc3,0x99,0x9f,0x83,0x99,0x99,0xc3,0xff,0x81,0x99,0xf3,0xe7,0xe7,0xe7,0xe7,0xff	},
	{ 0xc3,0x99,0x99,0xc3,0x99,0x99,0xc3,0xff,0xc3,0x99,0x99,0xc1,0xf9,0x99,0xc3,0xff	},
	{ 0xff,0xff,0xe7,0xff,0xff,0xe7,0xff,0xff,0xff,0xff,0xe7,0xff,0xff,0xe7,0xe7,0xcf	},
	{ 0xf1,0xe7,0xcf,0x9f,0xcf,0xe7,0xf1,0xff,0xff,0xff,0x81,0xff,0x81,0xff,0xff,0xff	},
	{ 0x8f,0xe7,0xf3,0xf9,0xf3,0xe7,0x8f,0xff,0xc3,0x99,0xf9,0xf3,0xe7,0xff,0xe7,0xff	},
	{ 0xff,0xff,0xff,0x00,0x00,0xff,0xff,0xff,0xf7,0xe3,0xc1,0x80,0x80,0xe3,0xc1,0xff	},
	{ 0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xff,0xff,0xff,0x00,0x00,0xff,0xff,0xff	},
	{ 0xff,0xff,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0xff,0xff,0xff,0xff,0xff	},
	{ 0xff,0xff,0xff,0xff,0x00,0x00,0xff,0xff,0xcf,0xcf,0xcf,0xcf,0xcf,0xcf,0xcf,0xcf	},
	{ 0xf3,0xf3,0xf3,0xf3,0xf3,0xf3,0xf3,0xf3,0xff,0xff,0xff,0x1f,0x0f,0xc7,0xe7,0xe7	},
	{ 0xe7,0xe7,0xe3,0xf0,0xf8,0xff,0xff,0xff,0xe7,0xe7,0xc7,0x0f,0x1f,0xff,0xff,0xff	},
	{ 0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x00,0x00,0x3f,0x1f,0x8f,0xc7,0xe3,0xf1,0xf8,0xfc	},
	{ 0xfc,0xf8,0xf1,0xe3,0xc7,0x8f,0x1f,0x3f,0x00,0x00,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f	},
	{ 0x00,0x00,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xff,0xc3,0x81,0x81,0x81,0x81,0xc3,0xff	},
	{ 0xff,0xff,0xff,0xff,0xff,0x00,0x00,0xff,0xc9,0x80,0x80,0x80,0xc1,0xe3,0xf7,0xff	},
	{ 0x9f,0x9f,0x9f,0x9f,0x9f,0x9f,0x9f,0x9f,0xff,0xff,0xff,0xf8,0xf0,0xe3,0xe7,0xe7	},
	{ 0x3c,0x18,0x81,0xc3,0xc3,0x81,0x18,0x3c,0xff,0xc3,0x81,0x99,0x99,0x81,0xc3,0xff	},
	{ 0xe7,0xe7,0x99,0x99,0xe7,0xe7,0xc3,0xff,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9	},
	{ 0xf7,0xe3,0xc1,0x80,0xc1,0xe3,0xf7,0xff,0xe7,0xe7,0xe7,0x00,0x00,0xe7,0xe7,0xe7	},
	{ 0x3f,0x3f,0xcf,0xcf,0x3f,0x3f,0xcf,0xcf,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7	},
	{ 0xff,0xff,0xfc,0xc1,0x89,0xc9,0xc9,0xff,0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe	},
	{ 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f	},
	{ 0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff	},
	{ 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f	},
	{ 0x33,0x33,0xcc,0xcc,0x33,0x33,0xcc,0xcc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc	},
	{ 0xff,0xff,0xff,0xff,0x33,0x33,0xcc,0xcc,0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f	},
	{ 0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xe7,0xe7,0xe7,0xe0,0xe0,0xe7,0xe7,0xe7	},
	{ 0xff,0xff,0xff,0xff,0xf0,0xf0,0xf0,0xf0,0xe7,0xe7,0xe7,0xe0,0xe0,0xff,0xff,0xff	},
	{ 0xff,0xff,0xff,0x07,0x07,0xe7,0xe7,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00	},
	{ 0xff,0xff,0xff,0xe0,0xe0,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0x00,0x00,0xff,0xff,0xff	},
	{ 0xff,0xff,0xff,0x00,0x00,0xe7,0xe7,0xe7,0xe7,0xe7,0xe7,0x07,0x07,0xe7,0xe7,0xe7	},
	{ 0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f	},
	{ 0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff	},
	{ 0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00	},
	{ 0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0x00,0x00,0xff,0xff,0xff,0xff,0x0f,0x0f,0x0f,0x0f	},
	{ 0xf0,0xf0,0xf0,0xf0,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0x07,0x07,0xff,0xff,0xff	},
	{ 0x0f,0x0f,0x0f,0x0f,0xff,0xff,0xff,0xff,0x0f,0x0f,0x0f,0x0f,0xf0,0xf0,0xf0,0xf0	}
};


#define MAP_COUNT 1000
const char charset_map [][CHAR_Y * 2] = {
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x03,0x0f,0x0d,0x0d,0x0f,0x04,0x0f	},
	{ 0x12,0x05,0x20,0x02,0x01,0x13,0x09,0x03,0x20,0x16,0x37,0x2e,0x30,0x20,0x31,0x32	},
	{ 0x32,0x33,0x36,0x35,0x20,0x02,0x19,0x14,0x05,0x13,0x20,0x06,0x12,0x05,0x05,0x20	},
	{ 0x20,0x20,0x20,0x28,0x03,0x29,0x31,0x39,0x38,0x36,0x20,0x03,0x0f,0x0d,0x0d,0x0f	},
	{ 0x04,0x0f,0x12,0x05,0x20,0x05,0x0c,0x05,0x03,0x14,0x12,0x0f,0x0e,0x09,0x03,0x13	},
	{ 0x2c,0x20,0x0c,0x14,0x04,0x2e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x28,0x03,0x29,0x31,0x39,0x37,0x37,0x20,0x0d,0x09,0x03,0x12,0x0f,0x13,0x0f	},
	{ 0x06,0x14,0x20,0x03,0x0f,0x12,0x10,0x2e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x01,0x0c,0x0c,0x20,0x12	},
	{ 0x09,0x07,0x08,0x14,0x13,0x20,0x12,0x05,0x13,0x05,0x12,0x16,0x05,0x04,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x01,0x01,0x03	},
	{ 0x03,0x3e,0x41,0x53,0x51,0x57,0x45,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	},
	{ 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20	}
};


#define COLORS_COUNT 256

const char charset_colors[][CHAR_Y*2] = {
	{ 0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x0a,0x0a,0x0e,0x0e,0x0d,0x0d,0x0c,0x0c,0x0f,0x0f,0x0b,0x0b,0x0d,0x0d,0x0e,0x0c	},
	{ 0x0f,0x0f,0x0d,0x0d,0x0d,0x0d,0x00,0x00,0x00,0x00,0x0a,0x0a,0x0c,0x0c,0x0b,0x0f	},
	{ 0x0a,0x0a,0x0e,0x0e,0x0d,0x0d,0x0c,0x0c,0x0f,0x0f,0x0b,0x0b,0x0a,0x08,0x0c,0x0c	},
	{ 0x0f,0x0f,0x0a,0x08,0x0d,0x0d,0x00,0x00,0x00,0x00,0x0a,0x0a,0x0c,0x0c,0x0a,0x0a	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	},
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	}
};


#define VIC_BASE_RAM			(0x8000)
#define VIC_BASE_RAM2			((char*)VIC_BASE_RAM)
#define	SCREEN_RAM				((char*)VIC_BASE_RAM+0x0400)
#define CHARMAP_RAM				((char*)VIC_BASE_RAM+0x0800)
#define COLOUR_RAM				((char*)0xd800)

#define CHARMAP_RAM2 ((char*)0x1ffe)


#include <cbm.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

void load_font() {
	int i;
	const char *pData;


	// memset(SCREEN_RAM, ' ', 40*25);

	CIA2.ddra |= 0x03;
	CIA2.pra = (CIA2.pra & 0xfc) | (3-(VIC_BASE_RAM / 0x4000));
	VIC.addr = ((((int)(SCREEN_RAM - VIC_BASE_RAM) / 0x0400) << 4) + (((int)(CHARMAP_RAM - VIC_BASE_RAM) / 0x0800) << 1));
	VIC.ctrl2 |= 16;
	VIC.ctrl1 = 0x1b;
	VIC.bordercolor = VIC.bgcolor0 = COLOR_LIGHTBLUE;
	VIC.bgcolor1 = COLOR_BROWN;
	VIC.bgcolor2 = COLOR_BLACK;


	pData = &charset[0][0];
	for(i = 0; i < CHARSET_COUNT; ++i)
		CHARMAP_RAM[i] = *pData++;

	// pData = &charset_map[0][0];
	// for(i = 0; i < MAP_COUNT; ++i)
	// 	CHARMAP_RAM[i+2048] = *pData++;

	// pData = &charset_map[0][0];
	// for(i = 0; i < MAP_COUNT; ++i) {
	// 	COLOUR_RAM[i] = *pData++;
	// }

	// pData = &charset_map[0][0];
	// for(i = 0; i < MAP_COUNT; ++i)
	// 	COLOUR_RAM[i] = *pData++;




	// clrscr();


	// for (i=0;i<16; i++) {
	// 	COLOUR_RAM[(i*2)+40] = charset_colors[0][96+i*2];
	// 	SCREEN_RAM[(i*2)+40] = 96+i*2;
	// 	COLOUR_RAM[(i*2)+1+40] = charset_colors[0][97+i*2];
	// 	SCREEN_RAM[(i*2)+1+40] = 97+i*2;
	// 	COLOUR_RAM[(i*2)] = charset_colors[0][64+i*2];
	// 	SCREEN_RAM[i*2] = 64+i*2;
	// 	COLOUR_RAM[(i*2)+1] = charset_colors[0][65+i*2];
	// 	SCREEN_RAM[i*2+1] = 65+i*2;
	// }

	

	// i = 0;
	
	// gotoxy(10, 10);
	// textcolor(COLOR_BLACK);
	// cprintf("HELLOciao");

	// while (1) {
	// 	// SCREEN_RAM[1]++;
	// 	for(i=0;i<1024;i++);
	// 	// cputs("This is A Test\n");
	// 	// cputc(i++);
	// }


}