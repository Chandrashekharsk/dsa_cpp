#include <iostream>
#include <vector>
using namespace std;

int knapSack(int i, vector<int> nums, vector<int> weights, int capacity, vector<vector<int>> dp) {
  if (i == 0) {
    if (nums[i] <= capacity)
      return weights[i];
    else
      return 0;
  }
  if (capacity == 0) return 0;
  if (dp[i][capacity] != -1) return dp[i][capacity];

  int pick = -1e9;
  if (nums[i] <= capacity)
    pick =
        weights[i] + knapSack(i - 1, nums, weights, capacity - nums[i], dp);

  int notPick = knapSack(i - 1, nums, weights, capacity, dp);
  return dp[i][capacity] = max(pick, notPick);
}

int knapSack(vector<int>& nums, vector<int>& weights, int capacity) {
  vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, -1));
  return knapSack(nums.size() - 1, nums, weights, capacity, dp);
}

int knapSack2(vector<int>& nums, vector<int>& weights, int capacity) {
  vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, 0));

  for (int j = 0; j <= capacity; j++) {
    dp[0][j] = (nums[0] <= j) ? weights[0] : 0;
  }

// Fill the DP table
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= capacity; j++) {
      int pick = -1e8;
      if (nums[i] <= j) pick = weights[i] + dp[i - 1][j - nums[i]];
      int notPick = dp[i - 1][j];
      dp[i][j] = max(pick, notPick);
    }
  }
  return dp[nums.size() - 1][capacity];
  return dp[nums.size() - 1][capacity];
}

int knapSack3(vector<int>& nums, vector<int>& weights, int capacity) {
  vector<int> prev (capacity + 1, 0);
  vector<int> curr (capacity + 1, 0);

  for (int j = 0; j < capacity; j++) {
    prev[j] = (nums[0] <= j) ? weights[0] : 0;
  }

// Fill the DP table
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= capacity; j++) {
      int pick = -1e8;
      if (nums[i] <= j) pick = weights[i] + prev[j - nums[i]];
      int notPick = prev[j];
      curr[j] = max(pick, notPick);
    }
    prev = curr;
  }
  return prev[capacity];
}

int knapSack4(vector<int>& nums, vector<int>& weights, int capacity) {
  vector<int> prev (capacity + 1, 0);

  for (int j = 0; j <= capacity; j++) {
    prev[j] = (nums[0] <= j) ? weights[0] : 0;
  }

// Fill the DP table
  for (int i = 1; i < nums.size(); i++) {
    for (int j = capacity; j>=1; j--) {
      int pick = -1e8;
      if (nums[i] <= j) pick = weights[i] + prev[j - nums[i]];
      int notPick = prev[j];
      prev[j] = max(pick, notPick);
    }
  }
  return prev[capacity];
}


int main() {
  vector<int> nums = {3, 4, 5};
  vector<int> weights = {40, 20, 50};
  cout << knapSack(nums, weights, 7)<<"\n";
  cout << knapSack2(nums, weights, 7)<<"\n";
  cout << knapSack3(nums, weights, 7)<<"\n";
  cout << knapSack4(nums, weights, 7)<<"\n";

  return 0;
}