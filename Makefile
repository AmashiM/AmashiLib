CC=gcc
CFLAGS= -I./include

LIBS := amastr.h

all: link build

link: $(LIBS)

%.h:
	$(CC) -c ./lib/$*.c -o ./obj/$*.o $(CFLAGS)

build:
	$(CC) main.c $(wildcard ./obj/*.o) -o main $(CFLAGS)

clean:
	rm -f ./obj/*