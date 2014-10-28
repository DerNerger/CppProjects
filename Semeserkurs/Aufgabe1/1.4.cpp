#include <iostream>

using namespace std;

double max(double a, double b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    double a, b, c;
    cout << "Geben Sie 3 Zahlen ein:" << endl;
    cin >> a >> b >> c;
    cout << "max = " << max(max(a,b),c) << endl;
    return 0;
}
