// Collections.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include <tchar.h>
#include "SLList.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	SLList<int> myList;
	cout << myList.getSize() << endl;
	cout << myList.isEmpty() << endl;

	myList.add(1);
	myList.add(2);
	myList.add(3);
	myList.add(4);
	

	SLList<int> myListCopy(&myList);
	myListCopy.add(15);

	cout << myList.toString() << endl;
	myList.clear();
	cout << myList.toString() << endl;

	getchar();
	return 0;
}

