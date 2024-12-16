// Pair - used to store pairs of any data types
#include<iostream>
#include<vector>
using namespace std;

// using push_back() we have to pass pair in the form of object ({1,2})
// but using emplace_back() we simplay pass value separeted by comma (1,2)


int main(){

  // pair<string, int> p = {"chandrashekhar", 20};

  // pair<int, pair<string, int>> p = {1,{ "chandrashekhar", 20}};
  // cout<< p.first<<" "<<p.second.first<< " "<<p.second.second;


  vector<pair<int,int>> vec = {{1,2}, {3,4}, {5,6}};
  // for(auto p: vec) cout<< p.first<<" "<<p.second<<"\n";
  vec.push_back({7,8});
  vec.emplace_back(10,20); 
  for(auto p: vec) cout<< p.first<<" "<<p.second<<"\n";
  return 0;
}