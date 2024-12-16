#include<iostream>
#include<vector>
using namespace std;

int helper(int i, int j, vector<vector<int>>& nums, vector<vector<int>> dp){
  if(i==0 && j== 0) return nums[i][j];
  if(i<0 || j<0 || j>nums[0].size()-1) return 1e-9;
  if(dp[i][j] != -1) return dp[i][j];

  int up = nums[i][j] + helper(i-1, j, nums, dp);
  int leftDiagonal = nums[i][j] + helper(i-1, j-1, nums, dp);
  int rightDiagonal = nums[i][j] + helper(i-1, j+1, nums, dp);
  return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int maxPathSum(vector<vector<int>>& nums){
  vector<vector<int>> dp (nums.size(), vector<int> (nums[0].size(), -1));
  return helper(nums.size()-1, nums[0].size()-1, nums, dp);
}

int maxPathSum2(vector<vector<int>>& nums){
  vector<vector<int>> dp (nums.size(), vector<int> (nums[0].size(), -1));
  for(int j=0; j<nums[0].size(); j++){
    dp[nums.size()-1][j] = nums[nums.size()-1][j];
  }

  for(int i=nums.size()-2; i>=0; i--){
    for(int j=nums[i].size()-1; j>=0; j--){

      int straight = dp[i+1][j];
      int rightDiagonal = dp[i+1][j+1];
      int leftDiagonal = dp[i+1][j-1];
      dp[i][j] = nums[i][j] + max(straight, max(leftDiagonal, rightDiagonal));
    }
  }
  return dp[0][0];
}

int maxPathSum3(vector<vector<int>>& nums){
  vector<int> next (nums[0].size(), -1);
  for(int j=0; j<nums[0].size(); j++){
    next[j] = nums[nums.size()-1][j];
  }

  for(int i=nums.size()-2; i>=0; i--){
    vector<int> curr (nums[0].size(),0);
    for(int j=nums[i].size()-1; j>=0; j--){

      int straight = next[j];
      int rightDiagonal = next[j+1];
      int leftDiagonal = next[j-1];
      curr[j] = nums[i][j] + max(straight, max(leftDiagonal, rightDiagonal));
    }
    next = curr;
  }
  return next[0];
}



int main(){
  vector<vector<int>> nums = {{9, 2, 3}, {4, 5, 6},{7, 8, 9}};
  cout << maxPathSum(nums) << "\n";
  cout << maxPathSum2(nums) << "\n";
  cout << maxPathSum3(nums) << "\n";
  return 0;
}