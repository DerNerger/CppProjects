#include "Teilnehmer.h"
#include <algorithm>

void Teilnehmer::lerntKennen(Teilnehmer &a){
    if( &a == this) return;
    if(std::find(v.begin(), v.end(), a.name) != v.end()) //v contains a.name => kennen sich schon
      return;
    else{
      v.push_back(a.name);
      a.lerntKennen(*this);
    }
}

const string& Teilnehmer::gibNamen() const{
    return name;
}

void Teilnehmer::druckeBekannte() {
    for(vector<string>::iterator it = v.begin(); it<v.end(); it++)
        cout << *it << " ";
}
