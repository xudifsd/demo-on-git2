
CC = gcc
CFLAGS = -g -Wall
PREFIX = $(HOME)

LIBS = -lgit2
LIB_OBJS = usage.o path.o setup.o
LIB_H = lib.h
PROS = add

all: $(PROS)

install: $(PROS)
	install $(PROS) $(PREFIX)/bin/

add: add.o $(LIB_OBJS)
	$(CC) -o add add.o $(LIB_OBJS) $(LIBS)

add.o: add.c $(LIB_H)
	$(CC) $(CFLAGS) -c add.c

path.o: $(LIB_H) path.c
	$(CC) $(CFLAGS) -c path.c

setup.o : setup.c $(LIB_H)
	$(CC) $(CFLAGS) -c setup.c

usage.o: usage.c $(LIB_H)
	$(CC) $(CFLAGS) -c usage.c

clean:
	rm $(PROS) *.o
