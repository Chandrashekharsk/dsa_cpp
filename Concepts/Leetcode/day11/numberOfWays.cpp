// 2270. Number of Ways to Split Array
#include<iostream>
#include<vector>
using namespace std;

int waysToSplitArray(vector<int>& nums){
  long long int totalSum = 0, leftSum = 0;
  int validSplits = 0;
  for(int i: nums) totalSum += i;

  for(int i=0; i<nums.size()-1; i++){
    // excluding rightmost index
    leftSum += nums[i];
    long long int rightSum = totalSum - leftSum;
    if(leftSum >= rightSum) ++validSplits;
  }
  return validSplits;
}

int main(){
  vector<int> vec = {2,3,1,0};
  // vector<int> vec = {10,4,-8,7};
  cout<<waysToSplitArray(vec);

  return 0;
}