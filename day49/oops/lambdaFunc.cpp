// lambda funtion -> Anonymus Function
// same as python lambda or same as js IIFE func
#include<iostream>
#include<vector>
using namespace std;



int main(){


  []{cout<<"Hello guys\n";}();
  [](){return 100;};

  auto sum = [](auto a, auto b){return a+b;};
  cout<< sum(2, 5)<<endl;

  string a = "hello ";
  string b = "world!";
  cout<< sum(a, b)<<endl;


  return 0;
}