#include <iostream>
#include <string>

using namespace std;

class Taschenrechner{
    public:
    Taschenrechner(string &anfrage);

    string getAnfrage();
    int getErgebnis();

    private:
    string &anfrage;
    int readFak();
    int readSum();
    void overreadBlanks();
    int readExpr();
    int error;
    string::iterator it;
};


inline string Taschenrechner::getAnfrage(){
    return anfrage;
    cout << anfrage << endl;
}

