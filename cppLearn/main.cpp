#include <iostream>

using namespace std;

int main()
{
	const size_t SIZE=10;
	int test[SIZE];
	for(int i=0; i<sizeof(test)/sizeof(test[0]);i++)
		test[i]=2*i;
	
	int *pBla = &test[0];
	for(int i=0; i<SIZE; i++)
	{
		cout << *pBla++ << endl;
	}
	return 0;
}
