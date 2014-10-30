
#ifndef INTMENGE
#define INTMENGE

#include <vector>
#include <cstddef> //for size_t
#include <iostream> //for std::cout
#include <algorithm> //for std::find

using namespace std;

class IntMenge{
    private:
    vector<int> vec;

    public:
    IntMenge();
    IntMenge(IntMenge &obj);
    void add(int elem);
    void remove(int elem);
    bool contains(int elem);
    size_t size();
    void print();
    void clear();
    int getMin();
    int getMax();
};

#endif
