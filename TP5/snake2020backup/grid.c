#include<stdio.h>
#include<string.h>
#include"snake.c"
#define NBL 22
#define NBC 36
#include <MLV/MLV_all.h>

typedef struct _Grid{
	int nbc;
	int nbl;
	char **grid;
}Grid;

Grid* allocate_grid(int n, int m){
    int i;
    Grid* tab = (Grid*) malloc(sizeof(Grid));
    tab->grid = (char**) malloc(sizeof(char*)*m);
    for(i=0;i<m;i++){
        tab->grid[i] = (char*) malloc(sizeof(char)*n);
    }
    return tab;
}

void free_grid(Grid* grid){
	free(&grid->nbl);
	free(&grid->nbl);
	free(grid->grid);
}


enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};

void debug(Grid* grid){
        for(int i=0;i<grid->nbl;i++)
        {
                for(int j=0;j<grid->nbc;j++)
                {
                        printf("%c", grid->grid[i][j]);
                }
                printf("\n");
        }

}


int  compute_size(int h, int w)
{
	int a, i, j;
	i = h/NBL;
	j = w/NBC;
	return i < j ? i:j;
}

void draw_grid(Grid* grid){
	int h, w, carre;
	enum Element symbol;
	h = MLV_get_window_height ();
	w = MLV_get_window_width ();
	carre = compute_size(h, w);
        for(int i=0;i<grid->nbl;i++)
        {
                for(int j=0;j<grid->nbc+1;j++)
                {

			if (grid->grid[i][j] == WALL){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLUE );
			}
			else if(grid->grid[i][j] == EMPTY){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_WHITE );
			}
			else if(grid->grid[i][j] == FRUIT){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GREEN );
			}
			else if(grid->grid[i][j] == SNAKE){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLACK );
			}


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


