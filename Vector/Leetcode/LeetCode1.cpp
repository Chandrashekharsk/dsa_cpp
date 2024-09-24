// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one
// n^n == 0;
// n^0 == n;
#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums){
  int ans = 0;
  for(int v : nums){
    ans ^= v;
  }
  return ans;
}

int main(){
  vector<int> vec = {4,1,2,1,2};
  cout<< singleNumber(vec);
  
  return 0;
}