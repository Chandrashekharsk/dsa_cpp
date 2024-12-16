#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minSubsetDiff(vector<int> nums) {
  int totSum = 0;
  for (int i = 0; i < nums.size(); i++) totSum += nums[i];
  vector<vector<bool>> dp(nums.size(), vector<bool>(totSum + 1, false));

  // Initialize DP for the first element
  for(int i=0; i<nums.size(); i++) dp[i][0] = true;
  if (nums[0] <= totSum) dp[0][nums[0]] = true;

  // Fill the DP table
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j <= totSum / 2; j++) {
      bool pic = false;
      if (nums[i] <= j) pic = dp[i - 1][j - nums[i]]; // Pick current element
      bool notPick = dp[i - 1][j]; // Do not pick current element
      dp[i][j] = pic || notPick;
    }
  }

  // Find the minimum absolute sum difference
  int mini = 1e9;
  for (int s1 = 0; s1 <= totSum / 2; s1++) {
    if (dp[nums.size() - 1][s1] == true) {
      mini = min(mini, abs((totSum - s1) - s1));
    }
  }

  return mini;
}

int main() {
  vector<int> nums = {1, 2, 3, 9}; // Sample input
  cout << "Minimum absolute sum difference: " << minSubsetDiff(nums) << endl;
  return 0;
}
