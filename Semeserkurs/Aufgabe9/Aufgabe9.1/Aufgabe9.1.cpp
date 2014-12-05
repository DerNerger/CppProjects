#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
typedef map<string, size_t>::iterator it_type;

map<string, size_t> getAllNames(string &str){
  map<string, size_t> names;
  stringstream ss;
  bool newString = true;
  for(int i = 0; i < str.length(); i++){
    if(newString){
       if( isalpha(str[i]) || str[i]=='_' ){
         ss << str[i];
         newString = false;
       }
    } else {
       if( isalnum(str[i]) || str[i] == '_'){
         ss << str[i];
       } else {
         newString = true;
         string newName;
         ss >> newName;
         ss.clear();
         names[newName] = names[newName] +1 ;
       }
    }
  }
  if(!newString){
     string newName;
     ss >> newName;
     names[newName] = names[newName] + 1;
  }
  return names;
}

bool aGeB(it_type a, it_type b){
  return a->second >= b->second;
}

class futor{
  public:
    bool operator()(it_type a, it_type b){
      return aGeB(a,b);
    }
};

int main(){
    cout << "Dateiname= " ;
    char * name = new char[20];
    cin.getline(name, 20);
    ifstream ifs(name);
    map<string, size_t> names;
    if(ifs){
        while(!ifs.eof()){
            string nextWord;
            ifs >> nextWord;
            map<string, size_t> result = getAllNames(nextWord);
            for(it_type iterator = result.begin(); iterator != result.end(); iterator++) {
              string key = iterator->first;
              size_t value = iterator->second;
              names[key] = names[key] + value;
            } 
        }
        vector<it_type> vec;
        cout << "Datei enthaelt die folgenden Namen:" << endl;
        for(it_type iterator = names.begin(); iterator != names.end(); iterator++) {
            cout << iterator->first << " = " << iterator->second << endl; 
            vec.push_back(iterator);
        }
        cout << endl << "sortiere Map" << endl << endl;
        //sort(vec.begin(), vec.end(), aGeB);  //sort with function aGeB
        sort(vec.begin(), vec.end(), futor()); //sort with functor

        int i=0;
        for(vector<it_type>::iterator it = vec.begin(); it!= vec.end(); it++){
          if(i==20) break;
          cout << (*it)->first << " = " << (*it)->second << endl;
          i++;
        }
    } else {
        cout << "Datei wurde nicht gefunden" << endl;
    }
}
