#ifndef DRAW_H__
#define DRAW_H__

#define BACKGROUND 	0
#define TEXTCOLOR 	7
#define TEXTCOLOR2 	4
#define GRIDCOLOR 	6

#define GRID_PADDING_Y	5
#define GRID_PADDING_X  1
#define CELL_SIZE	2

// void draw_game_grid(void);
void draw_curblock(void);
void draw_info(void);
void draw_container(void);
void draw_gameover(void);
void draw_initialscreen(void);
void draw_grid_cell(int, int);

#endif