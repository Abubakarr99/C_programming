#define NBL 22
#define NBC 36
#define SNAKE_SIZE 4

typedef struct _Coord{
    int x;
    int y;
}Coord;

typedef enum  {TOP='q', BOTTOM='d', LEFT='z', RIGHT='x' } direction;

typedef struct struct_snake{
    Coord pos[SNAKE_SIZE];
    direction dir;
}Snake;

void crawl(Snake *serpent);

