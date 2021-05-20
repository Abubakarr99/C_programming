CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lMLV
EXEC=maison prog 

all: $(EXEC)
maison: maison.o
	$(CC) -o $@ $^ $(LDFLAGS)
maison.o: maison.c
	$(CC) -o maison.o -c maison.c 
prog: prog.o sum.o
	$(CC) -o prog prog.o sum.o $(CFLAGS)
sum.o: sum.c
	$(CC) -o sum.o -c sum.c 
prog.o: prog.c sum.h
	$(CC) -o prog.o -c prog.c $(CFLAGS)
clean:
	rm  *.o
mrproper: clean
	rm -rf $(EXEC)
