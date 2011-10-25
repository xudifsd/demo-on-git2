
CC = gcc
CFLAGS = -g -Wall
PREFIX = $(HOME)

LIBS = -lgit2
LIB_OBJS = usage.o path.o setup.o
PROS = add

all: $(PROS)

install: $(PROS)
	install $(PROS) $(PREFIX)/bin/

add: add.o $(LIB_OBJS)
	$(CC) -o add add.o $(LIB_OBJS) $(LIBS)

add.o: add.c usage.h
	$(CC) $(CFLAGS) -c add.c

path.o: path.h path.c
	$(CC) $(CFLAGS) -c path.c

setup.o : setup.c setup.h path.h usage.h
	$(CC) $(CFLAGS) -c setup.c

usage.o: usage.c usage.h
	$(CC) $(CFLAGS) -c usage.c

clean:
	rm $(PROS) *.o
