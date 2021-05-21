CC=gcc
CFLAGS=-W -Wall -ansi -pedantic

EXEC=game

all: $(EXEC)
game: game.o grid.o
	$(CC) -o game game.o grid.o -lMLV
grid.o: grid.c
	$(CC) -o grid.o -c grid.c
game.o: game.c grid.h
	$(CC) -o game.o -c game.c 


