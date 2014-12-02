#include <iostream>

using namespace std;

class A{
  private:
    int a;
    void print(){
      cout << a << endl;
    }
  public:
  friend void fuu(){
    cout << "BLAAAA" << endl;
  }
};

