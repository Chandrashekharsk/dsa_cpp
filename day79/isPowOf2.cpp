// 231. Power of Two
#include<iostream>
#include<vector>
using namespace std;

bool isPowOf2(int n){
  if(n<=0) return false;
  return (n & (n-1)) == 0;
}

int main(){
  cout<<isPowOf2(0)<<endl;
  cout<<isPowOf2(1)<<endl;
  cout<<isPowOf2(2)<<endl;
  cout<<isPowOf2(3)<<endl;
  cout<<isPowOf2(4)<<endl;
  cout<<isPowOf2(6)<<endl;
  cout<<isPowOf2(8)<<endl;
  cout<<isPowOf2(10)<<endl;
  return 0;
}