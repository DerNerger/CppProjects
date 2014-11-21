#include <iostream>
#include "Person.h"
#include <vector>
#include <typeinfo>

int main(){
  vector<Person * > diePersonen;
  diePersonen.push_back(new Student ("Risse", "Felicitas" , "635374"));
  diePersonen.push_back( new Professor("Philippsen", "Nele", "Datenbanken"));
  diePersonen.push_back( new Student ("Spillner", "Julian", "123429"));

  Student s("","",""); //dummy-string
  if(typeid(s) == typeid(*diePersonen[0]))
    cout << dynamic_cast<Student*>(diePersonen[0])->getMatrikelnummer() << endl;
}
