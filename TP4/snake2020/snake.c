
void crawl(Snake *serpent){
    int x = serpent->pos[0].x;
    int y = serpent->pos[0].y;

    switch (serpent->dir) {
        case LEFT:
            serpent->pos[0].x = (x-1+NBC)%NBC;
            break;
        case RIGHT:
            serpent->pos[0].x = (x+1+NBC)%NBC;
            break;
        case TOP:
            serpent->pos[0].y = (y-1+NBL)%NBL;
            break;
        case BOTTOM:
            serpent->pos[0].y = (y+1+NBL)%NBL;
            break;
    }

    if (serpent->pos[SNAKE_SIZE-4].y == NBC)
        serpent->pos[SNAKE_SIZE-4].y = 0;
}