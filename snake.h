#pragma once

#include "cartesian.h"

using namespace std;
#include <string>
#include <list>
#include <iostream>

class SnakeBase
{
    public:
    Spin my_spin;
    list<Cartesian> body;
    string name;
    int my_num;
    int get_num() { return my_num; }


    Cartesian last_apple={0,0};
    bool apple_moved=false;

    bool alive = true;
    bool played = false;
    bool started = false;

    public:
    SnakeBase(string);
    ~SnakeBase() {body.empty(); }
    bool init (Cartesian _head, Spin _spin, int _my_num);

    bool is_alive() { return alive;}
    void die() { alive = false; } //cout << "Snake " << name << " foi pro inferno!!!" << endl; } 
    list<Cartesian>& get_body() { return body;}
    Cartesian get_head() {return body.front();}
    Spin get_spin() { return my_spin;}
    bool is_empty(Cartesian _dot, list<SnakeBase*> _list);
    bool can_move(Spin _spin, list<SnakeBase*>,  Cartesian resolution);

    int size() { return body.size();}
    string get_name();
    void print();
    Spin play(Cartesian resolution, Cartesian _target, std::list<SnakeBase*> snakes);

};











