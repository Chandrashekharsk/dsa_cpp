#include <iostream>
#include <vector>
using namespace std;

int helper(int i, vector<int>& nums, int tar, vector<vector<int>>& dp) {
  if (i == 0) {
    if (tar % nums[0] == 0) return 1;
    return 0;
  }
  if (dp[i][tar] != -1) return dp[i][tar];

  int pick = 0;
  if (nums[i] <= tar) pick = helper(i, nums, tar - nums[i], dp);
  int notPick = helper(i - 1, nums, tar, dp);
  return dp[i][tar] = pick + notPick;
}

int findways(vector<int>& nums, int tar) {
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));
  return helper(nums.size() - 1, nums, tar, dp);
}

int findways2(vector<int>& nums, int tar) {
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, 0));
  for (int j=0; j<=tar; j++) dp[0][j] = (j%nums[0] == 0);

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j <= tar; j++) {
      int pick = 0;
      if (nums[i] <= j) pick = dp[i][j - nums[i]];
      int notPick = dp[i - 1][j];
      dp[i][j] = pick + notPick;
    }
  }
  return dp[nums.size()-1][tar];
}

int findways3(vector<int>& nums, int tar) {
  vector<int>prev (tar + 1, 0), curr (tar + 1, 0);
  for (int j=0; j<=tar; j++){
    prev[j] = curr[j] = (j%nums[0] == 0);
  } 

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j <= tar; j++) {
      int pick = 0;
      if (nums[i] <= j) pick = curr[j - nums[i]];
      int notPick = prev[j];
      curr[j] = pick + notPick;
    }
    prev = curr;
  }
  return prev[tar];
}

int main() {
  vector<int> nums = {1, 2, 3};
  int tar = 2;

  cout << findways(nums, tar)<<"\n";
  cout << findways2(nums, tar)<<"\n";
  cout << findways3(nums, tar)<<"\n";

  return 0;
}