#define SNAKE_SIZE 4
struct _Coord{
	int x;
	int y;
};

typedef struct _Coord Coord;

typedef enum  {TOP='q', BOTTOM='d', LEFT='z', RIGHT='x' } direction;

struct struct_snake{
	Coord pos[SNAKE_SIZE];
	direction dir;
};

typedef struct struct_snake Snake;

void crawl(Snake *serpent);
