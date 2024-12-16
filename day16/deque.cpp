// Deque - Double ended queue (internally it uses dynamic arrays) 
// operations are same as list have
// d[1] is valid here, but it's not valid for list.
#include<iostream>
#include<deque>
using namespace std;

  

int main(){

  deque<int> d = {1,2,3,4,5};
  d.push_back(6);

  // for(auto it= d.begin(); it != d.end(); it++) cout<< *(it)<<" ";
  for(auto i: d) cout<<i<<" ";

  return 0;
}