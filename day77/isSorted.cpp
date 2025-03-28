#include <iostream>
#include <vector>
using namespace std;

bool isSorted(const vector<int>& nums) {
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1]) return false;
  }
  return true;
}

int main() {
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {5, 4, 3, 2, 1};
  vector<int> nums3 = {1, 3, 2, 4, 5};

  cout << "Is nums1 sorted? " << (isSorted(nums1) ? "Yes" : "No") << endl;
  cout << "Is nums2 sorted? " << (isSorted(nums2) ? "Yes" : "No") << endl;
  cout << "Is nums3 sorted? " << (isSorted(nums3) ? "Yes" : "No") << endl;

  return 0;
}