#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v(10);
    size_t s = v.size();
    cout << "size=" << s << endl;

    v.push_back(42);
    s = v.size();
    cout << "size=" << s << endl;
    cout << "v[10]=" << v[10] << endl;
}
