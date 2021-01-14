#pragma once

#include "cartesian.h"
#include "snake.h"
#include "config.h"
#include "ncview.h"

using namespace std;
#include <vector>



class Engine
{
    private:
    Cartesian resolution;
    int num_snakes = 0;

    unsigned int steps=0;
    Cartesian apple;
    int apple_count=0;

    public: ViewBase *view;

    list<SnakeBase*> snakes_list; 

    bool stoped=false;
    void reset_apple();
    void kill(SnakeBase*);

    bool have_dot (Cartesian);
    bool check_border (Cartesian);
    bool validate_step(Cartesian);
    Cartesian get_randon_dot();

    void move(SnakeBase*, Spin);

    public:
    Engine(int Xres, int Yres);
    void init();
    int get_num_snakes();
    list<SnakeBase*> get_snakes();

    bool attach(SnakeBase *_snake);
    void run();



}; // Engine
