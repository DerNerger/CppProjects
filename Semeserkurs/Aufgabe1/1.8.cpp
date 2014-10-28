#include <iostream>

using namespace std;

int main()
{
    cout << "Geben Sie n1 und n2 an (n2>=n1): ";
    int n1, n2;
    cin >> n1 >> n2;
    
    //for
    int sum=0; 
    for(int i = n1; i <= n2; i++)
        sum+=i;
    cout << "Loesung mit for-Schleife: " << sum << endl;

    //while
    sum=0;
    int temp = n1;
    while(temp<=n2)
        sum += temp++;
    cout << "Loesung mit while-Schleife: " << sum << endl;

    //do while
    sum=0;
    temp = n1;
    do{
        sum += temp++;
    } while(temp<=n2);
    cout << "Loesung mit do while-Schleife: " << sum << endl;

    //ohne Schleife
    sum = ( n2*(n2+1) - n1*(n1-1) ) /2;
    cout << "Loesung ohne Schleife: " << sum << endl;
}
