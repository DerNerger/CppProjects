#include <iostream>
#include "rational.h"

using namespace std;

int main(){
  Rational r;
  cin >> r;

  Rational r2;
  cin >> r2;


  Rational r3;
  cin >> r3;

  cout << boolalpha;
  cout << (r==r2) << endl; 

  Rational c = r + r2 + r3  ;
  c.ausgabe();
}
