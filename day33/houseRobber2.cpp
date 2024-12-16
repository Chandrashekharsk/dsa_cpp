// 213. House Robber II
#include <iostream>
#include <vector>
using namespace std;

int maxSumOfNonAdjacent(vector<int> nums, int st, int end) {
  if(st == end ) return nums[st];
  
  int prev2 = 0, prev = nums[st];
  for (int i = st+1; i <= end; i++) {
    int take = nums[i] + (i==1? 0 : prev2);
    int notTake = 0 + prev;
    int curr = max(take, notTake);

    prev2 = prev;
    prev = curr;
  }
  return prev;
}

long long int houseRobber(vector<int>& nums) {
  if (nums.size() == 0 ) return 0;
  if (nums.size() == 1 ) return nums[0];

  return max(maxSumOfNonAdjacent(nums, 1, nums.size() - 1), maxSumOfNonAdjacent(nums, 0, nums.size() - 2));
}

int main() {
  vector<int> nums = {2, 1, 4, 9};
  cout << houseRobber(nums) << "\n";

  vector<int> nums2 = {2, 3, 2};
  cout << houseRobber(nums2) << "\n";

  vector<int> nums3 = {3, 2};
  cout << houseRobber(nums3) << "\n";

  return 0;
}