#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char **args){
    for(int i=0; i<argc; i++){
        cout << "Argument " << i << " = " << args[i] << endl;
        if(i==0)
            continue;
         
        fstream inf( args[i]);
        if(inf){
            cout << "Datei "<< args[i] << " wird ausgegeben" << endl;
            while(!inf.eof()){
                char * line = new char[1000];
                inf.getline(line, 1000);
                cout << line << endl;
            }
        } else {
            cout << "Es existiert keine Datei mit dem Namen "<< args[i] << endl;
        }
    }
}
