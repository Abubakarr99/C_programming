#include "snake.c"
#define NBL 22
#define NBC 36


//typedef enum  {TOP='z', BOTTOM='x', LEFT='q', RIGHT='d' } direction;
#define SNAKE_SIZE 4
struct Coord;
struct struct_snake;
typedef struct struct_snake Snake;

Snake crawl(Snake serpent){
	int x = serpent.pos[0].x;
	int y = serpent.pos[0].y;
        if(serpent.dir==LEFT){
		serpent.pos[0].x = (x-1+NBC)%NBC;
	}
	else if(serpent.dir==RIGHT){
		serpent.pos[0].x = (x+1+NBC)%NBC;
	}
	else if(serpent.dir==TOP){
		serpent.pos[0].y = (y-1+NBL)%NBL;
	}
	else if(serpent.dir==BOTTOM){
		serpent.pos[0].y = (y+1+NBL)%NBL;
	}
	serpent.pos[SNAKE_SIZE-1] = serpent.pos[SNAKE_SIZE-2];
	serpent.pos[SNAKE_SIZE-2] = serpent.pos[SNAKE_SIZE-3];
	serpent.pos[SNAKE_SIZE-3] = serpent.pos[SNAKE_SIZE-4];
	serpent.pos[SNAKE_SIZE-4].y = y+1;
	printf("%d ", serpent.pos[SNAKE_SIZE-4].x);
	serpent.pos[SNAKE_SIZE-4].x = x;
	return serpent;
}



