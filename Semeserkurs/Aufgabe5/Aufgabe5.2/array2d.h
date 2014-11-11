#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <cassert>
#include <iostream>
#include <assert.h> 

using namespace std;

template <typename T> class Array2d {
public:
  Array2d(size_t z, size_t s)
      : zeilen{z}, spalten{s}, ptr{new T[z * s]} {}
  Array2d(size_t z, size_t s, const T &wert)
      : Array2d(z, s) { // an obigen Konstruktor delegieren
    init(wert);
  }
  Array2d(const Array2d &a)
      : Array2d(a.zeilen,
                a.spalten) { // an obigen Konstruktor delegieren
    size_t anzahl = zeilen * spalten;
    for (size_t i = 0; i < anzahl; ++i) {
      ptr[i] = a.ptr[i];
    }
  }

  ~Array2d() { delete[] ptr; }

  Array2d &operator=(const Array2d &arr) = delete; // (noch) verbieten

  template<size_t x, size_t y>
  Array2d(T (&arr)[x][y])
  :zeilen{x}, spalten{y}, ptr{new T[x*y]}{
    for(int i = 0; i<x; i++)
      for(int j = 0; j<y; j++)
        ptr[y*i + j]=arr[i][j];
  }

  Array2d &assign(Array2d tmp) {
    swap(tmp);
    return *this;
  }

  size_t getZeilen() const { return zeilen; }

  size_t getSpalten() const { return spalten; }

  void init(const T &wert) { // Alle Elemente mit wert initialisieren
    size_t anzahl = zeilen * spalten;
    for (size_t i = 0; i < anzahl; ++i) {
      ptr[i] = wert;
    }
  }

  const T &at(size_t z, size_t s) const {
    assert(z < zeilen && s < spalten);
    return ptr[z * spalten + s];
  }

  T &at(size_t z, size_t s) {
    assert(z < zeilen && s < spalten);
    return ptr[z * spalten + s];
  }

  void swap(Array2d &rhs) {
    size_t temp = zeilen;
    zeilen = rhs.zeilen;
    rhs.zeilen = temp;
    temp = spalten;
    spalten = rhs.spalten;
    rhs.spalten = temp;
    T *tempPtr = ptr;
    ptr = rhs.ptr;
    rhs.ptr = tempPtr;
  }

private:
  size_t zeilen;
  size_t spalten;
  T *ptr;

  //template<typename T>
  //friend Array2d<T> &mmult(Array2d<T> a, Array2d<T> b);
};

// Globale Funktion zur Ausgabe
template <typename T> void printArray(const Array2d<T> &a) {
  for (size_t z = 0; z < a.getZeilen(); ++z) {
    for (size_t s = 0; s < a.getSpalten(); ++s) {
      std::cout << a.at(z, s) << " ";
    }
    std::cout << std::endl;
  }
}

template<typename T>
Array2d<T> &mmult(Array2d<T> &a, Array2d<T> &b){ 
  assert(a.getSpalten()==b.getZeilen());
  Array2d<T> *result = new Array2d<T>(a.getZeilen(), b.getSpalten());
  result->init(0);
  for(int i = 0; i < a.getZeilen(); i++){
    for(int j = 0; j < b.getSpalten(); j++){
      T& val = result->at(i,j);
      for(int k = 0; k < a.getSpalten(); k++)
        val+= a.at(i,k) * b.at(k, j);
    }
  }
  return *result;
}
#endif
