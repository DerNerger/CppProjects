#include <iostream>

using namespace std;

int main(void)
{
    //Variante a
    int n = 1, sum = 0;
    while(n <= 100) {
        ++n; // Darf erst nach sum +=n stehen
        sum += n;
    }
    //richtig:
    n = 1, sum = 0;
    while(n <= 100) {
        sum += n;
        ++n;
    }

    //Variante b
    n = 1, sum = 1;
    while(n < 100) 
        n += 1; 
        sum += n; //steht nichtmehr in der Schleife
                  //Klammern setzen
    //richtig:
    n = 1, sum = 1; 
    while(n < 100){
        n += 1; 
        sum += n; 
    }

    //Variante c
    n = 100;
    sum = n*(n+1)/2; //Korrekt, da n*(n+1) immer gerade

    //Variante d
    n = 1; //n muss bei 0 starten
    while(n < 100) {
        int sum = 0; //sum wird jedesmal neu mit 0 initialisiert
        n = n + 1;
        sum = sum + n;
    }
    //richtig:
    n = 0, sum=0;
    while(n < 100) {
        n = n + 1;
        sum = sum + n;
    }

    //Variante e
    n = 1, sum = 0;
    while(n <= 0100) { //0100 ist oktalzahl und dezimal 64
        sum += n;
        ++n;
    }
    cout << sum << endl;
    //richtig:
    n = 1, sum = 0;
    while(n <= 100) { 
        sum += n;
        ++n;
    }
    cout << sum << endl;
}
