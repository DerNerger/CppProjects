#include <iostream>
#include <assert.h>

using namespace std;

int main(){
    //Speicherplatz = sizeof(int) * dim1 * dim2 = 4 * 2 * 3 = 24
    int matrix[2][3];
    cout << "sizeof(matrix)=" <<sizeof(matrix) << endl;

    //Bytenummer = i * sizeof(int) * dim2 + j * sizeof(int)
    //           = i *     4       *  3   + j *   4
    //           = 12i + 4j 
    int *first = &matrix[0][0];
    int i;
    int j;

    cout << "Eingabe der Zeile(i) und Spalte(j) von welcher die Bytenummer berechnet werden soll" << endl;
    cout << "i= ";
    cin >> i;
    cout << "j= ";
    cin >> j;

    assert(i >= 0 && i <2);
    assert(j >= 0 && j <3);
    int bytenumber = (&matrix[i][j] - first)*sizeof(int);
    cout << "Bytenummer=" << bytenumber << endl;
}
