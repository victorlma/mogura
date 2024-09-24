CC=gcc
CFLAGS=-ggdb --std=c99 -Iinclude
LIBS=`pkg-config --libs ncurses`
SRCDIR=src
BUILDIR=build

.PHONY: clean

run: build
	./$(BUILDIR)/mogura

build: $(SRCDIR)/main.c $(SRCDIR)/mdefs.h
	mkdir -p $(BUILDIR)
	$(CC) $(CFLAGS) -o $(BUILDIR)/mogura $^ $(LIBS)

clean:
	rm -rf build/
