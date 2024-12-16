// Stack - LIFO fashion
// 1. push, emplace, pop
// 2. size
// 3. top
// 4. empty
// 5. swap

#include<iostream>
#include<stack>
using namespace std;

  

int main(){

  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  
  // cout<< s.top();
  // cout<<"size: "<< s.size()<<" \n";
  // while(!s.empty()){
  //   cout<<s.top()<<" ";
  //   s.pop();
  // }
  // cout<<"\n";

  stack<int> s2;
  s2.swap(s);
  cout<<"sizeOf s: "<< s.size()<<" \n";
  cout<<"sizeOf s2: "<< s2.size()<<" \n";


  return 0;
}