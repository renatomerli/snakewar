
// a multiplayer snake engine to provide a competition of game solving/AI algorithms

#include "globals.h"
#include "config.h"
#include "cartesian.h"
#include "engine.h"
#include "snake.h"
#include "ncview.h"
#include "sdlview.h"

#include<unistd.h>

using namespace std;
#include <list>
#include <string>

 
int main()
{

srand(time(NULL));

// define the board dimensions
Cartesian resolution(70,35);

// create the engine
Engine my_engine(resolution.getX(),resolution.getY());

// create and attach a SDL view
SdlView sdl_view;
sdl_view.init(resolution, 26);
my_engine.view = &sdl_view;

// create and attach a ncurses view
//NCView nc_view;
//nc_view.init(resolution);
//my_engine.view = &nc_view;


// create and attach five players
SnakeBase Player1("Player 1");  
my_engine.attach(&Player1);
    
SnakeBase Player2("player2");  
my_engine.attach(&Player2);

SnakeBase Player3("Player 3");  
my_engine.attach(&Player3);

SnakeBase Player4("Player 4");  
my_engine.attach(&Player4);

SnakeBase Player5("Player 5");  
my_engine.attach(&Player5);

// init engine and call its main loop
my_engine.init();
getchar();
my_engine.run();

}
