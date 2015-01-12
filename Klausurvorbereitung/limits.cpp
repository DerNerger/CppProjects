#include <iostream>
#include <climits>
#include <limits>
#include <cfloat>

using namespace std;

int main(){
  cout << INT_MIN << endl;
  cout << numeric_limits<int>::min() << endl;
  cout << DBL_MIN << endl;
  cout << numeric_limits<double>::min() << endl;
  cout << FLT_MIN << endl;
  cout << numeric_limits<float>::min() << endl;
}
