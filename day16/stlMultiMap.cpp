// MultiMap - sorted & can store same key multiple times
// MultiMap - (sorted, none-uniqueKeys)
// mm[key] = value,  not valid
#include<iostream>
#include<map>
using namespace std;



int main(){

  multimap<string, int> mm;
  mm.insert({"car",1500});
  mm.insert({"headphones",200});
  mm.insert({"headphones",200});
  mm.insert({"headphones",200});
  mm.emplace("tv",400);
  
  for(auto p: mm) cout<< p.first<<" "<<p.second<<"\n";

  // erase all matching keys
  // mm.erase("headphones");

    // erase particular key 
  mm.erase(mm.find("headphones")); 
  cout<< "PRINTING AGAIN....\n";

  for(auto p: mm) cout<< p.first<<" "<<p.second<<"\n";

  return 0;
}