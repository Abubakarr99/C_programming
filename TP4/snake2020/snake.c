

void crawl(Snake *serpent){
    int x = serpent->pos[0].x;
    int y = serpent->pos[0].y;


     switch (serpent->dir) {
        case LEFT:
            serpent->pos[0].x = (x-1+NBL)%NBL;
	     serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
             serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
             serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
            break;
        case RIGHT:
            serpent->pos[0].x = (x+1+NBL)%NBL;
	    serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
            serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
            serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
            break;
        case TOP:
            serpent->pos[0].y = (y-1+NBC)%NBC;
	    serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
            serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
            serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
            break;
        case BOTTOM:
            serpent->pos[0].y = (y+1+NBC)%NBC;
	     serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
            serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
            serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
            break;

	default:
	    serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
            serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
            serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
            y=(y+1+NBC)%NBC;
            serpent->pos[SNAKE_SIZE-4].y = y;
            break;

    }


        /*serpent->pos[SNAKE_SIZE-1] = serpent->pos[SNAKE_SIZE-2];
        serpent->pos[SNAKE_SIZE-2] = serpent->pos[SNAKE_SIZE-3];
        serpent->pos[SNAKE_SIZE-3] = serpent->pos[SNAKE_SIZE-4];
        y=y+1;
        serpent->pos[SNAKE_SIZE-4].y = y;*/

    if (serpent->pos[SNAKE_SIZE-4].y == NBC)
        serpent->pos[SNAKE_SIZE-4].y = 0;
}

