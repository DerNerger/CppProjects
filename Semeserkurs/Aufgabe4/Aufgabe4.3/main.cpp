#include <iostream>

#include "IntMenge.h"

using namespace std;

int main(){
   IntMenge m; 
   m.add(2);
   m.add(1);
   m.add(5);
   m.add(5);
   m.add(9);
   m.print();

   cout.setf(ios_base::boolalpha);
   cout << "2 in vec: " << m.contains(2) << endl;
   cout << "42 in vec: " << m.contains(42) << endl;

   cout << "min= " << m.getMin() << endl;
   cout << "max= " << m.getMax() << endl;
 
   cout << "size= " << m.size() << endl;

   cout << "clear" << endl;
   m.clear();
   m.print();
   cout << "size= " << m.size() << endl;

   for(int i = 1; i< 10; i++)
       m.add(i);

   m.print();
   cout << "remove 2 and 20" << endl;
   m.remove(2);
   m.remove(20);
   m.print();

   cout << "min= " << m.getMin() << endl;
   cout << "max= " << m.getMax() << endl;
   cout << "size= " << m.size() << endl;

   cout << "Copy" << endl;
   IntMenge m2 = m;
   cout << "fuege 42 zur erstem Menge hinzu" << endl;
   m.add(42);
   cout << "fuege 43 zur zweiten Menge hinzu" << endl;
   m2.add(43);
   cout << "erste Menge: ";
   m.print();
   cout << "zweite Menge: ";
   m2.print();

   cout << "leere Menge 1" << endl;
   m.clear();
   cout << "Suche Minimum in Menge 1" << endl;
   try{
      m.getMin();
   } catch (const char *  e){
       cout << e << endl;
   }
}
