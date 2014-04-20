#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class Stack
{
public:
	Stack();
	T pop();
	void push(T elem);
	T getTop();
	int getSize();
	bool isEmpty();
private:
	Node<T>* top;
	int size;
};

#include "Stack.hpp"

#endif