#include<iostream>
#include<vector>
using namespace std;

int helper(int st, int end, vector<int>& nums){
  if(end<st) return 0;

  int include = nums[end] + (end>1? helper(st, end-2, nums): 0);
  int exclude = helper(st, end-1, nums);
  return max(include,exclude);
}

int helper2(int st, int end, vector<int>& nums){
  if(end<st) return 0;

  int prev2 = 0, prev = nums[st];
  for(int i=st; i<=end; i++){
    int include = nums[i] + prev2;
    int exclude = prev;

    int currMax = max(include, exclude);
    prev2 = prev;
    prev = currMax;
  }
  return prev;
}

int houseRobber2(vector<int>& nums){
  if(nums.size() == 0) return 0;
  if(nums.size() == 1) return nums[0];
  int excludeFirstIdx =  helper2(1, nums.size()-1, nums);
  int excludeLastIdx =  helper2(0, nums.size()-2, nums);
  return max(excludeLastIdx, excludeFirstIdx);
}

int main(){

  vector<int> nums= {2,1, 4, 9};
  cout<< houseRobber2(nums);


  return 0;
}