#include <iostream>

using namespace std;

void print(int arr[], int length);

//primitive sort
void selectionSort(int arr[], int length);
void insertionSort(int arr[], int length);
void bubbleSort(int arr[], int length);
//higher sort
void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);

int main()
{
	int arr[]={6,8,4,3,0,2,9,7,1,5};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	//selectionSort(arr, sizeof(arr)/sizeof(arr[0]));	
	//insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
	//bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
	quickSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	print(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}

void print (int arr[], int length)
{
	for(int i=0; i<length; i++)
		cout << arr[i]<<" ";
	cout << endl;
}

//Element of O(n^2)
void selectionSort(int arr[], int length)
{
	for(int i=0; i<length-1; i++)
	{
		int minIndex = i;
		for(int j=i+1; j<length; j++)
		{
			if(arr[j]<arr[minIndex])
				minIndex=j;
		}
		int t = arr[i];
		arr[i]=arr[minIndex];
		arr[minIndex]=t;
	}
}

//Element of O(n^2)
void insertionSort(int arr[], int length)
{
	for(int i=1; i<length; i++)
	{
		int toIns=arr[i];
		int j;
		for(j=i; j>0; j--)
		{
			if(arr[j-1]<toIns) break;
			arr[j]=arr[j-1];
		}
		arr[j]=toIns;
	}
}

//Element of O(n^2)
void bubbleSort(int arr[], int length)
{
	for(int i=length; i>=0; i--)
	{
		for(int j=0; j<i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int t = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}	
	}
}


//Element of O(n*ld(n))
void quickSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int pivIndex = partition(arr, l, r);
		quickSort(arr,l, pivIndex-1);
		quickSort(arr, pivIndex+1, r);
	}
}

int partition(int arr[], int l, int r)
{
	int piv = arr[r];
	int pl = l;
	int pr = r;
	do {
		while(pl<pr && arr[pl]<=piv)
			pl++;
		while(pl<pr && arr[pr]>=piv)
			pr--;
		if(pl<pr)
		{
			int t = arr[pl];
			arr[pl]=arr[pr];
			arr[pr]=t;
		}
	} while(pl<pr);
	arr[r]=arr[pl];
	arr[pl]=piv;
	return pl;
}




