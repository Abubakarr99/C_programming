
#define SNAKE_SIZE 4
struct _Coord{
	int x;
	int y;
};

typedef struct _Coord Coord;

struct struct_snake{
	Coord pos[SNAKE_SIZE];
	enum direction dir;
};

typedef struct struct_snake Snake;

void crawl(Snake Serpent){

}

