#include <iostream>
#include "iterateable.h"

using namespace std;

int main(){
  iterateable it;
  for(int i : it)
    cout << i << endl;
}
