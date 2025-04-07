// 137. Single Number II
#include <iostream>
#include <vector>
using namespace std;

bool isSetBit(int num, int pos) { return (num & (1 << pos)); }

int setBit(int num, int pos) { return num | (1 << pos); }

int findUniqueNum(int arr[], int n) {
  int ans = 0;

  for (int pos = 0; pos < 64; ++pos) {
    int sumAtPos = 0;
    for (int j = 0; j < n; ++j) {
      if ((arr[j]>>pos) & 1) ++sumAtPos;
    }

    if (sumAtPos % 3 != 0) ans |= 1<<pos;
  }

  return ans;
}

int main() {
  // Test cases for findUniqueNum
  int arr1[] = {2, 2, 3, 2};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << "Unique number in {2, 2, 3, 2}: " << findUniqueNum(arr1, n1)
       << " (Expected: 3)" << endl;

  int arr2[] = {0, 1, 0, 1, 0, 1, 99};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << "Unique number in {0, 1, 0, 1, 0, 1, 99}: " << findUniqueNum(arr2, n2)
       << " (Expected: 99)" << endl;

  int arr3[] = {7, 7, 7, 8};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  cout << "Unique number in {7, 7, 7, 8}: " << findUniqueNum(arr3, n3)
       << " (Expected: 8)" << endl;

  return 0;
}