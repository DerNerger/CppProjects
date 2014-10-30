#include "IntMenge.h"

IntMenge::IntMenge() : vec(vector<int>(0)) {}
IntMenge::IntMenge(IntMenge &obj) : vec(vector<int>(obj.vec)) {}

inline size_t IntMenge::size(){
    return vec.size();
}

void IntMenge::add(int elem){
    if(!contains(elem))
        vec.push_back(elem);
}

void IntMenge::remove(int elem){
    vector<int>::iterator it = vec.begin();
    while( (it != vec.end()) && *it!=elem) it++;
    if(it==vec.end()) return; //element existiert nicht
    while(it != vec.end()-1){
        *it = *(it+1);
        it++;
    }
    vec.pop_back();
}

inline bool IntMenge::contains(int elem){
    return (find(vec.begin(), vec.end(), elem) != vec.end());
}

void IntMenge::print(){
    cout << "{ ";
    for (vector<int>::iterator it = vec.begin() ; it != vec.end(); it++)
        cout << *it << " ";
    cout << "}" << endl;
}

int IntMenge::getMin(){
    if(size()==0){
        cout << "FEHLER Menge ist leer" << endl;
        return -1;
    }

    int currentMin = vec[0];
    for (vector<int>::iterator it = vec.begin() ; it != vec.end(); it++)
        currentMin = *it < currentMin ? *it : currentMin;
    return currentMin;
}

int IntMenge::getMax() {
    if(size()==0){
        cout << "FEHLER Menge ist leer" << endl;
        return -1;
    }
    int currentMin = vec[0];
    for (vector<int>::iterator it = vec.begin() ; it != vec.end(); it++)
        currentMin = *it > currentMin ? *it : currentMin;
    return currentMin;
}

	void IntMenge::clear(){
    vec.clear();
}
