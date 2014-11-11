#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

template <typename T>
struct Element {
    T value;
    Element *next;

    Element(T v, Element<T> *n) : value(v), next(n) { }
};

template <typename T>
void insert(Element<T>* &rp, T v) {
	if (rp != NULL) {
		if (v > rp->value) // Sortieren
			insert<T>(rp->next, v); // Rekursion
		else
			rp=new Element<T>(v, rp);
	}
	else
		rp=new Element<T>(v, NULL);
}


template <typename T>
void insert(Element<T>* &rp, T v, int (*cmp)(T&, T&)) {
	if (rp != NULL) {
		if (cmp(v, rp->value) > 0) // Sortieren
			insert<T>(rp->next, v); // Rekursion
		else
			rp=new Element<T>(v, rp);
	}
	else
		rp=new Element<T>(v, NULL);
}


template<typename T>
void print(Element<T> *p) {
	while(p) {
		std::cout << p->value << " ";
		p=p->next;
	}
	std::cout << std::endl;
}

template<typename T>
void remove(Element<T>* &rp, T v) {
	if (rp != NULL) {
		if (rp->value == v) {
			Element<T> *tmp=rp;
			rp = rp->next;
			delete tmp;
			remove<T>(rp, v);
		}
		else
			remove<T>(rp->next, v);// Rekursion
	}
}

#endif /* LINKEDLIST_H_ */
