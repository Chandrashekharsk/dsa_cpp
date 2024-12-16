#include <iostream>
#include <vector>
using namespace std;

int helper(int r, int c, vector<vector<int>>& nums, vector<vector<int>>& dp) {
  if (r < 0 || c < 0 || nums[r][c] == -1)
    return 0;  // Out of bounds or obstacle
  if (r == 0 && c == 0) return nums[0][0] != -1 ? 1 : 0;
  if (dp[r][c] != -1) return dp[r][c];

  int up = helper(r - 1, c, nums, dp);    // Path from above
  int left = helper(r, c - 1, nums, dp);  // Path from the left
  return dp[r][c] = up + left;
}

int sumOfUniquePath(vector<vector<int>>& nums) {
  if (nums.empty() || nums[0][0] == -1 || nums.back().back() == -1)
    return 0;  // Start or end is blocked
  vector<vector<int>> dp(nums.size(), vector<int>(nums[0].size(), -1));
  return helper(nums.size() - 1, nums[0].size() - 1, nums, dp);
}

int sumOfUniquePath2(vector<vector<int>>& nums) {
  if (nums.empty() || nums[0][0] == -1 || nums.back().back() == -1)
    return 0;  // Start or end blocked
  vector<vector<int>> dp(nums.size(), vector<int>(nums[0].size(), -1));

  dp[0][0] = nums[0][0] != -1 ? 1 : 0;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[0].size(); j++) {
      if (i == 0 && j == 0)
        continue;
      else if (nums[i][j] == -1)
        dp[i][j] = 0;
      else {
        int up = (i > 0) ? dp[i - 1][j] : 0;
        int left = (j > 0) ? dp[i][j - 1] : 0;
        dp[i][j] = up + left;
      }
    }
  }
  return dp[nums.size() - 1][nums[0].size() - 1];
}

int sumOfUniquePath3(vector<vector<int>>& nums) {
  if (nums.empty() || nums[0][0] == -1 || nums.back().back() == -1) return 0;  // Start or end blocked
  vector<int> prev (nums[0].size(), -1);



  for (int i = 0; i < nums.size(); i++) {
    vector<int> curr (nums[i].size(), 0);
    for (int j = 0; j < nums[0].size(); j++) {

      if (i == 0 && j == 0) curr[j] = 1;
      else if (nums[i][j] == -1) curr[j] = 0;
      else {
        int up = (i > 0) ? prev[j] : 0;
        int left = (j > 0) ? curr[j - 1] : 0;
        curr[j] = up + left;
      }
    }
    prev = curr;
  }
  return prev[nums[0].size() - 1];
}

int main() {
  vector<vector<int>> nums = {{1, 2}, {-1, 4}};
  cout << sumOfUniquePath(nums) << "\n";
  cout << sumOfUniquePath2(nums) << "\n";
  cout << sumOfUniquePath3(nums) << "\n";
  return 0;
}
