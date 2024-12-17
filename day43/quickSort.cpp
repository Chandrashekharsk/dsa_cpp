#include <iostream>
#include <vector>
using namespace std;
// TC: O(nlogn) -avg,  O(n^2) -worst
// SC:O(n)

void swap(int a, int b, vector<int>& nums){
  int temp = nums[a];
  nums[a] = nums[b];
  nums[b] = temp;
}

int partition(int st, int end, vector<int>& nums) {
  int j = st - 1;
  for (int i = st; i < end; i++) {
    if (nums[i] <= nums[end]) {
      j++;
      swap(i, j, nums);
    }
  }
  j++;
  swap(j, end, nums);
  return j;
}

void helper(int st, int end, vector<int>& nums) {
  if (st < end) {
    int pivotIdx = partition(st, end, nums);
    helper(st, pivotIdx - 1, nums);
    helper(pivotIdx + 1, end, nums);
  }
}

void quickSort(vector<int>& nums) { 
  helper(0, nums.size() - 1, nums);
}

int main() {
  vector<int> nums = {1, 3, 4, 2};
  quickSort(nums);
  for (auto i: nums) cout<<i<<" ";

  return 0;
}