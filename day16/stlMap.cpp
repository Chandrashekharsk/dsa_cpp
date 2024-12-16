//  Map(sorted), unordered_map(unsorted), multimap(sorted & can store same key multiple times)

// Map - (sorted, uniqueKeys)
// 1. insert, emplace 
// 2. size, empty, erase 
// 3. count, find 

// map[key] = value; is valid here
#include<iostream>
#include<map>
using namespace std;


int main(){
  map<string,int> m;
  m["tv"] = 100;
  m["laptop"] = 300;
  m["headphones"] = 180;
  m["headphones"] = 180;
  m.insert({"camera", 500});
  m.emplace("car", 3500);

  for(auto p: m) cout<< p.first<<" "<<p.second<<"\n";
  cout<< m["laptop"]<<"\n";
  cout<< m.count("laptop")<<"\n";

  if(m.find("car") != m.end()){
    cout<< "found\n";
  }else{
    cout<< "not found\n";
  }

  return 0;
}