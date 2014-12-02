#include"meinstring.h"
#include<iostream>

using namespace std;

int main() {
  MeinString str("String1");
  //at
  cout << str[0] << endl;
  
  //assign
  MeinString str2 = str;
  str2[6]='2';

  //ausgabe
  cout << "str= "<< str << endl;
  cout << "str2= "<< str2 << endl;

  //+=
  cout << "str += str2" << endl;
  str += str2;
  cout << "str= "<< str << endl;


  //+
  cout << "str3 = str + str2" << endl;
  MeinString str3 = str + str2;
  cout << "str = "<< str << endl;
  cout << "str2 = "<< str2 << endl;
  cout << "str3 = "<< str3 << endl;
}

