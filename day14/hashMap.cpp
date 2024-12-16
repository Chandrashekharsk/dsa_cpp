#include<iostream>
#include<vector>
#include<map>
// #include <unordered_map>
using namespace std;

  

int main(){

  map<int, string> map;
  map[0] = "apple";
  map[1] = "mango";
  map[2] = "banana";
  map[3] = "orange";

  // cout<< map[3];
  for(auto pair: map ){
    cout<< pair.first<<" "<< pair.second<<"\n";
  }
  return 0;
}