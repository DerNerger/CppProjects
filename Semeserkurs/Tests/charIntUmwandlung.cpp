#include <iostream>

using namespace std;


int main(void){

    //char - int
    char c = 'a';
    int i;
    i = c;
    cout << i << endl;
    i =(int) c;
    cout << i << endl;
    i = int(c);
    cout << i << endl;
    i = static_cast<int>(c);
    cout << i << endl;

    //bool - int
    bool a = 5;
    cout << a << endl;
    i = a;
    cout << "i=" << i << endl;
    a = false;
    cout.setf(ios_base::boolalpha);
    cout << a << endl;
    i = a;
    cout << "i=" << i << endl;
}
