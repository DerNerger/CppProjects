/*
 * Main.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: kibellus
 */

#include "LinkedList.h"

using namespace std;

template<typename T>
int cmpAufsteigend(T &a, T &b){
	if(a==b)
		return 0;
	if(a<b)
		return -1;
	return 1;
}

template<typename T>
int cmpAbsteigend(T &a, T &b){
	if(a==b)
		return 0;
	if(a>b)
		return -1;
	return 1;
}

int main(){
	Element<int> *head = NULL;

	cout << "insert mit Funktion cmpAbsteigend" << endl;
	for (int i = 0; i < 10; ++i) {
		insert(head, i, cmpAbsteigend);
	}
	print(head);

	cout << "liste leeren"<< endl;
	for (int i = 0; i < 10; ++i) {
		remove(head, i);
	}
	print(head);

	cout << "insert mit Funktion cmpAufsteigend" << endl;
	for (int i = 0; i < 10; ++i) {
		insert(head, i, cmpAufsteigend);
	}
	print(head);

	cout << "liste leeren"<< endl;
	for (int i = 0; i < 10; ++i) {
		remove(head, i);
	}
	print(head);

	cout << "insert ohne Funktion(default auch Aufsteigend)" << endl;
	for (int i = 0; i < 10; ++i) {
		insert(head, i);
	}
	print(head);

}
