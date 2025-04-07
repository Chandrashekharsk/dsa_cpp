// 191. Number of 1 Bits
#include<iostream>
#include<vector>
using namespace std;

int hammingWeight(int n) {
  int cnt = 0;
  while(n){
    ++cnt;
    n &= n-1;
  }
  return cnt;
}

int main(){


  return 0;
}