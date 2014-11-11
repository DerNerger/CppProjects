#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Format{
  private:
    int sum;
    int nk;

  int getStellen(int z){
    int stellen = 0;
    if(z<=0){
      ++stellen;
      z*=-1;
    }

    while(z>0){
      z/=10;
      ++stellen;
    }
    return stellen;
  }

  public:
    Format(int a, int b) : sum(a), nk(b) {}

    string toString(double z);
};

string Format::toString(double z){
  int vks = (int) z;
  z -= vks;
  int vksc = getStellen(vks);
  int stellen = vksc + 1 + nk;
  int max = (stellen > sum) ? stellen : sum;
 
  char chars[max+1];
  chars[max] = '\0';
  int i;
  for(i=0; i<12-stellen; i++)
    chars[i]=' ';
  
  if(vks<0){
    vks*=-1;
    chars[i++]='-';
  }
  for(int j = max - nk - 2; j>=i ;j--){
    chars[j]=(vks%10)+'0';
    vks/=10;
  }

  if(z<0) z*= -1;
  chars[max - nk - 1] = ','; 

  for(int j=max - nk; j<max; j++){
    z *= 10;
    if(j == (max -1))
      z = round(z);
    int nk = ((int)z)%10;
    chars[j] = nk+'0';
  }
  return chars;
}
