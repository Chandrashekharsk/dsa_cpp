#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int>& nums){
  int totSum = 0;
  for (auto i: nums) totSum += i;
  if(totSum % 2 != 0) return false;
  int tar = totSum/2;
  
  vector<bool>prev (tar + 1, false);
  vector<bool>curr (tar + 1, false);

  prev[0] = curr[0] = true;
  if (nums[0] <= tar) prev[nums[0]] = true;

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= tar; j++) {
      bool pick = false;
      if (nums[i] <= j) pick = prev[j - nums[i]];
      bool notPick = prev[j];
      curr[j] = pick || notPick;
    }
    prev = curr;
  }
  return prev[tar];
}

int main(){

  vector<int> nums = {2, 3, 5, 14};
  // vector<int> nums = {6, 5, 4, 3};

  cout<<canPartition(nums);


  return 0;
}