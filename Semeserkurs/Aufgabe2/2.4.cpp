#include <string>
#include <iostream>
#include <vector>

using namespace std;

static const char *strings[] = { "M" , "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
static const int values[] =    { 1000, 900 , 500, 400 , 100,  90 ,  50,   40,  10,    9,   5,    4,  1 };

int main()
{
    int z;
    cin >> z;


  vector<string> str(13);
  for(int i = 0; i<13; i++)
      str[i] = strings[i];

  vector<int> val(13);
  for(int i = 0; i<13; i++)
      val[i] = values[i];

  for(int i = 0; z != 0; i++)
  {
    while(z >= val[i]) {
      z -= val[i];
      cout << str[i];
    }
  }

    cout  << endl;
    return 0;    
}
