// Collections.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include <tchar.h>
#include "SLList.h"
#include <time.h>

#define DIM 8

using namespace std;

SLList<string> list;

void saveBoard(int feld[DIM][DIM])
{
	stringstream ss;
	for (size_t i = 0; i < DIM; i++)
	{
		for (size_t j = 0; j < DIM; j++)
		{
			ss << feld[i][j] << "    ";
		}
		ss << endl;
	}
	list.add(ss.str());
}


bool showBoard(int feld[DIM][DIM])
{
	for (size_t i = 0; i < DIM; i++)
	{
		for (size_t j = 0; j < DIM; j++)
		{
			cout << feld[i][j] << "    ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;

	return true;
}

bool isFree(int feld[DIM][DIM], int testPosition[2])
{
	if (testPosition[0] >= DIM || testPosition[0] < 0)
		return false;
	if (testPosition[1] >= DIM || testPosition[1] < 0)
		return false;
	return feld[testPosition[0]][testPosition[1]] == 0;
}

bool findSolution(int feld[DIM][DIM], int position[2], int turnNumber)
{
	if (turnNumber>64)
	{
		showBoard(feld);
		return true;
	}
	int testPosition[2];

	//case 1
	testPosition[0] = position[0] - 1;
	testPosition[1] = position[1] - 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 2
	testPosition[0] = position[0] - 2;
	testPosition[1] = position[1] - 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 3
	testPosition[0] = position[0] - 2;
	testPosition[1] = position[1] + 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 4
	testPosition[0] = position[0] - 1;
	testPosition[1] = position[1] + 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 5
	testPosition[0] = position[0] + 1;
	testPosition[1] = position[1] + 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 6
	testPosition[0] = position[0] + 2;
	testPosition[1] = position[1] + 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 7
	testPosition[0] = position[0] + 2;
	testPosition[1] = position[1] - 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 8
	testPosition[0] = position[0] + 1;
	testPosition[1] = position[1] -2 ;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		if (findSolution(feld, testPosition, turnNumber + 1))
			return true;
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}
	return false;
}

void findAllSolutions(int feld[DIM][DIM], int position[2], int turnNumber)
{
	if (turnNumber>64)
	{
		saveBoard(feld);
		cout << "Solutions found=" << list.getSize() << endl;
		string s = list.getLast();
		cout << s << endl;
		return;
	}
	int testPosition[2];

	//case 1
	testPosition[0] = position[0] - 1;
	testPosition[1] = position[1] - 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld,testPosition,turnNumber+1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 2
	testPosition[0] = position[0] - 2;
	testPosition[1] = position[1] - 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 3
	testPosition[0] = position[0] - 2;
	testPosition[1] = position[1] + 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 4
	testPosition[0] = position[0] - 1;
	testPosition[1] = position[1] + 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 5
	testPosition[0] = position[0] + 1;
	testPosition[1] = position[1] + 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 6
	testPosition[0] = position[0] + 2;
	testPosition[1] = position[1] + 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 7
	testPosition[0] = position[0] + 2;
	testPosition[1] = position[1] - 1;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}

	//case 8
	testPosition[0] = position[0] + 1;
	testPosition[1] = position[1] - 2;
	if (isFree(feld, testPosition))
	{
		//test turn
		feld[testPosition[0]][testPosition[1]] = turnNumber;
		findAllSolutions(feld, testPosition, turnNumber + 1);
		// turn was wrong -> backtrack
		feld[testPosition[0]][testPosition[1]] = 0;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//init board
	int feld[DIM][DIM];
	for (size_t i = 0; i < DIM; i++)
	{
		for (size_t j = 0; j < DIM; j++)
		{
			feld[i][j] = 0;
		}
	}
	feld[7][0] = 1;

	int position[2] = { 7, 0 };

	//find one solution
	double time1 = 0.0, tstart;
	tstart = clock();
	findSolution(feld, position, 2);
	time1 += clock() - tstart;
	cout << "  Runtime = " << time1 << " milliseconds." << endl;

	//init board
	for (size_t i = 0; i < DIM; i++)
	{
		for (size_t j = 0; j < DIM; j++)
		{
			feld[i][j] = 0;
		}
	}
	feld[7][0] = 1;

	position[0]=7;
	position[1]= 0;

	//find all solutions
	findAllSolutions(feld, position, 2);


	getchar();
	return 0;
}

