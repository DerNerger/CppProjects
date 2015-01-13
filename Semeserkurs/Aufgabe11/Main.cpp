#include <iostream>
using namespace std;

#include "Q.h"

int main(){
  //init
  MyQueue<int> q;

  //add
  cout << endl;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);

  //print
  cout << endl;
  cout << q << endl;
  cout << "Size=" << q.getSize() << endl;

  //remove
  cout << endl;
  cout << "pop:" << q.pop_front() << endl;
  cout << "pop:" << q.pop_front() << endl;
  cout << "pop:" << q.pop_front() << endl;
  cout << q << endl;
  cout << "pop:" << q.pop_front() << endl;

  //try to remove from empty q
  cout << endl;
  try{
     cout << "pop:" << q.pop_front() << endl;
  }catch (const char * exc){
    cout << exc << endl;
  }

  //print again
  cout << endl;
  cout << q << endl;
  cout << "Size=" << q.getSize() << endl;

  //init it with initializer-list
  cout << endl;
  MyQueue<int> q2 = {5,4,3,2,1,0};
  cout << q2 << endl;

  //iterate
  cout << endl;
  cout << "ueber q iterieren..." << endl;
  for(int elem : q2)
    cout << elem << " ";
  cout << endl;

  //template test
  cout << endl;
  cout << "string q : q4" << endl;
  MyQueue<string> q4 = {"first", "second", "third"};
  cout << q4 << endl;

  //move-semantik
  cout << endl;
  cout << "move q2 to q" << endl;
  q = move(q2);
  cout << "q:" << q << endl;
  
  cout << "move q to q3" << endl;
  MyQueue<int> q3(move(q));
  cout << "q3:" << q3 << endl;

  
}
