/*
 * Taschenrechner.h
 *
 *  Created on: Nov 4, 2014
 *      Author: kibellus
 */

#ifndef TASCHENRECHNER_H_
#define TASCHENRECHNER_H_

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
}


#endif /* TASCHENRECHNER_H_ */
