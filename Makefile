CC= g++ -std=c++11
INCLUDES = -Iinclude
NCURSES = $(shell pkg-config --libs --cflags ncurses)

REQ := $(shell pkg-config --cflags ncurses)

all: snakewar
ifndef REQ
    $(error "ncurses library not found. You need to install it to compile this project.")
endif

snakewar: cartesian.o spin.o snake.o engine.o 
	$(CC) -o snakewar cartesian.o spin.o snake.o engine.o snakewar.cpp $(NCURSES) $(CFLAGS) $(INCLUDES)

cartesian.o:
	$(CC) -c cartesian.cpp $(INCLUDES)

snake.o:
	$(CC) -c snake.cpp $(INCLUDES)

engine.o:
	$(CC) -c engine.cpp $(INCLUDES)

spin.o:
	$(CC) -c spin.cpp $(INCLUDES)

test: cartesian.o spin.o
	$(CC) test.cpp cartesian.o spin.o -o test $(INCLUDES)

.PHONY: clean
clean: 
	rm -rf *.o snakewar test
