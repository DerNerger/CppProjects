#ifndef q_iterator_t
#define q_iterator_t

#include "Node.h"

#include <iterator>

using namespace std;

template <class T>
class q_iterator : iterator<forward_iterator_tag, T>  {

  private:
    Node<T> *current;
  public:
    q_iterator(Node<T> *current) : current(current) {}
        
    bool operator==(q_iterator &other){ return current == other.current; }
    bool operator!=(q_iterator &other){ return current != other.current; }
    T& operator*(){ return current->content; }
    void operator++(){ current = current->next; }
};

#endif
