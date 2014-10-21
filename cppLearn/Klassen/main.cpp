#include "Vector.h"
#include <iostream>

using namespace std;

int main(){
    //Vector a = Vector(1,2);
    Vector a(1,2);
    a.print();

    cout << "x=" << a.getX() << endl;
    cout << "y=" << a.getY() << endl;

    a.mult(10.0);
    a.print();
}
