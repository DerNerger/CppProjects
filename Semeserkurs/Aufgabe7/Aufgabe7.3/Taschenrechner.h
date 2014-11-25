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
#include "Tree.h"

using namespace std;

class Taschenrechner{
    public:
    Taschenrechner(string &anfrage);

    string getAnfrage();
    Tree* getTree();

    private:
    string &anfrage;
    Tree* readFak();
    Tree* readSum();
    void overreadBlanks();
    Tree* readExpr();
    int error;
    string::iterator it;
};


inline string Taschenrechner::getAnfrage(){
    return anfrage;
}


#endif /* TASCHENRECHNER_H_ */
