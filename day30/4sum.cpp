// 18. 4Sum
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int tar) {
  vector<vector<int>> ans;
  if (nums.size() < 4) return ans;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    for (int j = i + 1; j < nums.size(); j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;
      int st = j + 1, end = nums.size() - 1;

      while (st < end) {
        long long sum = (long long)nums[i] + nums[j] + nums[st] + nums[end];
        if (sum < tar) st++;
        if (sum > tar) end--;
        if (sum == tar) {
          ans.push_back({nums[i], nums[j], nums[st], nums[end]});
          st++;
          end--;
          while (st < end && nums[st] == nums[st - 1]) st++;
          while (st < end && nums[end] == nums[end + 1]) end--;
        }
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;

  vector<vector<int>> result = fourSum(nums, target);

  cout << "Quadruplets summing to " << target << ":\n";
  for (auto& quad : result) {
    for (int num : quad) {
      cout << num << " ";
    }
    cout << "\n";
  }

  return 0;
}