#include "cartesian.h"

Spin::Spin(int _X, int _Y) : Cartesian(_X, _Y) {}
Spin::Spin(Direction _direction) :  Direction(_direction) {}

bool Spin::set(Direction _direction)
{
    return set (_direction.getX(), _direction.getY());        
}

bool Spin::set(int _X, int _Y)
{
    if ( ! can_set(_X, _Y) ) return false;
    Cartesian::set(_X, _Y);
    return true;        
}


bool Spin::can_set(Direction _direction)
{
    return can_set(_direction.getX(), _direction.getY());
}

bool Spin::can_set(int _X, int _Y)
{
    // validate directions rage
    if ( (_X < -1 || _X >2) || (_Y < -1 || _Y >2) ) return false;

    // if nothing changed we return true
    if (_X == getX() && _Y == getY()) return true;

    // snake cant be stopped on both directons
    if ( _X == 0 && _Y == 0 ) return false;

    // 180 degree of rotation is not valid]
    if ( (getX() == -1 && _X == 1) || (getX() == 1 && _X == -1) ) return false;
    if ( (getY() == -1 && _Y == 1) || (getY() == 1 && _Y == -1) ) return false;

    return true;
}




