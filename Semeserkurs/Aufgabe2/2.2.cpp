#include <iostream>

using namespace std;

struct Result{
    unsigned long long max;
    unsigned iterations;
};

Result collatz(unsigned long long z)
{
    unsigned long long max = z;
    unsigned iterations = 0;
    string dummy;
    getline(cin, dummy);
    do{
        if(z % 2 == 0)
            z /=2;
        else
            z = z*3 + 1;
        if(z > max)
        {
            max  = z;
            cout << "Neuer Hoechstwert: " << max << ". Weiter mit Enter." << endl;
            getline(cin, dummy);
        }
        iterations++;
    }while(z > 1);

    Result r;
    r.max = max;
    r.iterations = iterations;
    return r;
}

int main()
{
    unsigned long long start;
    cout << "Bitte geben Sie eine Startzahl ein: ";
    cin >> start;
    Result r = collatz(start);
    cout << "Es wurden " << r.iterations << " benoetigt." << endl;
    cout << "Der erreichte Hoechstwert war " << r.max << "." << endl;
    return 0;
}
