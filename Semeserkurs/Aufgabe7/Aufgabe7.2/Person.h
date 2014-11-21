#include <string>
using namespace std;

class Person{
   private:
     string Vorname; 
     string Nachname; 
   public:
     Person(string nn, string vn) : Vorname(vn), Nachname(nn){}
     string getVorname(){ return Vorname; }
     string getNachname() { return Nachname; }

     virtual string toString() = 0;
};

class Student : public Person{
  private:
    string Matrikelnummer;
  public:
    Student(string nn, string vn, string nr) : Matrikelnummer(nr), Person(nn, vn) {  }
    string getMatrikelnummer(){ return Matrikelnummer; }
    virtual string toString(){
       string temp;
      temp += "Student ";
       temp += Person::toString()+" ";
       temp += ", Matrickelnummer: "+Matrikelnummer;
       return temp;
    }
};

class Professor : public Person{
  private:
    string Lehrgebiet;
  public:
    Professor(string nn, string vn, string lg) : Person(nn, vn), Lehrgebiet(lg) {}
    string getLehrgebiet() {return Lehrgebiet; }
    virtual string toString(){
      string temp;
      temp += "Prof. ";
      temp += Person::toString()+" ";
      temp += ", Lehrgebiet: "+Lehrgebiet;
      return temp;
    }
};

string Person::toString(){
    string temp;
    temp+=Vorname;
    temp+=" ";
    temp+=Nachname;
    return temp;
}
