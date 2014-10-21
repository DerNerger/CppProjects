#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
T abs(T a){
    if(a > 0)
        return a;
    else
        return -a;
}

template <>
bool abs<bool>(bool a){
    cout << "Datentyp Fehlerhaft" << endl;
    exit(1);
}


template <>
char abs<char>(char a){
    cout << "Datentyp Fehlerhaft" << endl;
    exit(1);
}

int main(){
    cout << "|-1|=" << abs(-1) << endl;
    cout << "|20.5|=" << abs(20.5) << endl;
    cout << "|-0.6f|=" << abs(-0.6f) << endl;
    cout << "|1000000l|=" << abs(1000000l) << endl;
    //cout << "|true|=" << abs(true) << endl;
    cout << "|'A'|=" << abs('A') << endl;
}
