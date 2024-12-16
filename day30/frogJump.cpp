// abs() - coverts all negative int values in positive values (i.e.) it only returns positive numbers.
// fabs() - coverts all negative floating values in positive values (i.e.) it only returns positive numbers.

#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Memoization (Top-down) -> initiate with greatest index
int frogJumpMemo(vector<int>& nums, vector<int>& dp, int i) {
  if (i == 0) return 0;            
  if (dp[i] != -1) return dp[i];  

  int left = frogJumpMemo(nums, dp, i - 1) + abs(nums[i] - nums[i - 1]);
  int right = INT_MAX;
  if (i > 1) {
    right = frogJumpMemo(nums, dp, i - 2) + abs(nums[i] - nums[i - 2]);
  }
  return dp[i] = min(left, right);
}

// Tabulation (Bottom-up)  -> initiate with lowest index
int frogJumpTab(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, 0); 

  dp[0] = 0;  

  for (int i = 1; i < n; i++) {
    int left = dp[i - 1] + abs(nums[i] - nums[i - 1]);
    int right = INT_MAX;
    if (i > 1) {
      right = dp[i - 2] + abs(nums[i] - nums[i - 2]);
    }
    dp[i] = min(left, right);
  }
  return dp[n - 1];  
}

// Optimized Tabulation (Bottom-up)  -> initiate with lowest index
int frogJumpTab2(vector<int>& nums) {
  int n = nums.size();
  int prev = 0, prev2 = 0;

  for (int i = 1; i < n; i++) {
    int left = prev + abs(nums[i] - nums[i - 1]);
    int right = INT_MAX;
    if (i > 1) {
      right = prev2 + abs(nums[i] - nums[i - 2]);
    }
    prev2 = prev;
    prev = min(left, right);
  }
  return prev; 
}

int main() {
  vector<int> nums = {10, 30, 40, 20};

  // Memoization
  vector<int> dp(nums.size(), -1);
  cout << "Minimum Cost (Memoization): "
      << frogJumpMemo(nums, dp, nums.size() - 1) << endl;

  // Tabulation
  cout << "Minimum Cost (Tabulation): " << frogJumpTab(nums) << endl;

  // Tabulation2
  cout << "Minimum Cost (Tabulation2): " << frogJumpTab2(nums) << endl;

  return 0;
}
