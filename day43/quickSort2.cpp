#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& nums, int a, int b){
  int temp = nums[a];
  nums[a] = nums[b];
  nums[b] = temp;
}

int partition(vector<int>& nums, int st, int end) {
  int j = st - 1;
  // here we assume nums[end] is our pivot
  for (int i = st; i < end; i++) {
    if (nums[i] <= nums[end]) {
      j++;
      swap(nums, i, j);
    }
  }
  j++;
  swap(nums, j, end);
  return j;
}

void helper(int st, int end, vector<int>& nums) {
  if (st < end) {
    int pivotIdx = partition(nums, st, end);
    helper( st, pivotIdx - 1, nums);
    helper( pivotIdx + 1, end, nums);
  }
}

void quickSort(vector<int>& nums) { 
  helper (0, nums.size() - 1, nums);
}

int main() {
  vector<int> nums = {1, 3, 4, 2};
  quickSort(nums);
  for (auto i : nums) {
    cout << i << " ";
  }

  return 0;
}