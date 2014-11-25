#include <exception>
//#include <stdexcept>
#include <iostream>

using namespace std;


void blaa() throw(exception) {
   throw exception(); 
}

int main(){
    blaa();
}
