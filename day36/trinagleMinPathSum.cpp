// 120. Triangle Min Path Sum
#include<iostream>
#include<vector>
using namespace std;

int helper(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp){
  if(i==nums.size()-1) return nums[i][j];
  if(dp[i][j] != -1) return dp[i][j];

  int down = helper(i+1, j, nums, dp);
  int diagonal = helper(i+1, j+1, nums, dp);
  return dp[i][j] = min(down, diagonal) + nums[i][j];
}

int minPathSum(vector<vector<int>>& nums){
  vector<vector<int>> dp(nums.size());
  for(int i=0; i<nums.size(); i++){
    dp[i].resize(nums[i].size(),-1);  // Resize dp[i] to match nums[i]
  }
  return helper(0, 0, nums, dp);
}

int minPathSum2(vector<vector<int>>& nums){
  vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));
  
  for(int j=0; j<nums[nums.size()-1].size(); j++){
    dp[nums.size()-1][j] = nums[nums.size()-1][j];
  }

  for(int i=nums.size()-2; i>=0; i--){
    for(int j=nums[i].size()-1; j>=0; j--){
      
      int down =  dp[i+1][j];
      int diagonal = dp[i+1][j+1];
      dp[i][j] = nums[i][j] + min(down, diagonal);
    }
  }
  return dp[0][0];
}

int minPathSum3(vector<vector<int>>& nums){
  vector<int> next(nums[nums.size()-1].size(), 0);
  
  for(int j=0; j<nums[nums.size()-1].size(); j++){
    next[j] = nums[nums.size()-1][j];
  }

  for(int i=nums.size()-2; i>=0; i--){
    vector<int> curr(nums[i].size(), 0);
    for(int j=nums[i].size()-1; j>=0; j--){
      
      int down = next[j];
      int diagonal = next[j+1];
      curr[j] = nums[i][j] + min(down, diagonal);
    }
    next= curr;
  }
  return next[0];
}

int main(){
  vector<vector<int>> nums = {{1}, {6, 5},{7, 4, 8}};
  cout << minPathSum(nums) << "\n";
  cout << minPathSum2(nums) << "\n";
  cout << minPathSum3(nums) << "\n";

  return 0;
}