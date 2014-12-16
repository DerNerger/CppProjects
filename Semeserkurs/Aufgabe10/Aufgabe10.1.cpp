#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex mut;

void func(int waitTime, int threadNumber){
  mut.lock();
  cout << "Thread number " << threadNumber << "starts" << endl;
  mut.unlock();
  this_thread::sleep_for(chrono::seconds(waitTime));
  mut.lock();
  cout << "Thread number " << threadNumber << "ends" << endl;
  mut.unlock();
}

int main(){
  thread t1(func, 1, 1);
  thread t2(func, 2, 2);
  thread t3(func, 3, 3);
  t1.join();
  t2.join();
  t3.join();
}
