#include "Taschenrechner.h"
#include <string>
#include <sstream>

Taschenrechner::Taschenrechner(string &a) : anfrage(a), error(0) {
    it = anfrage.begin();
}

Tree* Taschenrechner::getTree(){
    Tree *result = readExpr();
    if(error)
        cout << "Error" << endl;
    return result;
}


Tree* Taschenrechner::readExpr(){
        Tree *lhs = readSum();
        if(!error){
                overreadBlanks();
                while((*it == '+') || (*it == '-')){
                        Tree *rhs = readSum();
                        if(!error){
                        		lhs = new OperatorElement(lhs,'+',rhs);
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
    while(isspace(*it))
        it++;
}

Tree* Taschenrechner::readSum(){
        Tree *lhs = readFak();
        if(!error){
                overreadBlanks();
                while((*it == '*') || (*it == '/')){
                        char c = *it;
                        it++;
                        Tree* rhs = readFak();
                        if(!error){
                                if(c=='*')
                                		lhs = new OperatorElement(lhs,'*',rhs);
                                else
                                		lhs = new OperatorElement(lhs,'/',rhs);
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

Tree* Taschenrechner::readFak(){
    overreadBlanks();
    Tree *result = 0;
    char c;
    if((*it == '+') || (*it=='-')){
    c = *it; it++;
    result = readFak();
    if(c=='-')
    	result = new OperatorElement(new NumberElement(-1),'*',result);
    } else {
        if(isdigit(*it)){ //isdigit
            int currentPos = it - anfrage.begin();
            int length = 0;
            while(*it >='0' && *it<= '9'){
                length++;
                it++;
            }
            int z;
            istringstream(anfrage.substr(currentPos, length)) >> z;
            result = new NumberElement(z);
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
