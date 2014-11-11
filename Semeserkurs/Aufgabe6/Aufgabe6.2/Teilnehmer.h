#include <vector>
#include <iostream>

using namespace std;

class Teilnehmer{
  private:
    const string name;
    //vector<Teilnemer *> v; Problem ist hier=> wenn speicher freigegeben wird, so wird der poiner ungueltig
    vector<string> v; //besser => nur die namen per value speichern
  public:
    Teilnehmer(const string& pName) : name(pName), v(0) {}
    void lerntKennen(Teilnehmer &a);
    const string& gibNamen() const;
    void druckeBekannte() ;
};
