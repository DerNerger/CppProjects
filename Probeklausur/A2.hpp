#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;


/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A2_a
#define A2_b
//#define A2_c
//#define A2_d
//#define A2_e

vector<string> text;

#ifdef  A2_a
void einlesen() {
    ifstream s;
    s.open("Datei.txt");
    while(!s.eof()){
        string str;
        s >> str;
        text.push_back(str);
    }
}
#endif

#ifdef  A2_b
auto lambda1 = [](char c){ return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';};
#endif

#ifdef  A2_c
int vokal_counter = 0;
... lambda2 = ....
#endif

#ifdef  A2_d
... getComp() {
}
#endif

#ifdef  A2_e
void sortieren() {
...
}
#endif
