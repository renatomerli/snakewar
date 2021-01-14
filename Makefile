CC := g++ -std=c++11
TIMEFLAG := -DMYDATE="\"`date`\"" 
INCLUDES := -Iinclude
NCURSES := $(shell pkg-config --libs --cflags ncurses)
SDL := $(shell sdl2-config --cflags --libs)
SDL_IMAGE := $(shell pkg-config --libs --cflags SDL2_image)

REQ1 := $(shell pkg-config --cflags ncurses)
REQ2 := $(shell pkg-config --cflags sdl2)

all: snakewar
ifndef REQ1
    $(error "ncurses library not found. You need to install it to compile this project.")
endif
ifndef REQ2
    $(error "SDL2 library not found. You need to install it to compile this project.")
endif

snakewar: cartesian.o spin.o snake.o engine.o ncview.o sdlview.o
	$(CC) -o snakewar cartesian.o spin.o snake.o engine.o ncview.o sdlview.o snakewar.cpp $(INCLUDES) $(NCURSES) $(SDL) $(SDL_IMAGE) $(TIMEFLAG)

cartesian.o:
	$(CC) -c cartesian.cpp $(INCLUDES)  

spin.o:
	$(CC) -c spin.cpp $(INCLUDES)  

snake.o:
	$(CC) -c snake.cpp $(INCLUDES)  

engine.o:
	$(CC) -c engine.cpp $(INCLUDES)  

ncview.o:
	$(CC) -c ncview.cpp $(INCLUDES) 

sdlview.o:
	$(CC) -c sdlview.cpp $(INCLUDES) 

test:
	$(CC) -g test.cpp cartesian.o spin.o -o test $(INCLUDES) $(SDL) $(SDL_IMAGE)

.PHONY: clean
clean: cartesian.o spin.o	
	rm -rf *.o snakewar test

