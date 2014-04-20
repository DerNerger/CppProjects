#include "Stack.h" 


template <class T>
Stack<T>::Stack()
{
	top = nullptr;
	size = 0;
}

template <class T>
T Stack<T>::pop()
{
	T back = top->getContent();
	top = top->getNext();
	size--;
	return back;
}

template <class T>
T Stack<T>::getTop()
{
	return top->getContent();
}

template <class T>
void Stack<T>::push(T elem)
{
	Node<T>* nextTop = new Node<T>(elem);
	nextTop->setNext(top);
	top = nextTop;
	size++;
}

template <class T>
int Stack<T>::getSize()
{
	return size;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return size==0;
}