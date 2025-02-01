// LIFO fashion
#include<iostream>
#include<vector>
using namespace std;

class Stack{
  private: 
  vector<int> v;
  public: // all funcs implemented in O(1) time
  int top(){
    return v.back();
  };
  void push(int x){
    v.push_back(x);
  };
  void pop(){
    v.pop_back();
  }
  bool empty(){
    return v.empty();
  }
  int size(){
    return v.size();
  }
};

int main(){

  Stack s;
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  cout<< s.top()<<endl;
  cout<< s.size()<<endl;

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}