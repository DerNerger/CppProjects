#include <iostream>

using namespace std;


void removeBlanks(char *str){
    char * i = str;
    while(*str){
        if(*str!=' ')
            *(i++)=*str;
        str++;
    }
    *i='\0';
}

int main(){
    char * str = new char[30];

    cout <<"Bitte eine Zeichenkette von maximal 30 Zeichen eingeben" << endl;
    cin.getline(str, 30);
    cout << "Eingabe=" << str << endl;
    removeBlanks(str);
    cout << "Ausgabe=" << str << endl;
}
