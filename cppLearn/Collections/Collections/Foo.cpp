#include "stdafx.h"
#include "Foo.h"
#include <iostream>

using namespace std;

template<typename T>
Foo<T>::Foo()
{
	cout << "Datei wurde erstellt" << endl;
}

template<typename T>
void Foo<T>::someMethod(T x)
{
	cout << "running Method T" << endl;
}