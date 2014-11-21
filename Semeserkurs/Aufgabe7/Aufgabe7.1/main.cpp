#include <iostream>
#include "Person.h"
#include <vector>


int main(){
  vector<Person * > diePersonen;
  diePersonen.push_back(new Student ("Risse", "Felicitas" , "635374"));
  diePersonen.push_back( new Professor("Philippsen", "Nele", "Datenbanken"));
  diePersonen.push_back( new Student ("Spillner", "Julian", "123429"));
  for(size_t i = 0; i < diePersonen.size(); ++i) {
    cout << diePersonen[i]->getVorname() << endl;
  }
  for(size_t i = 0; i < diePersonen.size(); ++i) {
    cout << diePersonen[i]->toString() << endl;
  }
}
