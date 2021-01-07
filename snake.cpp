#include "snake.h"
#include "globals.h"

using namespace std;
#include <iostream>


SnakeBase::SnakeBase(string _name) { name = _name; }

bool SnakeBase::init (Cartesian _head, Spin _spin, int _my_num)
{
    if (started) return false;
    else started = true;
    my_num = _my_num;
    my_spin = _spin;
    body.push_front(_head);

    return true;
}

string SnakeBase::get_name() {return name; }

void SnakeBase::print () { for (auto _dot : body) _dot.print() ;}

bool SnakeBase::is_empty(Cartesian _dot, list<SnakeBase*> _list)
{
    for (SnakeBase * _snake : _list)
    {
        if (!_snake->is_alive()) continue;
        for (Cartesian _snakeDot : _snake->get_body())
        {
            if (_snakeDot == _dot) { /* cout << "colisao detectada em Snake" << endl ; */ return false; }
        }
    }
    return true;
}

bool SnakeBase::can_move(Spin _spin, list<SnakeBase*> _list,  Cartesian resolution)
{
    Cartesian head = get_head();
    Cartesian target = head + _spin;

    if ( (target.getX()  > resolution.getX()) || (target.getY() > resolution.getY()) ) return false;
    if ( (target.getX() < 0) || (target.getY() < 0) ) return false;

    for (SnakeBase * _snake : _list)
    {
        if (!_snake->is_alive()) continue;
        for (Cartesian _snakeDot : _snake->get_body())
        {
            if (_snakeDot == target) { /* cout << "colisao detectada em Snake" << endl ; */ return false; }
        }
    }


    return true;

}

Spin SnakeBase::play(Cartesian _resolution, Cartesian _target, std::list<SnakeBase*> snakes) 
{
 
     if (last_apple != _target) { /* cout << "Apple moved" << endl; */ last_apple = _target; apple_moved=true; }
     else apple_moved=false;

//    if (_target == get_head()) { cout << "What??? target ja eh head !!!" ; die(); }//  return NONE; } 

    int distance = get_head() % _target;

//    cout << "Name: " << get_name() << " - size " << size() << " and distance: " << distance << " to destiny " ; _target.print();
    if (( ((get_head() + UP) % _target) < distance) && my_spin.can_set(UP) && can_move (UP, snakes, _resolution)  ) {   return my_spin = UP; } 
    if ((  ((get_head() + DOWN) % _target) < distance) && my_spin.can_set(DOWN) && can_move (DOWN, snakes, _resolution)  ) {  return my_spin = DOWN; } 
    if ((  ((get_head() + RIGHT) % _target) < distance) && my_spin.can_set(RIGHT) && can_move (RIGHT, snakes, _resolution) ) {  return my_spin = RIGHT; }
    if ((  ((get_head() + LEFT) % _target) < distance) && my_spin.can_set(LEFT) && can_move (LEFT, snakes, _resolution) ) {  return my_spin = LEFT; } 

    if ( can_move (UP, snakes, _resolution ) ) return my_spin = UP;
    if ( can_move (DOWN, snakes, _resolution ) ) return my_spin = DOWN;
    if ( can_move (RIGHT, snakes, _resolution ) ) return my_spin = RIGHT;
    if ( can_move (LEFT, snakes, _resolution ) ) return my_spin = LEFT;

/*
    if (( ((get_head() + UP) % _target) < distance) && my_spin.can_set(UP)) {   return my_spin = UP; } 
    if ((  ((get_head() + DOWN) % _target) < distance) && my_spin.can_set(DOWN)) {  return my_spin = DOWN; } 
    if ((  ((get_head() + RIGHT) % _target) < distance) && my_spin.can_set(RIGHT) ) {  return my_spin = RIGHT; }
    if ((  ((get_head() + LEFT) % _target) < distance) && my_spin.can_set(LEFT) ) {  return my_spin = LEFT; } 
*/
 //   cout << "Algo errado aconteceu" << endl;
    return my_spin;

}
