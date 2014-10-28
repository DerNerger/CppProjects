#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    //schreiben in datei
    ofstream ofs;
    ofs.open("output.txt");
    if(ofs){
        string line;
        for(int i = 0; i < 4; i++){
            ofs << "Zeile " << i << endl;
        }
    }
    else {
        cout << "Datei konnte nicht gelesen werden" << endl;
    }
}
