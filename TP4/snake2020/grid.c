#include<stdio.h>
#include<string.h>
#include "grid.h"
#include "snake.c"
#include <MLV/MLV_all.h>



int  compute_size(int h, int w)
{
	int i, j;
	i = h/NBL;
	j = w/NBC;
	return i < j ? i:j;
}

void draw_grid(char grid[NBL][NBC+1]){
	int h, w, carre;
	h = MLV_get_window_height ();
	w = MLV_get_window_width ();
	carre = compute_size(h, w);
        for(int i=0;i<NBL;i++)
        {
                for(int j=0;j<NBC+1;j++)
                {

                    switch (grid[i][j]) {
                        case WALL:
                            MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLUE );
                            break;
                        case EMPTY:
                            MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_WHITE );
                            break;
                        case FRUIT:
                            MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GREEN );
                            break;
                        case SNAKE:
                            MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLACK );
                            break;
                    }
                }
        }
}

void place_snake(char grid[NBL][NBC+1], Snake serpent){
	int i;
	for(i=0;i<SNAKE_SIZE; i++){
		grid[serpent.pos[i].x][serpent.pos[i].y] = 's';
	}
}

enum Element move_snake(Snake *serpent, char grid[NBL][NBC+1]){
    int val;
	grid[serpent->pos[3].x][serpent->pos[3].y] = ' ';
	crawl(serpent);
    switch (grid[serpent->pos[0].x][serpent->pos[0].y]) {
        case WALL:
           val = WALL;
            break;
        case EMPTY:
            val= EMPTY;
            break;
        case FRUIT:
            val= FRUIT;
            break;
    }
    grid[serpent->pos[0].x][serpent->pos[0].y] = 's';
    return val;
}


