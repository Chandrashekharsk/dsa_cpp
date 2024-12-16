// UnorderedMap - (unSorted, uniqueKeys) 
// m[key] = value,  VALID
#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
  unordered_map<string, int> um;
  um.insert({"tv", 400});
  um.insert({"tv", 400});
  um.insert({"tv", 800});
  um.insert({"car", 400});
  for(auto i: um) cout<< i.first<<" "<< i.second<<"\n";

  return 0;
}