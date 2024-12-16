// 560. Subarray Sum Equals K
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// BruteForce approach
int subarraySum(vector<int>& nums, int k) {
  int count = 0;

  for (int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
      sum += nums[j];
      if (sum == k) count++;
    }
  }
  return count;
}

// PrefixSum approach
int subarraySum2(vector<int>& nums, int k) {
  int count = 0;
  vector<int> ps(nums.size(), 0);

  ps[0] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    ps[i] = ps[i - 1] + nums[i];
  }

  unordered_map<int, int> mp;  
  for (int j = 0; j < ps.size(); j++) {
    if (ps[j] == k) count++;

    int val = ps[j] - k;
    if (mp.find(val) != mp.end()) {
      count += mp[val];
    }

    // Update the frequency of the current prefix sum
    mp[ps[j]]++;
  }
  return count;
}

int main() {
  vector<int> nums = {1, 1, 1};
  cout << subarraySum2(nums, 2);

  return 0;
}