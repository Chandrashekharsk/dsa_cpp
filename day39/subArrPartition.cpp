#include<iostream>
#include<vector>
using namespace std;


bool helper(int i, vector<int>& nums, int tar, vector<vector<int>>& dp){
  if(tar == 0) return true;
  if(i==0) return nums[i] == tar;
  if(dp[i][tar] != -1) return dp[i][tar];
  
  bool include = false;
  if(nums[i]<= tar) include = helper(i-1, nums, tar-nums[i], dp);
  bool exclude = helper(i-1, nums, tar, dp);
  return dp[i][tar] = include || exclude;
}

bool canPartition(vector<int>& nums){
  int totalSum = 0;
  for(int i=0; i<nums.size(); i++) totalSum += nums[i];
  if(totalSum %2 !=0) return false;
  int tar = totalSum/2;
  vector<vector<int>> dp(nums.size(), vector<int> (tar+1, -1));

  return helper(nums.size()-1, nums, tar, dp);
}

bool canPartition2(vector<int>& nums){
  int totalSum = 0;
  for(int i=0; i<nums.size(); i++) totalSum += nums[i];
  if(totalSum %2 !=0) return false;
  int tar = totalSum/2;

  vector<vector<bool>> dp(nums.size(), vector<bool> (tar+1, false));
  for(int i=0; i<nums.size(); i++) dp[i][0] = true;
  if (nums[0] <= tar) dp[0][nums[0]] = true;

  for(int i=1; i<nums.size(); i++){
    for(int j=1; j<=tar; j++){

      bool include = false;
      if(nums[i] <= j) include = dp[i-1][j-nums[i]];
      bool exclude = dp[i-1][j];
      dp[i][j] = include || exclude;
    }
  }
  return dp[nums.size()-1][tar];
}

bool canPartition3(vector<int>& nums){
  int totalSum = 0;
  for(int i=0; i<nums.size(); i++) totalSum += nums[i];
  if(totalSum %2 !=0) return false;
  int tar = totalSum/2;

  vector<bool> prev(tar+1, false);
  vector<bool> curr(tar+1, false);
  prev[0] = curr[0] = true;
  if(nums[0]<= tar) prev[nums[0]] = true;

  for(int i=1; i<nums.size(); i++){
    for(int j=1; j<=tar; j++){

      bool include = false;
      if(nums[i] <= j) include = prev[j-nums[i]];
      bool exclude = prev[j];
      curr[j] = include || exclude;
    }
    prev = curr;
  }
  return prev[tar];
}


int main(){
  vector<int> nums = {2,3,3,3,4,5};
  cout<< canPartition(nums)<<"\n";
  cout<< canPartition2(nums)<<"\n";
  cout<< canPartition3(nums)<<"\n";

  return 0;
}