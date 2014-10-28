#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
    char fileName[31];
    cout << "Dateiname: ";
    cin.getline(fileName, 30);
    ifstream ifs;
    ifs.open(fileName);
    
    if(ifs){
        vector<char> v(16);
        unsigned char byte;
        while(!ifs.eof())
        {
            int i;
            for(i = 0; i < 16 && !ifs.eof(); i++)
            {
                ifs >> noskipws >> byte;
                v[i] = byte;
                cout.width(2);
                cout.fill('0');
                cout << uppercase << hex << int(byte) << " ";
            }
            for(int j = i; j<16; j++)
                cout << "   ";
  
            cout << "   ";
            for(int j = 0; j < i; j++)
            {
                char c = v.at(j);
                if(!isgraph(c))
                    cout << '.';
                else
                    cout << c;
            }
            cout << endl;
        }
        ifs.close();
    }
    else {
        cout << "Fehler beim Lesen der Datei." << endl;
    }
}
