#include <iostream>
#include <vector>
using namespace std;

void merge(int start, int mid, int end, vector<int>& nums) {
  vector<int> temp;
  int left = start;
  int right = mid + 1;
  while (left <= mid && right <= end) {
    if (nums[left] <= nums[right]) {
      temp.push_back(nums[left]);
      ++left;
    } else {
      temp.push_back(nums[right]);
      ++right;
    }
  }
  while (left <= mid) {
    temp.push_back(nums[left]);
    ++left;
  }
  while (right <= end) {
    temp.push_back(nums[right]);
    ++right;
  }
  for (int k = start; k <= end; ++k) {
    nums[k] = temp[k - start];
  }
}

void divide(int start, int end, vector<int>& nums) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;
  divide(start, mid, nums);
  divide(mid + 1, end, nums);

  merge(start, mid, end, nums);
}

void mergeSort(vector<int>& nums) { divide(0, nums.size() - 1, nums); }

int partition(int start, int end, vector<int>& nums) {
  int lowest = start;
  int pivot = nums[lowest];
  int highest = end;

  while (start < end) {
    while (nums[start] <= pivot && start < highest) ++start;
    while (nums[end] > pivot && end > lowest) --end;
    if (start < end) swap(nums[start], nums[end]);
  }
  swap(nums[end], nums[lowest]);
  return end;
}

void qs(int start, int end, vector<int>& nums) {
  if (start >= end) return;

  int pivotIdx = partition(start, end, nums);
  qs(start, pivotIdx - 1, nums);
  qs(pivotIdx + 1, end, nums);
}

void quickSort(vector<int>& nums) { qs(0, nums.size() - 1, nums); }

int main() {
  vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
  vector<int> nums2 = nums;

  mergeSort(nums);
  cout << "Merge Sort: ";
  for (int num : nums) cout << num << " ";
  cout << endl;

  quickSort(nums2);
  cout << "Quick Sort: ";
  for (int num : nums2) cout << num << " ";
  cout << endl;

  return 0;
}