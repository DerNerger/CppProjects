#include "datum.h"
#include <ctime>

Datum::Datum()  { aktuell();}

void Datum::set(int t, int m, int j)throw(UngueltigesDatumException) {
   if(!istGueltigesDatum(t, m, j)) 
       throw UngueltigesDatumException();
    tag_ = t;
    monat_ = m;
    jahr_ = j;
}

void Datum::aktuell() {   // Systemdatum eintragen
    time_t now = time(NULL);
    tm *z = localtime(&now);           // Zeiger auf struct tm
    jahr_  = z->tm_year + 1900;
    monat_ = z->tm_mon+1;               // localtime liefert 0..11
    tag_   = z->tm_mday;
}

Datum& Datum::operator++() {     // Datum um 1 Tag erhöhen
   ++tag_;
   // Monatsende erreicht?
   if(!istGueltigesDatum(tag_, monat_, jahr_)) {
     tag_ = 1;
     if (++monat_ > 12) {
        monat_ = 1;
        ++jahr_;
     }
   }
   return *this;
}

Datum Datum::operator++(int) {        // Datum um 1 Tag erhöhen
   Datum temp = *this;
   ++*this;                           // Präfix ++ aufrufen
   return temp;
}

// besser: durch Methode string toString() ersetzen!
Datum::operator std::string() const {
    std::string temp("tt.mm.jjjj");
              // implizite Umwandlung in char
    temp[0] = tag_/10 +'0';
    temp[1] = tag_%10 +'0';
    temp[3] = monat_/10 +'0';
    temp[4] = monat_%10 +'0';
    int pos = 9;                 // letzte Jahresziffer
    int j = jahr_;
    while(j > 0) {
       temp[pos] = j % 10 + '0';  // letzte Ziffer
       j = j/10;                  // letzte Ziffer abtrennen
       --pos;
    }
    return temp;
}

// globale Funktion
bool istGueltigesDatum(int t, int m, int j) {
     // Tage pro Monat(static vermeidet Neuinitialisierung):
     static int tmp[]={31,28,31,30,31,30,31,31,30,31,30,31};

     tmp[1] = istSchaltjahr(j) ? 29 : 28;

     return     m >= 1    && m <= 12
            && j  >= 1583 && j  <= 2399  // oder mehr
            && t  >= 1    && t   <= tmp[m-1];
}


int main(){
  //Aufgabe 8.6
  Datum d(2,12,2014);
  cout << "d="<< d << endl;

  Datum d2(24,12,2014);
  cout << "d2="<< d2 << endl;

  Datum d3(24,12,2014);
  cout << "d3="<< d3 << endl;

  //Aufgabe 8.7
  bool eq = d == d2;
  cout << "d==d2 :" << boolalpha <<eq << endl; 
  eq = d2 == d3;
  cout << "d2==d3 :"  <<eq << endl; 

  bool ne = d != d2;
  cout << "d!=d2 :" << boolalpha <<ne << endl; 
  ne = d2 != d3;
  cout << "d2!=d3 :"  <<ne << endl; 

  bool lt = d < d2;
  cout << d << " < " << d2 << " = " << lt << endl;
  lt = d2 < d3;
  cout << d2 << " < " << d3 << " = " << lt << endl;
  lt = d < d3;
  cout << d << " < " << d3 << " = " << lt << endl;

  //Aufgabe 8.8
  int diff = DatumDifferenz(d,d2);
  cout << "|d-d2|=" << diff << endl;

  diff = DatumDifferenz(d3,d2);
  cout << "|d3-d2|=" << diff << endl;

  //Aufgabe 8.9
  try{
    d.set(0,-12,500);
  } catch (UngueltigesDatumException& r){
    cout << r.what() << endl;
  }
}
