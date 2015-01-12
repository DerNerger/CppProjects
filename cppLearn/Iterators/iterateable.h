#include <vector>
#include <iterator>

using namespace std;

//typedef vector<int>::iterator it;

class iterateable;

class it_iterator : iterator<forward_iterator_tag, int>{
  private:
    iterateable& it;
    int elem;
  public:
    it_iterator(iterateable &it, int elem) : it(it), elem(elem) {}

    bool operator==(it_iterator &oter){
        return elem==oter.elem;
    }
    
    bool operator!=(it_iterator &oter){
        return elem!=oter.elem;
    }

    int& operator*();

    void operator++(){
        elem++;
    }
};

typedef it_iterator it;
class iterateable{
    private:
        int arr[5];
        vector<int> v;

    public:
        iterateable() : v(5) {
            arr[0]=0;
            arr[1]=3;
            arr[2]=5;
            arr[3]=7;
            arr[4]=9;
            v[0]=0;
            v[1]=1;
            v[2]=2;
            v[3]=3;
            v[4]=4;
        }
       int &getElem(int a){ return arr[a];}

 ls
   it begin() { return it_iterator(*this,0);}
    it end() { return it_iterator(*this,5);}
};

int& it_iterator::operator*(){
  return it.getElem(elem);
}
