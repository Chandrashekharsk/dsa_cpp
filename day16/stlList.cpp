// List - Doubly LinkedList
// 1. push_back, push_front
// 2. emplace_back, emplace_front
// 3. pop_back, pop_front
// 4. front, end, rbegin, rend
// 5. size, clear, insert

// list[1] is not valid here, but it's valid for deque.

#include<iostream>
#include<list>
using namespace std;

  

int main(){
  list<int> l = {4,3,2,1};
  // list<int> l;
  // l.push_back(1);
  // l.push_back(2);
  // l.push_front(3);
  // l.push_front(4);
  
  for(auto i: l) cout<< i<<" ";
  cout<<"\n";
  l.pop_back();
  for(auto i: l) cout<< i<<" ";

  return 0;
}