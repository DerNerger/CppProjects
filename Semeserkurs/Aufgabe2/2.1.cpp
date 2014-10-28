#include <iostream>

using namespace std;

int pow(int base, int pot)
{
    int result = 1;
    for(int i = 0; i < pot; i++)
        result *= base;
    return result;
}

long parseLong(string &z)
{
    int st = 0;
    long result = 0;
    for(string::iterator it = z.end()-1; it >= z.begin(); --it) {
        result += (*it-'0') * pow(10,st++);
    }    
    return result;
}

long getCrossfoot(long z)
{
    int cSum = 0;
    while(z > 0)
    {
        cSum += z%10;
        z/=10;
    }
    return cSum;
}

int main()
{
    string str;
    cout << "Bitte geben Sie einen String ein: ";
    cin >> str;
    long z = parseLong(str);
    cout << "Zahl = " << z << endl;
    long z2 = getCrossfoot(z);
    cout << "Quersumme = " << z2 << endl;
    return 0;
}
