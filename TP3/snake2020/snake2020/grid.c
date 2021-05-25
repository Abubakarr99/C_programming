#include<stdio.h>
#include<string.h>
/*#include"snake.h"*/
#include"snake.c"
#define NBL 22
#define NBC 36
#include <MLV/MLV_all.h>


enum Element {WALL='w', EMPTY=' ', FRUIT='f', SNAKE='s'};

void debug(char matrice[][NBC], int ligne, int colonne){
        for(int i=0;i<ligne;i++)
        {
                for(int j=0;j<colonne;j++)
                {
                        printf("%c", matrice[i][j]);
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

void draw_grid(char grid[NBL][NBC+1]){
	int h, w, carre;
	enum Element symbol;
	h = MLV_get_window_height ();
	w = MLV_get_window_width ();
	carre = compute_size(h, w);
        for(int i=0;i<NBL;i++)
        {
                for(int j=0;j<NBC+1;j++)
                {

			if (grid[i][j] == WALL){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLUE );
			}
			else if(grid[i][j] == EMPTY){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_WHITE );
			}
			else if(grid[i][j] == FRUIT){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_GREEN );
			}
			else if(grid[i][j] == SNAKE){
				MLV_draw_filled_rectangle( j*carre, i*carre , carre, carre, MLV_COLOR_BLACK );
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

Snake move_snake(Snake serpent, char grid[NBL][NBC+1]){
	grid[serpent.pos[3].x][serpent.pos[3].y] = ' ';
	serpent = crawl(serpent);
	grid[serpent.pos[0].x][serpent.pos[0].y] = 's';
	
	return serpent;
}


