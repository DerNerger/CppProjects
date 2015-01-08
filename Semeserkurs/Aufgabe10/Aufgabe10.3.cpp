#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mut;
condition_variable cv;
bool go[3];

void func(int number){
  unique_lock<mutex> ul(mut);
  while(!go[number-1])cv.wait(ul);
  cout << "Thread " << number << " gestartet" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  if(number<3) go[number] = true;
  cv.notify_one();
}

int main(){
  thread t(func, 1);
  this_thread::sleep_for(chrono::seconds(1));
  go[0] = true;
  cv.notify_one();
  thread t2(func, 2);
  thread t3(func, 3);
  t.join();
  t2.join();
  t3.join();
  cout << "Programm wurde beendet" << endl;
}
