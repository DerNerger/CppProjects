#include <iostream>
using namespace std;

#include "Tree.h"
#include "Taschenrechner.h"
#include <string>

int main(){


  string anfrage;
  cout << "Bitte einen Term eingeben:" << endl;
  getline(cin, anfrage);
  Taschenrechner tr(anfrage);
  Tree* t = tr.getTree();
  cout << "Ergebnis:" << endl;
  cout << t->eval() << endl;
  cout << "Infix-Darstellung:" << endl;
  cout << *t << endl;
  cout << "Baum:" << endl;
  VisualTree tree = t->visual();
  cout << tree << endl;
}

//((20-(50/5))+(2*3))
//20-50/5+2*3

