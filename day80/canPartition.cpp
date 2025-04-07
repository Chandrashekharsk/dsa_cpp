// 416. Partition Equal Subset tar
#include <iostream>
#include <vector>
using namespace std;

bool helper(int i, int tar, vector<int>& nums, vector<vector<int>>& dp) {
  if (tar == 0) return true;                      // Found a subset
  if (i >= nums.size() || tar < 0) return false;  // Base case

  if (dp[i][tar] != -1) return dp[i][tar];  // Memoization

  // Either include nums[i] or skip it
  bool take = false;
  if (nums[i] <= tar) take = helper(i + 1, tar - nums[i], nums, dp);
  bool notTake = helper(i + 1, tar, nums, dp);

  return dp[i][tar] = take || notTake;
}

bool canPartition(vector<int>& nums) {
  int totSum = 0;
  for (int num : nums) totSum += num;
  if (totSum % 2 != 0) return false;

  int tar = totSum / 2;
  vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));
  return helper(0, tar, nums, dp);
}

bool canPartition2(vector<int>& nums) {
  int totSum = 0;
  for (int num : nums) totSum += num;
  if (totSum % 2 != 0) return false;
  int tar = totSum / 2;
  int n = nums.size();

  vector<vector<int>> dp(n+1, vector<int>(tar + 1, false));
  
  for(int i=0; i<n; ++i){
    dp[i][0] = true; // Base case: sum of 0 is always possible
  };
  dp[0][nums[0]] = true;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= tar; ++j) {
      bool take = false;
      if (nums[i] <= j) take = dp[i - 1][j - nums[i]];
      bool notTake = dp[i-1][j];
      dp[i][j] = take || notTake;
    }
  }
  return dp[n-1][tar];
}

bool canPartition3(vector<int>& nums) {
  int totSum = 0;
  for (int num : nums) totSum += num;
  if (totSum % 2 != 0) return false;
  int tar = totSum / 2;
  int n = nums.size();

  vector<int> prev(tar + 1, false), curr(tar + 1, false);
  if(nums[0]<= tar) prev[nums[0]] = curr[nums[0]] = true;
  // prev[0] = curr[0] = true; // Base case: sum of 0 is always possible

  for (int i = 1; i < n; ++i) {
    prev[0] = true; // Base case: sum of 0 is always possible
    for (int j = 1; j <= tar; ++j) {
      bool take = false; 
      if (nums[i] <= j) take = prev[j - nums[i]];
      bool notTake = prev[j];
      curr[j] = take || notTake;
    }
    prev = curr;
  }
  return prev[tar];
}

int main() {
  vector<int> nums = {1, 5, 11, 5};
  if (canPartition2(nums)) {
    cout << "Can partition into two subsets with equal tar." << endl;
  } else {
    cout << "Cannot partition into two subsets with equal tar." << endl;
  }
  if (canPartition3(nums)) {
    cout << "Can partition into two subsets with equal tar." << endl;
  } else {
    cout << "Cannot partition into two subsets with equal tar." << endl;
  }
  return 0;
}