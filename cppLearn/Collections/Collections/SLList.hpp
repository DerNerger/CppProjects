#include "SLList.h"
#include "Node.h"
#include <string>
#include <sstream>

using namespace std;

template <class T>
SLList<T>::SLList()
{
	init();
}

template <class T>
SLList<T>::SLList(SLList<T>* list)
{
	init();
	Node<T>* current = list->first;
	while (size < list->size)
	{
		add(current->getContent());
		current = current->getNext();
	}
}



template <class T>
int SLList<T>::getSize()
{
	return size;
}

template<class T>
bool SLList<T>::isEmpty()
{
	return size == 0;
}

template<class T>
void SLList<T>::add(T elem)
{
	if (isEmpty())
	{
		first = new Node<T>(elem);
		last = first;
	}
	else
	{
		last->setNext(new Node<T>(elem));
		last = last->getNext();
	}
	size++;
}

template<class T>
void SLList<T>::init()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

template<class T>
string SLList<T>::toString()
{
	string s;
	Node<T>* current=first;
	for (int i = 0; i < size; i++)
	{
		ostringstream oss;
		oss << current->getContent();
		if (i != size - 1)
			oss << ", ";
		s.append(string(oss.str()));
		current = current->getNext();
	}
	return s;
}

template<class T>
T SLList<T>::getLast()
{
	return last->getContent();
}

template<class T>
T SLList<T>::getFirst()
{
	return first->getContent();
}

template<class T>
void SLList<T>::clear()
{
	//TODO implementation is crap!!!
	delete first;
	fitst = nullptr;
	last = nullptr;
	size = 0;
}

