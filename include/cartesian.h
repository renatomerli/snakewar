#pragma once

using namespace std;
#include <utility>
#include <string>

struct Spin;

class Cartesian : protected std::pair<int,int>
{
    public: 
    Cartesian(int X=0, int Y=0) { set (X,Y) ;}
    
    void set (Cartesian _input){ set ( _input.getX(), _input.getY() );}
    void set (int X, int Y){ pair::first = X; pair::second = Y;}

    int getX() { return pair::first;}
    int getY() { return pair::second;}
    void setX(int X) {pair::first = X;};
    void setY(int Y) {pair::second = Y;}

    string get_name();

    int operator% (Cartesian _input);
    Cartesian operator+ (Spin _input);
    void operator+= (Cartesian _input);
    bool operator== (Cartesian _input);
    bool operator!= (Cartesian _input);
  
    void print();
};


typedef Cartesian Direction;


struct Spin : Cartesian
{

    public:
    Spin(int _X=0, int _Y=-1);
    Spin(Direction _direction);

    bool set(int,int);
    bool set(Direction _input);

    bool can_set(int _X, int _Y);
    bool can_set(Direction _direction);

};
