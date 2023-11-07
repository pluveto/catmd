CC = gcc
CFLAGS = -DVERSION=\"$(shell git describe --always --tags 2>/dev/null || echo unknown)\" -Wall -Wextra -O2
LDFLAGS = 

.PHONY: all clean

all: catmd

catmd: catmd.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o catmd
