CC = gcc
CFLAGS = -DVERSION=\"$(shell git describe --tags --long 2>/dev/null || echo unknown)\" -Wall -Wextra -O2
LDFLAGS = 
INSTALL_DIR = /usr/local/bin

.PHONY: all clean install uninstall

all: catmd

catmd: catmd.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o catmd

install: catmd
	install -m 755 catmd $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/catmd
