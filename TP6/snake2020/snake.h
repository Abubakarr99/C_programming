#define NBL 22
#define NBC 36
#define SNAKE_SIZE 4

typedef struct _Coord{
    int x;
    int y;
    struct _Coord *next;
}Coord;

typedef enum  {TOP='q', BOTTOM='d', LEFT='z', RIGHT='x' } direction;

typedef struct struct_snake{
    Coord pos[SNAKE_SIZE];
    Coord *segments_list;
    int size;
    direction dir;
}Snake;

void crawl(Snake *serpent);
Snake* new_snake();
void add_segment(Snake* serpent, int x, int y);
void free_snake(Snake *serpent);
