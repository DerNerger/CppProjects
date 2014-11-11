#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool isName(string &str){
    if(!isalpha(str[0]))
        return false;
    for (std::string::iterator it=str.begin()+1; it!=str.end(); ++it){
        if( (!isalnum(*it)) && (*it!='_') )
            return false;
    }
    return true;
}

int main(){
    cout << "Dateiname= " ;
    char * name = new char[20];
    cin.getline(name, 20);
    
    ifstream ifs(name);
    if(ifs){
        cout << "Datei enthaelt die folgenden Namen:" << endl;
        while(!ifs.eof()){
            string nextWord;
            ifs >> nextWord;
            if(isName(nextWord))
                cout << nextWord << endl;
        }
    } else {
        cout << "Datei wurde nicht gefunden" << endl;
    }
}
