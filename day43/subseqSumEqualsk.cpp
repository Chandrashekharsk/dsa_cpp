#include <iostream>
#include <vector>
using namespace std;

bool helper(int i, vector<int>& nums, int tar, vector<vector<int>>& dp) {
  if (tar == 0) return true;
  if (i == 0) return nums[i] == tar;
  if (dp[i][tar] != -1) return dp[i][tar];

  bool pick = false;
  if (nums[i] <= tar) pick = helper(i - 1, nums, tar - nums[i], dp);
  bool notPick = helper(i - 1, nums, tar, dp);
  return dp[i][tar] = pick || notPick;
}

bool isExist(vector<int>& nums, int tar) {
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));
  return helper(nums.size() - 1, nums, tar, dp);
}

bool isExist2(vector<int>& nums, int tar) {
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, 0));
  for (int i = 0; i < nums.size(); i++) dp[i][0] = true;
  if (nums[0] <= tar) dp[0][nums[0]] = true;

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= tar; j++) {
      bool pick = false;
      if (nums[i] <= j) pick = dp[i - 1][j - nums[i]];
      bool notPick = dp[i - 1][j];
      dp[i][j] = pick || notPick;
    }
  }
  return dp[nums.size()-1][tar];
}

bool isExist3(vector<int>& nums, int tar) {
  vector<bool>prev (tar + 1, false);
  vector<bool>curr (tar + 1, false);

  prev[0] = curr[0] = true;
  if (nums[0] <= tar) prev[nums[0]] = true;

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= tar; j++) {
      bool pick = false;
      if (nums[i] <= j) pick = prev[j - nums[i]];
      bool notPick = prev[j];
      curr[j] = pick || notPick;
    }
    prev = curr;
  }
  return prev[tar];
}

int main() {
  vector<int> nums = {2, 3, 4};
  int tar = 67;

  cout << isExist(nums, tar)<<"\n";
  cout << isExist2(nums, tar)<<"\n";
  cout << isExist3(nums, tar)<<"\n";

  return 0;
}