#include <iostream>
#include "rational.h"

using namespace std;

int main(){
    //create rational from 5
    Rational r1;
    r1 = add(r1, 5);
    r1.ausgabe();

    //add 5 to r
    r1 = add(5, r1);
    r1.ausgabe();

    //Aufgabe 2.2
    print(r1);
}
