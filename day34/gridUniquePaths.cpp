#include <iostream>
#include <vector>
using namespace std;

int countUniquePaths(int i, int j, vector<vector<int>>& nums) {
  if (i == 0 && j == 0) return 1;
  if (i < 0 || j < 0) return 0;

  int up = countUniquePaths(i - 1, j, nums);
  int left = countUniquePaths(i, j - 1, nums);
  return up + left;
}

// memoization
int countUniquePaths2(int i, int j, vector<vector<int>>& nums,
                      vector<vector<int>>& dp) {
  if (i == 0 && j == 0) return 1;
  if (i < 0 || j < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int up = countUniquePaths(i - 1, j, nums);
  int left = countUniquePaths(i, j - 1, nums);
  return dp[i][j] = up + left;
}

// tabulation
int countUniquePaths3(vector<vector<int>>& nums) {
  vector<vector<int>> dp(nums.size() + 1, vector<int>(nums[0].size(), 0));

  dp[0][0] = 1;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[0].size(); j++) {
      int up = 0, left = 0;

      if (i > 0) up = dp[i - 1][j];
      if (j > 0) left = dp[i][j - 1];

      dp[i][j] += up + left;
    }
  }

  return dp[nums.size() - 1][nums[0].size() - 1];
}

// optimized tabulation
int countUniquePaths4(vector<vector<int>>& nums) {
  vector<int> prev(nums[0].size(), 0);

  for (int i = 0; i < nums.size(); i++) {
    vector<int> curr(nums[0].size(), 0);

    for (int j = 0; j < nums[0].size(); j++) {

      if(i==0 && j==0) curr[j] = 1;
      else{
        int up = 0, left = 0;
        if (i > 0) up = prev[j];
        if (j > 0) left = curr[j - 1];

        curr[j] += up + left;
      }
    }
    prev = curr;
  }

  return prev[nums[0].size() - 1];
}

int main() {
  // vector<vector<int>> nums = {{1, 2}, {3, 4}};
  vector<vector<int>> nums = {{1, 2}, {3, 4},{5,6}};
  cout << countUniquePaths(nums.size() - 1, nums[0].size() - 1, nums) << "\n";

  vector<vector<int>> dp(nums.size() + 1, vector<int>(nums[0].size(), -1));
  cout << countUniquePaths2(nums.size() - 1, nums[0].size() - 1, nums, dp) << "\n";
  cout << countUniquePaths3(nums) << "\n";
  cout << countUniquePaths4(nums) << "\n";

  return 0;
}