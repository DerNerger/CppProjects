#include <iostream>

using namespace std;

class Test{
private:
  std::string str; 
public:
  Test(const char *s) : str(s) {cout<<str<<endl;}
};
