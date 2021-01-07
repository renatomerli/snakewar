#include "cartesian.h"
#include "globals.h"
#include <iostream>

void testspin ()
{
cout << endl << "Testing spins..." << endl;

cout << "moving down from up ?" << (Spin(UP).can_set(DOWN) ? "sim" : "nao") << endl; 
cout << "moving up from right ?" << (Spin(UP).can_set(RIGHT) ? "sim" : "nao") << endl; 
cout << "moving up from left ?" << (Spin(UP).can_set(LEFT) ? "sim" : "nao") << endl; 
}

void testdot ()
{
cout << endl << "Testing dots..." << endl;
cout << "x ";
Cartesian x (1,2); x.print();
cout << "y ";
Cartesian y (2,3); y.print();


cout << "z (x+y) ";
Cartesian z = x + y; z.print();

cout << "diif (x <> y) " <<  x % y << endl;


cout << "(x == y) ? " << (x == y ? "true" : "false") << endl ;


}


int main()
{

    testspin();
    testdot();

}