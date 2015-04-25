CC=gcc
CFLAGS=-Wall -g
SDL_CFLAGS := $(shell sdl2-config --cflags) 
SDL_LDFLAGS := $(shell sdl2-config --libs) -lm 

all: matrix.o life.o gl 

life.o: life.c life.h
	$(CC) $(CFLAGS) -c life.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

gl: gl.c life.o 
	$(CC) $(CFLAGS) $(SDL_CFLAGS) gl.c sdl.o life.o matrix.o -o life $(SDL_LDFLAGS)

clean:
	rm life life.o matrix.o