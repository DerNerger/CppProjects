// Collections.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "Foo.h"

using namespace std;

/*
template <class T>
class Node
{
public:
	T content;
};
*/

int _tmain(int argc, _TCHAR* argv[])
{
	//http://www.parashift.com/c++-faq-lite/templates-defn-vs-decl.html
	Foo<int> f;
	f.someMethod(4);
	getchar();
	return 0;
}

