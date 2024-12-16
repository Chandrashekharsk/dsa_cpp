// 1.Two Sum
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int tar) {
  unordered_map<int, int> m;
  vector<int> ans;

  for (int i = 0; i < nums.size(); i++) {
    int first = nums[i];
    int sec = tar - first;

    if (m.find(sec) != m.end()) {
      ans.push_back(i);
      ans.push_back(m[sec]);
      break;
    }
    m[first] = i;
  }
  return ans;
}

int main() {
  // Sample input
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  // Call the function
  vector<int> result = twoSum(nums, target);

  // Display the result
  if (!result.empty()) {
    cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;
  } else {
    cout << "No two numbers found with the given target." << endl;
  }

  return 0;
}
