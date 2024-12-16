// Prioritypqueue - by default it is "max heap", but we can also create "min heap"
// 1. push, emplace, pop
// 2. top
// 3. size
// 4. empty

#include<iostream>
#include<queue>
using namespace std;


int main(){

  // priority_queue<int> pq;
  // below greater<int> is a functor
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(5);
  pq.push(15);
  pq.push(10);

  while(!pq.empty()){
    cout<< pq.top()<<" ";
    pq.pop();
  }

  return 0;
}