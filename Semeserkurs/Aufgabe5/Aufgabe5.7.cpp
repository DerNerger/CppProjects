#include <iostream>

using namespace std;


template<typename TYP>
void ausgabe3D(TYP tabelle, size_t n) {
    const size_t SPALTEN = sizeof tabelle[0] /sizeof tabelle[0][0];
    const size_t TIEFE  = sizeof tabelle[0][0] /sizeof tabelle[0][0][0];
    for(size_t i = 0; i < n;++i) {
        for(size_t j = 0; j < SPALTEN;++j) {
            cout << "(";
            for(size_t k = 0; k < TIEFE; ++k)
                cout << tabelle[i][j][k] << ' ';
            cout << ") ";
        }
        cout << endl;
    }
}

int main() {
    int matrix1[2][3][2] = {{{111,112},{121,122},{131, 132}},
                            {{211,212},{221,222},{231, 232}}};
        ausgabe3D(matrix1, 2); // Erste Dimension muss immer angegeben werden!!
}
