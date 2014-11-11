#include "Format.h"

int main(){
  Format f(12,3);
  cout << f.toString(789.906625) << endl;
  cout << f.toString(-123456789.906625) << endl;
}
