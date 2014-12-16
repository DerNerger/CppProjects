#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex log;
mutex mut;
condition_variable cv;

void func(int number){
  log.lock();
  cout << "Thread" << number << " is starting" << endl;
  log.unlock();
}

int main(){

}
