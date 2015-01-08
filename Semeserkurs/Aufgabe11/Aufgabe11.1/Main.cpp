#include "Q.h"

int main(){
  //init
  MyQueue q;
  //add
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);
  //print
  cout << q << endl;
  cout << "Size=" << q.getSize() << endl;
  //remove
  cout << "pop:" << q.pop_front() << endl;
  cout << "pop:" << q.pop_front() << endl;
  cout << "pop:" << q.pop_front() << endl;
  cout << q << endl;
  cout << "pop:" << q.pop_front() << endl;
  //try to remove from empty q
  try{
     cout << "pop:" << q.pop_front() << endl;
  }catch (const char * exc){
    cout << exc << endl;
  }
  //print again
  cout << q << endl;
  cout << "Size=" << q.getSize() << endl;

  //init it with initializer-list
  MyQueue q2 = {5,4,3,2,1,0};
  cout << q2 << endl;
}
