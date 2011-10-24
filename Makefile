
CC = gcc
CFLAGS = -g -Wall
PREFIX = $(HOME)

LIBS = -lgit2
LIB_OBJS = usage.o
PROS = add

all: $(PROS)

install: $(PROS)
	install $(PROS) $(PREFIX)/bin/

add: add.o $(LIB_OBJS)
	$(CC) -o add add.o $(LIB_OBJS) $(LIBS)

add.o: add.c
	$(CC) $(CFLAGS) -c add.c

usage.o: usage.c
	$(CC) $(CFLAGS) -c usage.c

clean:
	rm $(PROS) *.o
