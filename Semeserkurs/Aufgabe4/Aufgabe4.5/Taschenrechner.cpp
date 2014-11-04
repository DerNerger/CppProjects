#include "Taschenrechner.h"
#include <string>

Taschenrechner::Taschenrechner(string &a) : anfrage(a) { 
    it = anfrage.begin();
}

int Taschenrechner::getErgebnis(){
    int result = readExpr();
    if(error)
        cout << "Error" << endl;
    return result;
}


int Taschenrechner::readExpr(){
        int lhs = readSum();
        if(!error){
                overreadBlanks();
                while((*it == '+') || (*it == '-')){
                        int rhs = readSum();
                        if(!error){
                                lhs += rhs;
                                overreadBlanks();
                        } else {
                            return 0;
                        }
                }
        } else {
            return 0;
        }
        return lhs;
}

void Taschenrechner::overreadBlanks(){
    if(isspace(*it))
        it++;
}

int Taschenrechner::readSum(){
        int lhs = readFak();
        if(!error){
                overreadBlanks();
                while((*it == '*') || (*it == '/')){
                        char c = *it;
                        it++;
                        int rhs = readFak();
                        if(!error){
                                if(c=='*')
                                        lhs *= rhs;
                                else
                                        lhs /= rhs;
                                overreadBlanks();
                        } else {
                            return 0;
                        }
                }
        } else {
            return 0;
        }
        return lhs;
}

int Taschenrechner::readFak(){
    overreadBlanks();
    int result = 0;
    char c;
    if((*it == '+') || (*it=='-')){
    c = *it; it++;
    result = readFak();
    if(c=='-')
        result *= -1;
    } else {
        if(isdigit(*it)){ //isdigit
            int currentPos = it - anfrage.begin();
            int length = 0;
            while(*it >='0' && *it<= '9'){
                length++;
                it++;
            }
            result = stoi( anfrage.substr(currentPos, length) );
        } else {
        //Klammer
            c = *it; it++;
            if(c == '('){
                result = readExpr();
                    if(!error){
                        overreadBlanks();
                        c = *it; it++;//read )
                        if(c!= ')'){
                            error = 1;
                            return 0;
                        }
                    } else {
                        return 0;
                    }
            } else {
                error = 1;
                return 0;
            }
        }
    }
    return result;
}
