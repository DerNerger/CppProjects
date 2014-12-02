// NOCH NICHT VOLLSTÄNDIG (s. Übungsaufgaben)
#ifndef DATUM_H
#define DATUM_H
#include<string>
#include <iostream>
#include "UngueltigesDatumException.h"

using namespace std;

class Datum {
  public:
    Datum();                         // Default-Konstruktor
    Datum(int t, int m, int j = 1997); // allgemeiner Konstruktor
    Datum(const Datum &d) : tag_(d.tag_), monat_(d.monat_), jahr_(d.jahr_) {}
    void set(int t, int m, int j)throw(UngueltigesDatumException); // Datum setzen
    void aktuell();                  // Systemdatum setzen
    bool istSchaltjahr() const;
    Datum& operator++();             // Tag hochzählen, präfix
    Datum operator++(int);           // Tag hochzählen, postfix
    int tag()   const;
    int monat() const;
    int jahr()  const;

    // besser: durch Methode string toString() ersetzen!
    // (siehe Übungsaufgabe)
    operator std::string() const;         // Typumwandlungsoperator



#endif  


  private:
     int tag_, monat_, jahr_;
};

bool istSchaltjahr(int jahr); // Impl. s.u.

// inline-Methoden
inline Datum::Datum(int t, int m, int j) { set(t, m, j);}

inline int Datum::tag()   const { return tag_;  }
inline int Datum::monat() const { return monat_;}
inline int Datum::jahr()  const { return jahr_; }
inline bool Datum::istSchaltjahr() const {
  return ::istSchaltjahr(jahr_); 
}
 
// global
bool istGueltigesDatum(int t, int m, int j);

inline bool istSchaltjahr(int jahr)  {
   return  (jahr % 4 == 0 && jahr % 100) || jahr % 400 == 0;
}

ostream& operator<<(ostream& l, const Datum& r){
  l << r.tag() << "." << r.monat() << "." << r.jahr();
  return l;
}

bool operator==(const Datum& l, const Datum& r){
  return (l.tag()==r.tag()) && (l.monat()==r.monat()) && (l.jahr()==r.jahr());
}

bool operator!=(const Datum& l, const Datum& r){
  return !(l==r);
}


bool operator<(const Datum& l, const Datum& r){
  if(l.jahr() < r.jahr()) return true;
  if(l.jahr() > r.jahr()) return false;
  if(l.monat() < r.monat()) return true;
  if(l.monat() > r.monat()) return false;
  return l.tag() < r.tag();
}


bool operator>(const Datum& l, const Datum& r){
  return (l!=r) && !(l < r);
}


bool operator<=(const Datum& l, const Datum& r){
  return (l==r) || (l<r);
}


bool operator>=(const Datum& l, const Datum& r){
  return (l > r) || (l==r);
}

int DatumDifferenz(const Datum& a, const Datum& b){
  Datum* lesser;
  const Datum* bigger;
  if( a < b){
    lesser = new Datum(a); //copy
    bigger = &b;
  } else {
    lesser = new Datum(b); //copy
    bigger = &a;
  }

  int diff = 0;
  while(*lesser < *bigger){
    diff++;
    (*lesser)++;
  }

  delete lesser;
  return diff;
}
