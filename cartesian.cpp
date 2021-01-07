#include "cartesian.h"
#include <iostream>
#include "globals.h"
using namespace std;


Cartesian Cartesian::operator+ (Spin _input)  {return  Cartesian( _input.first + first, _input.second + second); } 
void Cartesian::operator+= (Cartesian _input) { first += _input.first ; second += _input.second; }
int Cartesian::operator% (Cartesian _input) { return std::abs( _input.getX() - getX()) + std::abs(_input.getY() - getY()); }
bool Cartesian::operator== (Cartesian _input) {  return (_input.getX() == getX()) && (_input.getY() == getY()) ;  }    
bool Cartesian::operator!= (Cartesian _input) {  return ! ( _input == *this);  }    

void Cartesian::print() { cout << "X: " << first << " " << "Y: " << second << endl;}



string Cartesian::get_name()
{
    switch (first)
    {
    case -1:
        if (second == 0) return "LEFT";
        else return "";
        break;
    case 0:
        if (second == -1) return "UP";
        if (second == 1) return "DOWN";
        return "";
    case 1:
        if (second == 0) return "RIGHT";
        else return "";
    default:
        return "";
    }
    return "";
}
