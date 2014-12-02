#include"meinstring.h"
#include<iostream>
using namespace std;

int main() {
  MeinString str("String1");
  MeinString str2("String2");

  MeinString str3 = str + str2;

  cout << str3 << endl;
}

