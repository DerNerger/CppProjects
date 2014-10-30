#include <iostream>

using namespace std;

class MeineKlasse{
    private:
    int _readonlyAttribut;

    public:
    MeineKlasse() : readonlyAttribut(_readonlyAttribut) {}

    void aendern(int x){
        _readonlyAttribut = x;
    }

    const int& readonlyAttribut;
};

int main() {
    MeineKlasse objekt;
    //objekt.readonlyAttribut = 999; // Fehler! nicht erlaubte Aktion
    objekt.aendern(999); // OK, Setter funktioniert!
    // erlaubter direkter lesender Zugriff:
    cout << "objekt.readonlyAttribut=" << objekt.readonlyAttribut << endl; // ok
}
