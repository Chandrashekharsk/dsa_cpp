#include <iostream>
#include <vector>
using namespace std;

int helper(int i, vector<int>& nums, int tar, vector<vector<int>>& dp) {
  if (i == 0) {
    if (tar % nums[i] == 0)
      return tar / nums[i];
    else
      return 1e9;
  }
  if (tar <= 0) return 0;
  if (dp[i][tar] != -1) return dp[i][tar];

  int pick = 1e9;
  if (nums[i] <= tar) pick = 1 + helper(i, nums, tar - nums[i], dp);
  int notPick = helper(i - 1, nums, tar, dp);
  return dp[i][tar] = min(pick, notPick);
}

int minCoins(vector<int>& nums, int tar) {
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));
  return helper(nums.size() - 1, nums, tar, dp);
}

int minCoins2(vector<int>& nums, int tar) {
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, 0));
  for (int j = 0; j <= tar; j++) {
    if(j % nums[0] == 0) dp[0][j] = j/nums[0];
    else dp[0][j] = 1e9;
  }

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= tar; j++) {

      int pick = 1e9;
      if (nums[i] <= j) pick = 1 + dp[i][j - nums[i]];
      int notPick = dp[i - 1][j];
      dp[i][j] = min(pick, notPick);
    }
  }
  return dp[nums.size()-1][tar];
}

int minCoins3(vector<int>& nums, int tar) {
  vector<int> prev (tar + 1, 0);
  vector<int> curr (tar + 1, 0);

  for (int j = 0; j <= tar; j++) {
    if(j % nums[0] == 0) prev[j] = j/nums[0];
    else prev[j] = 1e9;
  }

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= tar; j++) {

      int pick = 1e9;
      if (nums[i] <= j) pick = 1 + curr[j - nums[i]];
      int notPick = prev[j];
      curr[j] = min(pick, notPick);
    }
    prev = curr;
  }
  return prev[tar];
}

int main() {
  vector<int> nums = {3, 6, 4};
  // int tar = 6;
  int tar = 13;

  cout << minCoins(nums, tar)<<"\n";
  cout << minCoins2(nums, tar)<<"\n";
  cout << minCoins3(nums, tar)<<"\n";

  return 0;
}