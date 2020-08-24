#ifndef LOGIC_H__
#define LOGIC_H__


#define GRID_PADDING_Y	2
#define GRID_PADDING_X  3
#define GRID_HEIGHT 	8
#define GRID_WIDTH 		10

extern int elapsed;
extern int highscore;
extern int score;
extern char limit;
extern char nextblock[2];
extern char curblock[2];
extern int curblock_rot;
extern int curblock_pos;
extern char grid[GRID_HEIGHT][GRID_WIDTH];

int update(void);
void drop_curblock(void);
void generate_nextblock(void);
void new_game(void);

#endif