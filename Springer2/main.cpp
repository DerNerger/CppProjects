#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> myqueue;
	for(int i=0; i<10;i++)
		myqueue.push(i);
	while(myqueue.size()>0)
		cout << myqueue.pop();
}
