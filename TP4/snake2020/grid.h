#include "snake.h"
#define NBL 22
#define NBC 36

void place_snake(char grid[NBL][NBC+1], Snake serpent);
int compute_size(int h, int w);
void draw_grid(char grid[NBL][NBC+1]);
enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};
enum Element move_snake(Snake *serpent, char grid[NBL][NBC+1]);

