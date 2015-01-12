#include <iostream>

using namespace std;

int main(){
  int a = static_cast<int>('a');
  int b = (int) 'a';
  int c = int('a');
  int d = 'a';
  const char * bla = "aaaa";
  int e = reinterpret_cast<int>(bla); //wasauchimmer dabei passiert
  cout << hex << a << endl;
  cout << hex << b << endl;
  cout << hex << c << endl;
  cout << hex << d << endl;
  cout << hex << e << endl;
}
