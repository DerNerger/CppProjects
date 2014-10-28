#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Bitte geben Sie eine Zahl ein: ";
    cin >> x;
    for(int i = sizeof(int) * 8 - 1; i>=0; i--)
    {
        if((i+1) % 4 == 0 && i != sizeof(int) * 8 - 1)
            cout << " ";
        cout << ((x & (1<<i)) != 0);
    }
    cout << endl;
    return 0;
}
