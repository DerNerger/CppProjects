// Klasse für rationale Zahlen
//////////////////////////////

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Rational {
   public:
     Rational();
     Rational(long z, long n);   // allgemeiner Konstruktor
     //Rational(long);             // Typumwandlungskonstruktor

     // Abfragen
     long getZaehler() const;
     long getNenner()  const;

     // arithmetische Methoden
     // (werden später durch überladene Operatoren ergänzt)
     void add(const Rational& r);
     void sub(const Rational& r);
     void mult(const Rational& r);
     void div(const Rational& r);

     // weitere Methoden
     void set(long zaehler, long nenner);
     void eingabe();
     void ausgabe() const;
     void kehrwert();
     void kuerzen();

 Rational& operator+=(Rational const& Rational);
 Rational& operator-=(Rational const& Rational);
 Rational& operator/=(Rational const& Rational);
 Rational& operator*=(Rational const& Rational);

   private:
     long zaehler, nenner;

  friend bool operator==(Rational& lhs, Rational& rhs){
    return (lhs.zaehler==rhs.zaehler) && (lhs.nenner==rhs.nenner);
  }

  //sollten Rational zurueckgeben, damit a+b+c+d+.... moeglich ist
  friend Rational operator+(const Rational& lhs, const Rational& rhs){
    Rational a = lhs;
    a += rhs;
    return a;
  }
  friend Rational operator-(const Rational& lhs, const Rational& rhs){
    Rational a = lhs;
    a -= rhs;
    return a;
  }
  friend Rational operator*(const Rational& lhs, const Rational& rhs){
    Rational a = lhs;
    a *= rhs;
    return a;
  }
  friend Rational operator/(const Rational& lhs, const Rational& rhs){
    Rational a = lhs;
    a /= rhs;
    return a;
  }

  friend std::istream& operator>>(std::istream& is, Rational& rhs){
    long a;
    long b;
    char c;
    is >> a;
    is >> c;
    is >> b;
    rhs.set(a,b);
    return is;
  }
 
};

// inline Methoden
inline Rational::Rational()               : zaehler(0), nenner(1) {}
inline Rational::Rational(long z, long n) : zaehler(z), nenner(n) {}
//inline Rational::Rational(long ganzeZahl) : zaehler(ganzeZahl), nenner(1) {}

inline long Rational::getZaehler() const {return zaehler;}
inline long Rational::getNenner()  const {return nenner;}

// globale Funktionen
const Rational add(const Rational& a, const Rational& b);
const Rational add(const Rational& a, long b);
const Rational add(long a, const Rational& b);
const Rational sub(const Rational& a, const Rational& b);
const Rational mult(const Rational& a, const Rational& b);
const Rational div(const Rational& z, const Rational& n);
void print(const Rational& r);


#endif
