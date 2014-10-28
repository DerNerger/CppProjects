#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    //lesen aus datei
    ifstream ifs;
    ifs.open("output.txt");
    if(ifs){
        string line;
        while(!ifs.eof()){
            ifs >> line;
            cout << line << endl;
        }
    }
    else {
        cout << "Datei konnte nicht gelesen werden" << endl;
    }
}
