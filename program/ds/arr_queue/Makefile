CFLAGS=-Wall -I.

all: main

main: main.o queue.o
	gcc -o $@ $^ $(CFLAGS)

%.o: %.c queue.h
	gcc -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o *~ main
