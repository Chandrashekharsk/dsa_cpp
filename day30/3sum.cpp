#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// BRUTE-FORCE approach
vector<vector<int>> findTriplets(vector<int>& nums) {
  vector<vector<int>> ans;
  set<vector<int>> s;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      for (int k = j + 1; k < nums.size(); k++) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          vector<int> triplets = {nums[i], nums[j], nums[k]};
          sort(triplets.begin(), triplets.end());

          if (s.find(triplets) == s.end()) {
            s.insert(triplets);
            ans.push_back(triplets);
          }
        }
      }
    }
  }
  return ans;
}

vector<vector<int>> findTriplets2(vector<int>& nums) {
  vector<vector<int>> ans;
  set<vector<int>> uniqueTriplets;

  for (int i = 0; i < nums.size(); i++) {
    set<int> tars;

    for (int j = i + 1; j < nums.size(); j++) {
      int tar = -nums[i] - nums[j];

      if (tars.find(tar) != tars.end()) {
        vector<int> triplets = {nums[i], nums[j], tar};
        sort(triplets.begin(), triplets.end());

        if (uniqueTriplets.find(triplets) == uniqueTriplets.end()) {
          ans.push_back(triplets);
          uniqueTriplets.insert(triplets);
        }
      }
      tars.insert(nums[j]);
    }
  }
  return ans;
}

vector<vector<int>> findTriplets3(vector<int>& nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; i++) {
    // avoid duplicates
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    int j = i + 1, k = nums.size() - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum < 0)
        j++;
      else if (sum > 0)
        k--;
      else if (sum == 0) {
        vector<int> temp = {nums[i], nums[j], nums[k]};
        ans.push_back(temp);
        j++;
        k--;
        while (j < k && nums[j] == nums[j - 1]) j++;
        while (k > j && nums[k] == nums[k + 1]) k--;
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = findTriplets3(nums);

  cout << "Triplets that sum to zero:" << endl;
  for (const auto& triplet : result) {
    cout << "[";
    for (size_t i = 0; i < triplet.size(); i++) {
      cout << triplet[i];
      if (i < triplet.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}
