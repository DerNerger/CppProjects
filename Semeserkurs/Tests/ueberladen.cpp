#include <iostream>

using namespace std;

void f1(int a, int b, bool c=true, int d=1){
    cout << "f1" << endl;
    cout.setf(ios_base::boolalpha);
    cout << a << " " << b << " " << c  << " "<< d << endl;
}

void f1(int a, bool b){
    cout << "f2" << endl;
}

int main(){
    f1(1,true);
}
