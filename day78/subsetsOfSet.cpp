#include <iostream>
#include <vector>
using namespace std;

// number of subsets = 2^n - 1
// 2^n = 1<<n => 1 left shift n times

vector<vector<int>> subSetsOfSet(int nums[], int n) {
  vector<vector<int>> ans;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> subset;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        subset.push_back(nums[j]);
      }
    }
    ans.push_back(subset);
  }
  return ans;
}
int main() {
  // Test cases for subSetsOfSet
  int nums[] = {1, 2, 3};
  int n = sizeof(nums) / sizeof(nums[0]);

  vector<vector<int>> subsets = subSetsOfSet(nums, n);

  cout << "Subsets of the set {1, 2, 3}:" << endl;
  for (const auto& subset : subsets) {
    cout << "{ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}