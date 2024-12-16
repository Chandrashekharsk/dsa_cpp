#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void helper(int i, vector<int>& nums, int tar, vector<int>& curr, vector<vector<int>>& ans) {
  if (i == nums.size()) {
    if (tar == 0) {
      ans.push_back(curr);  // Add the current combination to the result
    }
    return;
  }

  if (nums[i] <= tar) {
    curr.push_back(nums[i]);
    helper(i, nums, tar - nums[i], curr, ans);
    curr.pop_back();  // backtracking
  }
  helper(i + 1, nums, tar, curr, ans);
}


vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
  vector<vector<int>> ans; 
  vector<int> curr;
  helper(0, nums, tar, curr, ans);
  return ans;
}

int main() {
  vector<int> nums = {2, 3, 5};
  for (auto i : combinationSum(nums, 8)) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}