#include "Vector.h"

int main(){

  Vector a(1,2);
  Vector b(3,4);
  a = b;

  string str = a;
  cout << str << endl;

  /*
  Vector a(1,2);
  cout << a << endl;

  int arr[2] = {3,4};
  Vector b = arr;
  cout << b << endl;

  a+=b;
  cout << a << endl;

  Vector c = a+b;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
 
  cout << "c[0]=" << c[0] << endl;
  cout << "c[1]=" << c[1] << endl;
  //cout << "c[2]=" << c[2] << endl;

  a[0]=42;
  cout << a << endl;*/
}
