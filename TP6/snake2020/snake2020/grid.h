#include"snake.h"
#define NBL 22
#define NBC 36



typedef struct _Grid{
    char** grid;
    int nbc;
    int nbl;
}Grid;
void place_snake(Grid* grid, Snake serpent);
int  compute_size(int h, int w);
void draw_grid(Grid* grid);
enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};
enum Element move_snake(Snake *serpent, Grid* grid);
Grid* allocate_grid(int n, int m);
int ** alloue(int n, int m);
int free_grid(Grid* grid, int* n, int* m);
void debug(Grid* grid, int nbl, int nbc);

