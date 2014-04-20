#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node
{
public:
	Node(T pContent);
	T getContent();
	Node<T>* getNext();
	void setContent(T pContent);
	void setNext(Node<T>* pNextNode);
private:
	T content;
	Node<T>* nextNode;
};

#include "Node.hpp"

#endif