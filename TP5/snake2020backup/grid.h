#include"snake.h"
#define NBL 22
#define NBC 36
typedef struct _Grid{
    char** grid;
    int nbc;
    int nbl;
}Grid;

typedef struct _Grid Grid;
void free_grid(Grid* grid);
void place_snake(Grid* grid, Snake serpent);
void debug(Grid* grid);
int  compute_size(int h, int w);
void draw_grid(Grid* grid);
enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};
enum Element move_snake(Snake *serpent, Grid* grid);
Grid* allocate_grid(int n, int m);
