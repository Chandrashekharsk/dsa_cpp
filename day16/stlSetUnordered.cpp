// UnorderedSet - (unSorted, uniqueValues)
#include<iostream>
#include<unordered_set>
using namespace std;



int main(){

  unordered_set<int> us;
  us.insert(1);
  us.insert(1);
  us.insert(3);
  us.insert(2);
  for(auto i: us) cout<< i<<" ";


  return 0;
}