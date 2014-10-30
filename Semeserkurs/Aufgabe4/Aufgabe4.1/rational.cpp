// Klasse für rationale Zahlen
// (Definition der Methoden)
//////////////////////////////
#include"rational.h"
#include<iostream>
#include<cassert>
using namespace std;

// Elementfunktionen
 
void Rational::add(const Rational& r) {
     zaehler = zaehler*r.nenner + r.zaehler*nenner;
     nenner  = nenner*r.nenner;
     kuerzen();
}

 
void Rational::sub(const Rational& s) {
     Rational r = s;
     r.zaehler *=-1;
     add(r);
}
 
void Rational::mult(const Rational& r) {
     zaehler = zaehler*r.zaehler;
     nenner  = nenner *r.nenner;
     kuerzen();
}

void Rational::div(const Rational& n) {
     Rational r = n;
     r.kehrwert();
     mult(r);
}

void Rational::set(long z, long n) {
     zaehler = z;
     nenner  = n;
     assert(nenner != 0);
     kuerzen();
}

void Rational::eingabe() {
     cout << "Zähler :";
     cin >> zaehler;
     cout << "Nenner :";
     cin >> nenner;
     assert(nenner != 0);
     kuerzen();
}
 
void Rational::ausgabe() const {
     cout << zaehler << "/" << nenner << endl;
}

void Rational::kehrwert() {
     long temp = zaehler;
     zaehler = nenner;
     nenner  = temp;
     assert(nenner != 0);
}

long ggt(long x, long y) {
    long rest;
    while (y > 0) {
       rest = x % y;
       x = y; 
       y = rest;
    }
    return x;
}

void Rational::kuerzen() {
     int sign = 1;
     if (zaehler < 0) { sign=-sign; zaehler = -zaehler;}
     if (nenner  < 0) { sign=-sign; nenner  = -nenner;}
     long teiler = ggt(zaehler, nenner);
     zaehler = sign*zaehler/teiler;
     nenner = nenner/teiler;
}


// globale Funktionen
//####################################################
//#               Aufgabe 2.1                        #
//####################################################
const Rational add(const Rational& a, const Rational& b) {
   Rational r = a;
   r.add(b);
   return r;
}

const Rational add(const Rational& a, long b) {
    Rational r = a;
    Rational r2(b,1);
    r.add(r2);
    return r;
}

const Rational add(long a, const Rational& b) {
    return add(b,a);
}
 
const Rational sub(const Rational& a, const Rational& b) {
   Rational r = a;
   r.sub(b);
   return r;
}
 
const Rational mult(const Rational& a, const Rational& b) {
   Rational r = a;
   r.mult(b);
   return r;
}

const Rational div(const Rational& z, const Rational& n) {
   Rational r = z;
   r.div(n);
   return r;
}
//####################################################
//#               Aufgabe 2.2                        #
//####################################################
void print(const Rational& r){
    cout << "Variante 1: " << endl;
    r.ausgabe();

    cout << "Variante 2: " << endl;
    cout << r.getZaehler() << "/" << r.getNenner() << endl;
}
