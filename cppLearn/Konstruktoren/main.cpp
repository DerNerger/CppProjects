#include <iostream>

using namespace std;

class A{
    private:
        int param;

    public:
    A() : param(0){
        cout << "normaler Konstruktor" << endl;
        cout << "param =" << param << endl;
    }
    
    A(int b) : param(b){
        cout << "normaler Konstruktor mit parameter" << endl;
        cout << "param =" << param << endl;
    }

    A(A &obj) : param(obj.param){
        cout << "copy constructor" << endl;
        cout << "param =" << param << endl;
    }
};

A blaa(A a){ //1x copy-Konstruktor
    return a; //1x copy-Kostruktor
}

int main(){
    A a(2);
    blaa(a);
//    blaa(2);
}
