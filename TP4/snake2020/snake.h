#define NBL 22
#define NBC 36
#define SNAKE_SIZE 4

//typedef enum  {TOP='z', BOTTOM='x', LEFT='q', RIGHT='d' } direction;

typedef struct _Coord{
    int x;
    int y;
} Coord;
typedef enum  {TOP='z', BOTTOM='x', LEFT='q', RIGHT='d' } direction;
typedef struct struct_snake{
    Coord pos[SNAKE_SIZE];
    direction dir;
} Snake;






