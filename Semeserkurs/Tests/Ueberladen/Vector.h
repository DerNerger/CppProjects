#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Vector{
  private:
    int x;
    int y;

  public:
    Vector(int pX, int pY) : x(pX), y(pY) {}
    Vector(int arr[2]) : x(arr[0]), y(arr[1]) {}
    
    Vector & operator+=(const Vector & vec){
      x+=vec.x;
      y+=vec.y;
    }

  int & operator[](int index){
    if(index < 0 || index > 1) throw out_of_range("Index fail");
    if(index == 0) return x;
    else           return y;
  }

  Vector &operator=(const Vector & v){
    x = v.x;
    y = v.y;
    return *this;
  }
 
  operator string() const {
    string str = "(";
    str+=x+'0';
    str+=",";
    str+=y+'0';
    str+=")";
    return str;
  }

  //friends
  friend ostream & operator<< (ostream & stream, const Vector & vec){
    stream << "(" << vec.x <<"," << vec.y << ")";
    return stream;
  }

  friend Vector operator+ (const Vector & v1, const Vector & v2){
    return Vector(v1)+=v2;
  }

};
