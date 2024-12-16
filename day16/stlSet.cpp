// Set(sorted), UnorderedSet(unSoted), MultiSet(sorted, not-uniqueValues)
// Set - (sorted, uniqueValues)
// 1. insert, emplace 
// 2. size, empty, erase 
// 3. count, find
// 4. lower_bound, upper_bound  -  they return iterator;

#include<iostream>
#include<set>
using namespace std;



int main(){
  set<int> s;
  s.insert(1);
  s.insert(1);
  s.insert(1);
  s.insert(4);
  s.insert(5);


  cout<< *(s.lower_bound(1))<<" \n"; // At least this or greater than this
  cout<< *(s.upper_bound(1))<<" \n"; // At least greater than this
  for(auto i: s) cout<< i<<" ";
  cout<<"\n";
  // if(s.find(3) != s.end()){
  //   cout<<"found";
  // }else{
  //   cout<<"not found";
  // }

  return 0;
}