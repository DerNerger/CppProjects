#include <iostream>
#include <cmath>

using namespace std;

long double ehoch(double x){

    if(x<0)
        return (1/ehoch(-x));
    long double result = 1;
    long double lastSum = 1;
    for(int i = 1; i < 1000; i++){
        lastSum *= x;
        lastSum /= i;
        result += lastSum;
    }
    return result;
}

int main(void){

    cout << "xxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    for(int i = -40; i< 40; i+=10){
        cout <<  ehoch(i) << "    " << exp(i) << "   " << abs(ehoch(i) - exp(i))  << endl;
    }
}
