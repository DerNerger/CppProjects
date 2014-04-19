#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED
#include <string>

template <class T>
class SLList
{
public:
	SLList();
	SLList(SLList<T>* list);
	int getSize();
	bool isEmpty();
	void add(T elem);
	string toString();
	void clear();
	T getLast();
	T getFirst();
private:
	Node<T>* first;
	Node<T>* last;
	int size;
	void init();
};

#include "SLList.hpp"

#endif