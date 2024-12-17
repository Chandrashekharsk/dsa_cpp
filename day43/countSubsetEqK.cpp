#include <iostream>
#include <vector>
using namespace std;

int helper(int i, vector<int> nums, int sum, vector<vector<int>>& dp) {
  if (sum == 0) return 1;
  if (i == 0) return nums[i] == sum;
  if (dp[i][sum] != -1) return dp[i][sum];

  int pick = 0;
  if (nums[i] <= sum) pick = helper(i - 1, nums, sum - nums[i], dp);
  int notPick = helper(i - 1, nums, sum, dp);
  return dp[i][sum] = pick + notPick;
}

int countSumOfSubsetsEqK(vector<int>& nums, int sum) {
  vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
  return helper(nums.size() - 1, nums, sum, dp);
}

int countSumOfSubsetsEqK2(vector<int>& nums, int sum) {
  vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));
  for (int i = 0; i < nums.size(); i++) dp[i][0] = 1;
  if (nums[0] <= sum) dp[0][nums[0]] = 1;

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j < nums.size(); j++) {
      int pick = 0;
      if (nums[i] <= sum) pick = dp[i - 1][sum - nums[i]];
      int notPick = dp[i - 1][sum];
      dp[i][sum] = pick + notPick;
    }
  }
  return dp[nums.size()-1][sum];
}

int countSumOfSubsetsEqK3(vector<int>& nums, int sum) {
  vector<int> prev(sum + 1, 0);
  vector<int> curr(sum + 1, 0);

  prev[0]= curr[0] = 1;
  if (nums[0] <= sum) prev[nums[0]] = 1;

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j < nums.size(); j++) {
      int pick = 0;
      if (nums[i] <= sum) pick = prev[sum - nums[i]];
      int notPick = prev[sum];
      curr[sum] = pick + notPick;
    }
    prev = curr;
  }
  return prev[sum];
}

int main() {
  vector<int> nums = {2, 3, 8, 5};
  cout << countSumOfSubsetsEqK(nums, 5)<<"\n";
  cout << countSumOfSubsetsEqK2(nums, 5)<<"\n";
  cout << countSumOfSubsetsEqK3(nums, 5)<<"\n";

  return 0;
}