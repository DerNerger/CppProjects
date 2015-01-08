#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

int main(){
  function<double(double)> f = [](double x) { return x*x; };
  function<double(double)> dfdx = [](double x) { return 2*x; };

  auto newton = [] (function<double(double)> f, function<double(double)> dfdx, double start, double gen){
    double current = start;
    while( abs(f(current)) > gen ){
      current -= f(current) / dfdx(current);
    }
    return current;
  };

  int x_0 = newton(f, dfdx, 6, 0.01);
  cout << "x_0=" << x_0 << endl;
}
