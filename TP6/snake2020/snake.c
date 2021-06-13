#include "snake.h"

void crawl(Snake *serpent){
        int x = serpent->pos[0].x;
        int y = serpent->pos[0].y;
        switch (serpent->dir) {
            case LEFT:
                serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
                serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
                serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
                serpent->pos[0].x = (x-1+NBL)%NBL;
                break;
            case RIGHT:
                serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
                serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
                serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
                serpent->pos[0].x = (x+1+NBL)%NBL;
                break;
            case TOP:
                serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
                serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
                serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
                serpent->pos[0].y = (y-1+NBC)%NBC;
                break;
            case BOTTOM:
                serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
                serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
                serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
                serpent->pos[0].y = (y+1+NBC)%NBC;
                break;

            default:
                serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
                serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
                serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
                y=(y+1+NBC)%NBC;
                serpent->pos[0].x = x;
                serpent->pos[0].y = y;
                break;

        }


    }


Snake* new_snake()
{
        Snake *snake = malloc(sizeof(*snake));
        snake->segments_list=NULL;
        snake->size=0;
        return snake;
}

void add_segment(Snake* serpent, int x, int y)
{
	Coord *Coord1 = malloc(sizeof(*Coord1));
	Coord1->next=NULL;
	Coord1->x = x;
	Coord1->y = y;
	serpent->segments_list = Coord1;
}


void free_snake(Snake *serpent)
{
	Coord *asupprime;
	while(serpent->segments_list != NULL){
		asupprime = serpent->segments_list;
		serpent->segments_list = serpent->segments_list->next;
		free(asupprime);
	}
}





