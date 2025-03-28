#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(const vector<int>& nums) {
  if (nums.empty()) return {};

  vector<int> ans;
  ans.push_back(nums[0]);

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] != nums[i - 1]) ans.push_back(nums[i]);
  }

  return ans;
}

int remDuplicates(vector<int>& nums) {
  if (nums.empty()) return 0;

  int i = 0;
  for (int j = 1; j < nums.size(); ++j) {
    if (nums[i] != nums[j]) {
      ++i;
      nums[i] = nums[j];
    }
  }
  return i + 1;  // Return the count of unique elements
}

int main() {
  vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
  vector<int> result = removeDuplicates(nums);

  cout << "Array after removing duplicates (new vector): ";
  for (int num : result) cout << num << " ";
  cout << endl;

  int uniqueCount = remDuplicates(nums);
  cout << "Array after removing duplicates (in-place): ";
  for (int i = 0; i < uniqueCount; ++i) cout << nums[i] << " ";
  cout << endl;

  return 0;
}