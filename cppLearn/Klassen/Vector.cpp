#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(int x, int y){
    this->x = x;
    this->y = y;
}

void Vector::print(){
    cout << x << ", " << y << endl;
}
