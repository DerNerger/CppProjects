#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double p;
    double q;
    cout << "x^2 + px + q => bitte p und q eingeben" << endl;
    cin >> p >> q;
    cout << "Eingabe: p=" << p << ", q=" << q << endl;

    double underSqrt = pow(p/2,2) - q;
    if(underSqrt < 0)
        cout << "Es Existieren 0 Loesungen" << endl;
    else if(abs(underSqrt) < 0.1e-6)
    {
        cout << "Es Existiert 1 Loesung" << endl;
        cout << "x = " << -p/2 + sqrt(underSqrt) << endl;
    }
    else
    {
        cout << "Es Existieren 2 Loesungen" << endl;
        cout << "x1 = " << -p/2 + sqrt(underSqrt) << endl;
        cout << "x2 = " << -p/2 - sqrt(underSqrt) << endl;
    }
 
    return 0;
}
