all: lab10

binary: binary.c binary.h
	gcc -g -Wall -c binary.c

lab10: lab10.c binary.o
	gcc -g -Wall lab10.c binary.o -o lab10

clean:
	rm *.o lab10