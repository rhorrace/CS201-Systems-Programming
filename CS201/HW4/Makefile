CFLAGS = -pg -g -Wall -ansi -pedantic -O0

all: cls

cls: clsc.o
	gcc $(CFLAGS)  cls.o cls
cls.o: cls.c cls.h
	gcc $(CFLAGS) -o cls.c cls.h
clean:
	rm cls *~
