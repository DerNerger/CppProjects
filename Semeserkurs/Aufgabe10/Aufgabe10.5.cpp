#include <iostream>
#include <functional>
#include <math.h>

using namespace std;

double eval(function<double(double)> f,double x){
  return f(x);
}

int main(){
  function<double(double)> f = [](double x) { return x*x; };
  cout << "f(x)=x^2,   f(2)= " << eval(f, 2) << endl;

  function<double(double)> g = [](double x) { return 2*x+3; };
  cout << "g(x)=2x+3,  g(5)= " << eval(g, 5) << endl;

  cout << "h(x)=e^x,   h(1)= " << eval([](double x) { return exp(x); }, 1) << endl;
}
