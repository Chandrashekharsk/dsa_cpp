#include <iostream>
#include <vector>
using namespace std;

int invCountInversions(vector<int>& nums) {
  int invCount = 0;
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] > nums[i]) invCount++;
    }
  }
  return invCount;
}

int helper(int i, vector<int>& nums) {
  if (i == 0) return 0;

  int invCount = 0;
  for (int j = i - 1; j >= 0; j--) {
    if (nums[j] > nums[i]) invCount++;
  }
  return invCount + helper(i - 1, nums);
}

int invCountInversions2(vector<int>& nums) {
  return helper(nums.size() - 1, nums);
}

int merge(int st, int end, int mid, vector<int>& nums) {
  int i = st;
  int j = mid + 1, k = 0;
  int invCount = 0;
  vector<int> temp((end - st) + 1);

  while (i <= mid && j <= end) {
    if (nums[i] <= nums[j]) {
      temp[k++] = nums[i];
      i++;
    } else {
      invCount += mid - i + 1;
      temp[k++] = nums[j];
      j++;
    }
  }
  while (i <= mid) {
    temp[k++] = nums[i];
    i++;
  }
  while (j <= end) {
    temp[k++] = nums[j];
    j++;
  }
  copy(temp.begin(), temp.end(), nums.begin() + st);
  return invCount;
}

int divide(int st, int end, vector<int>& nums) {
  if(st >= end) return 0;
  
  int mid = st + (end - st) / 2;
  int leftInvinvCount = divide(st, mid, nums);
  int rightInvinvCount = divide(mid + 1, end, nums);
  return leftInvinvCount + rightInvinvCount + merge(st, end, mid, nums);
}

int invCountInversionsUsingMergeSort(vector<int>& nums) {
  return divide(0, nums.size() - 1, nums);
}

int main() {
  vector<int> nums = {6, 3, 5, 2, 7};
  cout << invCountInversions(nums) << "\n";
  cout << invCountInversions2(nums) << "\n";
  cout << invCountInversionsUsingMergeSort(nums) << "\n";

  return 0;
}