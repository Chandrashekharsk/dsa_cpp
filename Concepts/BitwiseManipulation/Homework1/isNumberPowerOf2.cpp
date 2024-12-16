// find if a number is power of 2 without any loop.

#include<iostream>
using namespace std;

int main(){

  cout<<"Enter a number: "; int n; cin>> n;
  int x = n-1;
  if(!(n & x)){
    cout<<"True";
  }else{
    cout<<"False";
  }

  return 0;
}