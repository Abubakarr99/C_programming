#define SNAKE_SIZE 4
struct _Coord{
	int x;
	int y;
};

typedef struct _Coord Coord;

typedef enum  {TOP='z', BOTTOM='x', LEFT='q', RIGHT='d' } direction;

struct struct_snake{
	Coord pos[SNAKE_SIZE];
	direction dir;
};

typedef struct struct_snake Snake;

Snake crawl(Snake serpent);
/*void crawl(Snake serpent){
	if(serpent.dir==LEFT){
		serpent.pos[0].x = serpent.pos[0].y;		
}
}*/

