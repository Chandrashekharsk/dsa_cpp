// 64. Minimum Path Sum
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<vector<int>>& nums, int i, int j, vector<vector<int>>& dp) {
  if (i == 0 && j == 0) return nums[0][0];
  if (i < 0 || j < 0) return INT_MAX;
  if (dp[i][j] != -1) return dp[i][j];

  int up = helper(nums, i - 1, j, dp);
  int left = +helper(nums, i, j - 1, dp);
  return dp[i][j] = nums[i][j] + min(up, left);
}

int minPathSum(vector<vector<int>>& nums) {
  vector<vector<int>> dp(nums.size(), vector<int>(nums[0].size(), -1));
  return helper(nums, nums.size() - 1, nums[0].size() - 1, dp);
}

int minPathSum2(vector<vector<int>>& nums) {
  vector<vector<int>> dp(nums.size(), vector<int>(nums[0].size(), 0));

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[0].size(); j++) {

      if (i == 0 && j == 0) dp[i][j] = nums[0][0]; 
      else {
        int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
        int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
        dp[i][j] = min(up, left) + nums[i][j];
      }
    }
  }

  return dp[nums.size() - 1][nums[0].size() - 1];
}


int minPathSum3(vector<vector<int>>& nums) {
  vector<int> prev (nums[0].size(), 0);

  for (int i = 0; i < nums.size(); i++) {
    vector<int> curr (nums[0].size(), 0);
    for (int j = 0; j < nums[0].size(); j++) {

      if (i == 0 && j == 0) curr[j] = nums[0][0]; 
      else {
        // int up = (i > 0) ? prev[j] : INT_MAX;
        // int left = (j > 0) ? curr[j - 1] : INT_MAX;
        // curr[j] = min(up, left) + nums[i][j];

        int up = nums[i][j];
        if(i>0) up+= prev[j];
        else up += 1e9;
        int left = nums[i][j];
        if(j>0) left+= curr[j-1];
        else  left += 1e9;
        curr[j] = min(up, left);
      }
    }
    prev = curr;
  }  

  return prev[nums[0].size() - 1];
}

int main() {
  vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6},{7, 8, 9}};
  cout << minPathSum(nums) << "\n";
  cout << minPathSum2(nums) << "\n";
  cout << minPathSum3(nums) << "\n";
  return 0;
}