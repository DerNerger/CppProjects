#include <iostream>


int main(void){
    
    //Moeglichkeit 1
    std::cout << "hallo" << std::endl; //ohne using

    //Moeglichkeit 2
    using namespace std;
     cout << "hallo" << endl; //mit using*/

    //Moeglichkeit 3
    using  std::cout;
    using std::endl;
    cout << "hallo" << endl;

}
