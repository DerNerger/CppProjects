#ifndef Q
#define Q

#include <iostream>
using namespace std;

#include "q_iterator.h"

template<class T>
class MyQueue{
  private:
    Node<T> *first;
    Node<T> *last;
    int size;
  public:
    MyQueue(): first(nullptr), last(nullptr), size(0) { cout << "CTOR" << endl;}
    MyQueue(initializer_list<T> arg): first(nullptr), last(nullptr), size(0) {
        for(auto & elem : arg){
          push_back(elem);
        }
        cout << "CTOR" << endl;
    }

    ~MyQueue(){
      delete first;
      cout << "DTOR"<< endl;
    }

    MyQueue(MyQueue && mv){
      first = mv.first;
      last = mv.last;
      mv.first = nullptr;
      mv.last = nullptr;
      cout << "MOVE CTOR"<< endl;
    }

    MyQueue<T>& operator=(MyQueue<T> && mv){
      if(this==&mv) return *this;
      first = mv.first;
      last = mv.last;
      mv.first = nullptr;
      mv.last = nullptr;
      cout << "MOVE ASSIGN" << endl;
    }

    bool isEmpty() { return first==nullptr; }
    int getSize() { return size; }

  friend ostream& operator<<(ostream & stream, const MyQueue & q){
    Node<T>* current = q.first;
    stream << "[";
    while(current!=nullptr){
      stream << current->content;
      cout << " ";
      current=current->next;
    }
    stream << "]";
    return stream;
  }

  q_iterator<T> begin() { return q_iterator<T>(first);}
  q_iterator<T> end() { return q_iterator<T>(nullptr);}

  void push_back(T elem){
    if(isEmpty()){
      first = new Node<T>(elem);
      last = first;
    } else {
      Node<T> *newNode = new Node<T>(elem);
      last->next = newNode;
      last = newNode;
    }
    size++;
  }

  T pop_front(){
    if(isEmpty()) throw "Queue is empty";
    T toReturn = first->content;
    Node<T> *toDelete = first;
    first = first->next;
    if(isEmpty()) last = nullptr;
    size--;
    delete toDelete;
    return toReturn;
  }
};

#endif
