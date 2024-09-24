#include<iostream>
using namespace std;

int findTarget(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 5, 24, 3, 9, 6};
  int target = 9;
  int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the array size
  int index = findTarget(arr, n, target); // Pass the correct size and target
  if (index != -1) {
    cout << "Target found at index: " << index << endl;
  } else {
    cout << "Target not found" << endl;
  }
  return 0;
}
