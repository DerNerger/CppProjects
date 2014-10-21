#include <iostream>

using namespace std;

template <class T>
string  getType(T a){
    return "unbekannt";
}

template <>
string getType<bool> (bool a){
    return "bool";
}

template <>
string getType<int> (int a){
    return "int";
}

template <>
string getType<char> (char a){
    return "char";
}

template <>
string getType<float> (float a){
    return "float";
}

int main(){
    cout << getType(true) << endl;
    cout << getType(1) << endl;
    cout << getType(2.3) << endl;
    cout << getType(2.3f) << endl;
    cout << getType('A') << endl;
}
