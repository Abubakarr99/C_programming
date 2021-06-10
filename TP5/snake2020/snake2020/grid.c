#include<stdio.h>
#include<string.h>
#include <MLV/MLV_all.h>
#include"snake.c"

typedef struct _Grid{
    char** grid;
    int nbc;
    int nbl;
}Grid;

enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};


void debug(Grid* grid, int nbl, int nbc){
        for(int i=0;i<nbl;i++)
        {
                for(int j=0;j<nbc+1;j++)
                {
                        printf("%c", grid->grid[i][j]);
                }
        }
}


int  compute_size(int h, int w)
{
	int i, j;
	i = h/NBL;
	j = w/NBC;
	return i < j ? i:j;
}

void draw_grid(Grid* grid){
	int h, w, carre;
	h = MLV_get_window_height ();
	w = MLV_get_window_width ();
	carre = compute_size(h, w);
	//printf("%d %d\n", grid->nbl, grid->nbc);
        for(int i=0;i<grid->nbl;i++)
                for(int j=0;j<grid->nbc+1;j++)
                {
                    if (grid->grid[i][j] == WALL){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLACK );
                    }
                    else if(grid->grid[i][j] == EMPTY){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_WHITE );
                    }
                    else if(grid->grid[i][j] == FRUIT){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GOLD );
                    }
                    else if(grid->grid[i][j] == SNAKE){
                        MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GREEN );
                    }
                }
        }

void place_snake(Grid* grid, Snake serpent){
	int i;
	for(i=0;i<SNAKE_SIZE; i++){
		grid->grid[serpent.pos[i].x][serpent.pos[i].y] = 's';
	}
}

enum Element move_snake(Snake *serpent, Grid* grid){
	int val;
	grid->grid[serpent->pos[3].x][serpent->pos[3].y] = ' ';
	crawl(serpent);
	switch (grid->grid[serpent->pos[0].x][serpent->pos[0].y]) {
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
    	grid->grid[serpent->pos[0].x][serpent->pos[0].y] = 's';
    	return val;
}


Grid* allocate_grid(int n, int m){
    int i;
    Grid* g = (Grid*) malloc(sizeof(Grid));
    g->grid = (char**) malloc(sizeof(char*)*m);
    for(i=0;i<m;i++){
        g->grid[i] = (char*) malloc(sizeof(char)*n);
    }
    return g;
}

int free_grid(Grid* grid, int* n, int* m){
    free(n);
    free(m);
    free(grid);
    return 0;
}



