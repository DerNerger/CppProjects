#ifndef Q
#define Q

#include <iostream>

using namespace std;

class Node{
  public:
    Node *next;
    int content;
    Node(int c) :next(nullptr), content(c) {};
    Node(int c, Node *n) : next(n), content(c) {}
    bool hasNext(){
      return next==nullptr;
    }
};

class MyQueue{
  private:
    Node *first;
    Node *last;
    int size;
  public:
    MyQueue(): first(nullptr), last(nullptr), size(0) {}
    MyQueue(initializer_list<int> arg): first(nullptr), last(nullptr), size(0) {
        for(auto & elem : arg){
          push_back(elem);
        }
    }
    ~MyQueue(){
      Node *current = first;
      while(current != nullptr){
        Node *toDelete = current;
        current = current->next;
        delete toDelete;
      }
    }

    void push_back(int elem);
    int pop_front();
    bool isEmpty() { return first==0; }
    int getSize() { return size; }

  friend ostream& operator<<(ostream & stream, const MyQueue & q){
    Node* current = q.first;
    stream << "[";
    while(current!=nullptr){
      stream << current->content;
      cout << " ";
      current=current->next;
    }
    stream << "]";
    return stream;
  }
};

#endif
