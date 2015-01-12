#ifndef Node_t
#define Node_t

template <class T>
class Node {

  public:
    Node *next;
    T content;

    Node(T c) :next(nullptr), content(c) {}
    Node(T c, Node *n) : next(n), content(c) {}

    ~Node(){
        if(next != nullptr) delete next;
    }

    bool hasNext(){
      return next!=nullptr;
    }
};
#endif
