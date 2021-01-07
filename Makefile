CC= g++ -std=c++11
CFLAGS = -DMYDATE="\"`date`\"" 
INCLUDES = -Iinclude
NCURSES = $(shell pkg-config --libs --cflags ncurses)


all: snakewar

snakewar: cartesian.o spin.o snake.o engine.o 
	$(CC) -o snakewar cartesian.o spin.o snake.o engine.o snakewar.cpp $(NCURSES) $(CFLAGS) $(INCLUDES)

cartesian.o:
	$(CC) -c cartesian.cpp $(INCLUDES) $(CFLAGS) 

snake.o:
	$(CC) -c snake.cpp $(INCLUDES) $(CFLAGS) 

engine.o:
	$(CC) -c engine.cpp $(INCLUDES) $(CFLAGS) 

spin.o:
	$(CC) -c spin.cpp $(INCLUDES) $(CFLAGS) 

test:
	$(CC) test.cpp cartesian.o spin.o -o test $(INCLUDES) $(CFLAGS)

clean: cartesian.o spin.o	
	rm *.o snakewar test
