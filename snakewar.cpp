
// a multiplayer snake engine to provide a competition of game solving/IA algorithms

#include "globals.h"
#include "config.h"
#include "cartesian.h"
#include "engine.h"
#include "snake.h"
#include "view.h"

#include<unistd.h>

using namespace std;
#include <list>
#include <string>

void testdot();
void testspin();



 
int main()
{

#ifdef DEBUG
testdot();
testspin();
cout << endl << "<< Press any key >>" << endl;
getchar();
#endif

srand(time(NULL));
     setlocale(LC_ALL, "");


//cout << "iniciando com " << x-2 << " linhas e " << y-2 << " colunas" << endl;

Board my_view;
Cartesian resolution(my_view.get_resolution());
my_view.init(resolution);
Engine my_engine(resolution.getX()-2,resolution.getY()-2);
//Engine my_engine(5,5    );

my_engine.view = &my_view;
my_engine.init();


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

SnakeBase Player6("Player 6");  
my_engine.attach(&Player6);


my_engine.run();


}
