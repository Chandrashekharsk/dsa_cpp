#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive with Memoization
int helper(int i, int tar, vector<int>& nums, vector<vector<int>>& dp) {
  if (i == 0) {
    if (tar == 0 && nums[i] == 0) return 2;  // Include or exclude '0'
    if (tar == 0 || nums[i] == tar) return 1;
    return 0;
  }

  if (dp[i][tar] != -1) return dp[i][tar];

  int pick = 0;
  if (nums[i] <= tar) pick = helper(i - 1, tar - nums[i], nums, dp) % MOD;
  int notPick = helper(i - 1, tar, nums, dp) % MOD;

  return dp[i][tar] = (pick + notPick) % MOD;
}

int countPartitionWithGivenDiff(vector<int>& nums, int D) {
  int totSum = 0;
  for (auto& it : nums) totSum += it;

  if ((totSum - D) % 2 != 0 || totSum - D < 0) return 0;
  int tar = (totSum - D) / 2;

  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));
  return helper(nums.size() - 1, tar, nums, dp);
}

// Bottom-Up DP
int countPartitionWithGivenDiff2(vector<int>& nums, int D) {
  int totSum = 0;
  for (auto& it : nums) totSum += it;

  if ((totSum - D) % 2 != 0 || totSum - D < 0) return 0;
  int tar = (totSum - D) / 2;

  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

  // Base case initialization
  dp[0][0] = (nums[0] == 0) ? 2 : 1;  // If nums[0] == 0, two ways (include/exclude)
  if (nums[0] != 0 && nums[0] <= tar) dp[0][nums[0]] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= tar; j++) {  // Start from j = 0
      int pick = 0;
      if (nums[i] <= j) pick = dp[i - 1][j - nums[i]] % MOD;
      int notPick = dp[i - 1][j] % MOD;

      dp[i][j] = (pick + notPick) % MOD;
    }
  }

  return dp[n - 1][tar];
}

// Space-Optimized Bottom-Up DP
int countPartitionWithGivenDiff3(vector<int>& nums, int D) {
  int totSum = 0;
  for (auto& it : nums) totSum += it;

  if ((totSum - D) % 2 != 0 || totSum - D < 0) return 0;
  int tar = (totSum - D) / 2;

  int n = nums.size();
  vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

  // Base case initialization
  prev[0] = (nums[0] == 0) ? 2 : 1;
  if (nums[0] != 0 && nums[0] <= tar) prev[nums[0]] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= tar; j++) {  // Start from j = 0
      int pick = 0;
      if (nums[i] <= j) pick = prev[j - nums[i]] % MOD;
      int notPick = prev[j] % MOD;

      curr[j] = (pick + notPick) % MOD;
    }
    prev = curr;  // Move current to previous for next iteration
  }

  return prev[tar];
}

int main() {
  vector<int> nums = {5, 5, 3, 0, 2};
  cout << countPartitionWithGivenDiff(nums, 1) << "\n";
  cout << countPartitionWithGivenDiff2(nums, 1) << "\n";
  cout << countPartitionWithGivenDiff3(nums, 1) << "\n";

  return 0;
}
