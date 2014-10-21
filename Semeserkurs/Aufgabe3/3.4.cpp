#include <iostream>
using namespace std;

int readExpr();
int readSum();
int readFak();
void overreadBlanks();

int main() {
	cout << "Bitte Term eingeben:" << endl;
	cout << readExpr() << endl;
	return 0;
}

int readExpr(){
	int lhs = readSum();
	if(true){
		overreadBlanks();
		while((cin.peek() == '+') || (cin.peek() == '-')){
			int rhs = readSum();
			if(true){
				lhs += rhs;
				overreadBlanks();
			}
		}
	}
	return lhs;
}

void overreadBlanks(){
	char c;
	while(cin.peek()==' ')
		cin.get(c);
}

int readSum(){
	int lhs = readFak();
	if(true){
		overreadBlanks();
		while((cin.peek() == '*') || (cin.peek() == '/')){
			char c;
			cin.get(c);
			int rhs = readFak();
			if(true){
				if(c=='*')
					lhs *= rhs;
				else
					lhs /= rhs;
				overreadBlanks();
			}
		}
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
		if((cin.peek() >= '0') && (cin.peek()<='9')){ //isdidgit
			cin >> result;
		} else {
			//Klammer
			cin.get(c);
			if(c == '('){
				result = readExpr();
				if(true){
					overreadBlanks();
					cin.get(c); //read )
				}
			}
		}
	}
	return result;
}

