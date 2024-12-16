// 287. Find the Duplicate Number
// slow-fast pointer approach
#include <iostream>
#include <vector>
using namespace std;


int findDuplicate(vector<int>& nums) {
  int slow = nums[0], fast = nums[0];

  // Phase 1: Detect the cycle
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  // Phase 2: Find the start of the cycle
  slow = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}

int main() {
  // vector<int> nums = {3, 1, 3, 4, 2};
  // vector<int> nums = {1,1};
  vector<int> nums = {2,1,2};
  int duplicate = findDuplicate(nums);
  cout << "The duplicate number is: " << duplicate << endl;

  return 0;
}
