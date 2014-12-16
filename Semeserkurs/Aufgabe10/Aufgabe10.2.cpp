#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex mut;
int result;
mutex log;

void func(int start, int end){
  log.lock();
  cout <<"startet thread from " << start << " to " << end << endl;
  log.unlock();
  int sum = 0;
  for(int i = start; i <= end; i++)
    sum += i;

  mut.lock();
  result += sum;
  mut.unlock();
}

int main(){
  int n;
  int threads;
  cout << "Bitte n eingeben:" ;
  cin >> n;
  cout << "Anzahl threads eingeben:";
  cin >> threads;
  int intervallaenge = n / threads;
  int restForLastThread = n % threads;

  vector<thread> v(threads);
  for(int i = 0; i < threads; i++){
    if(i!= threads-1)
      v[i] = thread (func, i*intervallaenge, (i+1)*intervallaenge-1);
    else //last thread
      v[i] = thread (func, i*intervallaenge, (i+1)*intervallaenge + restForLastThread);
  }

  for(int i = 0; i < v.size(); i++){
    v[i].join();
  }

  cout << "Ergebnis mit Threads = " << result << endl;
  cout << "Ergebnis mit Formel  = " << (n*n + n)/2 << endl;
}
