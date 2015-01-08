#include <iostream>

using namespace std;

int main(){
  auto func1 = [] (double a, double b, double c){
    return a+b+c;
  };
  cout << func1(2.0, 3.0, -5.2) << endl;

  int a=1, b=3;
  auto func2 = [a,b](int x){
    return a <= x && x<=b;
  };
  cout << boolalpha;
  cout << 2 << " element [1,3]="<< func2(2) << endl;
  cout << 0 << " element [1,3]="<< func2(0) << endl;

  int z=12;
  cout << "z=" << z << endl;
  auto func3 = [&z]() {
    z=-z;
  };
  func3();
  cout << "z=" << z << endl;
}
