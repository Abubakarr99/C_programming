CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lMLV

EXEC=game

all: $(EXEC)
game: game.o grid.o getlong.o
	$(CC) -o game game.o grid.o getlong.o -lMLV
getlong.o: getopt_long.c
	$(CC) -o getlong.o -c getopt_long.c
grid.o: grid.c snake.h
	$(CC) -o grid.o -c grid.c -lMLV
game.o: game.c grid.h getlong.h snake.h
	$(CC) -o game.o -c game.c
snake.o: snake.c
	$(CC) -o snake.o -c snake.c
clean:
	rm  *.o


