#include"snake.h"
#define NBL 22
#define NBC 36

void place_snake(char grid[NBL][NBC+1], Snake serpent);
void debug(char matrice[NBL][NBC+1], int ligne, int colonne);
int  compute_size(int h, int w);
void draw_grid(char grid[NBL][NBC+1]);
enum Element;
void move_snake(Snake serpent, char grid[NBL][NBC+1]);

