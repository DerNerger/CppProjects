#include "Node.h" 
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node(T pContent)
{
	content = pContent;
	nextNode = nullptr;
}

template <class T>
T Node<T>::getContent()
{
	return content;
}

template <class T>
void Node<T>::setContent(T pContent)
{
	content = pContent;
}

template <class T>
void Node<T>::setNext(Node<T>* pNextNode)
{
	nextNode = pNextNode;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return nextNode;
}