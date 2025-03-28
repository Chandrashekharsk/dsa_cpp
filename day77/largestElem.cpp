#include <iostream>
#include <vector>
using namespace std;

int largestElem(vector<int>& nums) {
  int start = 0, end = nums.size() - 1;
  int largest = -1e9;
  while (start <= end) {
    largest = max(largest, nums[start]);
    largest = max(largest, nums[end]);
    ++start;
    --end;
  }
  return (largest != -1e9) ? largest : -1;
}

int secondLargest(const vector<int>& nums) {
  int largest = nums[0], secondLargest = INT_MIN;

  for (int num : nums) {
    if (num > largest) {
      secondLargest = largest;
      largest = num;
    } else if (num > secondLargest && num < largest) {
      secondLargest = num;
    }
  }

  return (secondLargest != INT_MIN) ? secondLargest : -1;
}

int secondSmallest(const vector<int>& nums) {
  int smallest = nums[0], secSmallest = INT_MAX;

  for (auto& it : nums) {
    if (it < smallest) {
      secSmallest = smallest;
      smallest = it;
    } else if (it < secSmallest && it > smallest) {
      secSmallest = it;
    }
  }
  return (secSmallest != INT_MAX) ? secSmallest : -1;
}

int main() {
  vector<int> nums = {64, 34, 25, 12, 22, 11, 90};

  int largest = largestElem(nums);
  cout << "Largest Element: " << largest << endl;

  int secLargest = secondLargest(nums);
  cout << "Second Largest Element: " << secLargest << endl;

  int secSmallest = secondSmallest(nums);
  cout << "Second Smallest Element: " << secSmallest << endl;

  return 0;
}