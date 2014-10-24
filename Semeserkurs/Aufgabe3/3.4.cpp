#include <iostream>
#include <cctype>
using namespace std;

int readExpr();
int readSum();
int readFak();
void overreadBlanks();
int error = 0;

int main() {
	cout << "Bitte Term eingeben:" << endl;
	int result = readExpr();
        if(error){
            cout << "Synaxfehler!" << endl;
            return 1;
        } else {
            cout << result << endl;
	    return 0;
        }
}

int readExpr(){
	int lhs = readSum();
	if(!error){
		overreadBlanks();
		while((cin.peek() == '+') || (cin.peek() == '-')){
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

void overreadBlanks(){
    char c;
    if(isspace(cin.peek()))
        cin.get(c);
}

int readSum(){
	int lhs = readFak();
	if(!error){
		overreadBlanks();
		while((cin.peek() == '*') || (cin.peek() == '/')){
			char c;
			cin.get(c);
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

int readFak(){
	overreadBlanks();
	int result = 0;
	char c;
	if((cin.peek() == '+') || (cin.peek()=='-')){
		cin.get(c);
		result = readFak();
		if(c=='-')
			result *= -1;
	} else {
		if(isdigit(cin.peek())){ //isdigit
			cin >> result;
		} else {
			//Klammer
			cin.get(c);
			if(c == '('){
				result = readExpr();
				if(!error){
					overreadBlanks();
					cin.get(c); //read )
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

