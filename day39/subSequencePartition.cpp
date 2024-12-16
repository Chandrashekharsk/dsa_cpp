#include<iostream>
#include<vector>
using namespace std;

int canPartition(vector<int> nums){
  vector<int> prefixSum (nums.size(), 0);
  prefixSum[0] = nums[0];
  for(int i=1; i<nums.size(); i++){
    prefixSum[i] = nums[i] + prefixSum[i-1];
  }

  for(int i=0; i<nums.size()-1; i++){
    if( prefixSum[i] == prefixSum[nums.size()-1] - prefixSum[i]) return true;
  }
  return false;
}


int main(){

  vector<int> nums = {1,3,3,3,4};
  cout<< canPartition(nums);


  return 0;
}