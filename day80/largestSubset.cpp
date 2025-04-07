#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int prev, vector<int>& nums, vector<int>& subSeq,
         vector<int>& ans) {
  if (i == nums.size()) {
    if (subSeq.size() > ans.size()) ans = subSeq;
    return;
  };
  if (prev == -1 || nums[i] % nums[prev] == 0) {
    subSeq.push_back(nums[i]);
    dfs(i + 1, i, nums, subSeq, ans);
    subSeq.pop_back();
  }

  dfs(i + 1, prev, nums, subSeq, ans);
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<int> subSeq;
  vector<int> ans;
  dfs(0, -1, nums, subSeq, ans);
  return ans;
}
vector<int> largestDivisibleSubset2(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<int> dp(n, 1);
  vector<int> prev(n, -1);
  int max_len = 1;
  int max_idx = 0;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
    if (dp[i] > max_len) {
      max_len = dp[i];
      max_idx = i;
    }
  }

  vector<int> result;
  while (max_idx != -1) {
    result.push_back(nums[max_idx]);
    max_idx = prev[max_idx];
  }

  return result;
}

int main() {
  vector<int> nums = {7, 2, 3};
  // vector<int> nums = {1,4,3,8};
  vector<int> result = largestDivisibleSubset2(nums);
  cout << "Largest Divisible Subset: ";
  for (auto& it : result) {
    cout << it << " ";
  }

  return 0;
}