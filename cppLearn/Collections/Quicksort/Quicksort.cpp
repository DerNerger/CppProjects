// Quicksort.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Node.h"
#include "Stack.h"
#include <iostream>

using namespace std;

int Partition(int l, int r, int feld[])
{
	if (l < r)
	{
		int pivot = feld[r];
		int lh = l;
		int rh = r;
		do
		{
			while ((lh < rh) && (feld[lh] <= pivot))
				lh++;
			while ((lh < rh) && (feld[rh] >= pivot))
				rh--;
			if (lh < rh)
			{
				int t = feld[lh];
				feld[lh] = feld[rh];
				feld[rh] = t;
			}
		} while (lh<rh);
		feld[r] = feld[lh];
		feld[rh] = pivot;
		return lh;
	}
	else
		return r;
}

void showFeld(int feld[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << feld[i] << " ";
	}
	cout << endl;
}

void Quicksort(int feld[], int feldSize)
{
	Stack<int> pivotStack;
	int left;
	pivotStack.push(feldSize);
	pivotStack.push(-1);

	while (pivotStack.getSize()>1)
	{
		left = pivotStack.pop()+1;
		while (pivotStack.getTop() > left)
		{
			int newPivot = Partition(left, pivotStack.getTop()-1, feld);
			pivotStack.push(newPivot);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int feld[12];
	feld[0] = 14;
	feld[1] = 23;
	feld[2] = 7;
	feld[3] = 12;
	feld[4] = 49;
	feld[5] = 47;
	feld[6] = 30;
	feld[7] = 27;
	feld[8] = 4;
	feld[9] = 11;
	feld[10] = 19;
	feld[11] = 39;

	showFeld(feld, sizeof(feld) / sizeof(feld[0]));
	Quicksort(feld, sizeof(feld) / sizeof(feld[0]));
	showFeld(feld, sizeof(feld) / sizeof(feld[0]));

	getchar();

	return 0;
}

