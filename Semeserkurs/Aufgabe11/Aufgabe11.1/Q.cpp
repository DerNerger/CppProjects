#include "Q.h"

void MyQueue::push_back(int elem){
  if(isEmpty()){
    first = new Node(elem);
    last = first;
  } else {
    Node *newNode = new Node(elem);
    last->next = newNode;
    last = newNode;
  }
  size++;
}

int MyQueue::pop_front(){
  if(isEmpty()) throw "Queue is empty";
  int toReturn = first->content;
  Node *toDelete = first;
  first = first->next;
  if(isEmpty()) last = nullptr;
  size--;
  delete toDelete;
  return toReturn;
}
