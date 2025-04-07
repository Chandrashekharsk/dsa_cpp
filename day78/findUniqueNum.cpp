// 136. Single Number
#include <iostream>
#include <vector>
using namespace std;

// XOR gives 0 for same bits
// XOR gives 1 for different bits

int findUniqueNum(int arr[], int n) {
  int xorSum = 0;
  for (int i = 0; i < n; ++i) {
    xorSum ^= arr[i];
  };
  return xorSum;
}

bool isSetBit(int num, int pos) { return (num & (1 << pos)); }
vector<int> find2UniqueNums(int arr[], int n) {
  int xorSum = 0;
  for (int i = 0; i < n; ++i) {
    xorSum ^= arr[i];
  }
  if (xorSum == 0) return {-1, -1};

  int ans = xorSum;
  int setBitPos = 0, pos = 0;

  while (setBitPos != 1) {
    setBitPos = xorSum & 1;
    if (setBitPos == 1) break;

    ++pos;
    xorSum >>= 1;
  }

  int xorSum2 = 0;
  for (int i = 0; i < n; ++i) {
    if (isSetBit(arr[i], pos)) xorSum2 ^= arr[i];
  }
  return {ans ^ xorSum2, xorSum2};
}

int main() {
  // Test cases for findUniqueNum
  int arr1[] = {1, 2, 3, 2, 1};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << "Unique number in {1, 2, 3, 2, 1}: " << findUniqueNum(arr1, n1)
       << " (Expected: 3)" << endl;

  int arr2[] = {4, 5, 6, 5, 4};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << "Unique number in {4, 5, 6, 5, 4}: " << findUniqueNum(arr2, n2)
       << " (Expected: 6)" << endl;

  int arr3[] = {7};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  cout << "Unique number in {7}: " << findUniqueNum(arr3, n3)
       << " (Expected: 7)" << endl;

  // Test cases for find2UniqueNums
  int arr4[] = {1, 2, 3, 2, 1, 4};
  int n4 = sizeof(arr4) / sizeof(arr4[0]);
  vector<int> result = find2UniqueNums(arr4, n4);
  cout << "Two unique numbers in {1, 2, 3, 2, 1, 4}: {" << result[0] << ", "
       << result[1] << "} (Expected: {3, 4})" << endl;

  int arr5[] = {5, 6, 7, 7, 8, 6, 5, 8};
  int n5 = sizeof(arr5) / sizeof(arr5[0]);
  result = find2UniqueNums(arr5, n5);
  cout << "Two unique numbers in {5, 6, 7, 6, 5, 8}: {" << result[0] << ", "
       << result[1] << "} (Expected: {-1, -1})" << endl;

  return 0;
}