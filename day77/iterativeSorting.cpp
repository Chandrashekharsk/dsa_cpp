#include <iostream>
#include <vector>
using namespace std;


vector<int> selectionSort(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIdx = i;
    for (int j = i + 1; j < n; ++j) {
      if (nums[j] < nums[minIdx]) {
        minIdx = j;
      }
    }
    swap(nums[i], nums[minIdx]);
  };
  return nums;
}

vector<int> bubbleSort(vector<int>& nums){
  int n = nums.size();
  for(int i=n-1; i>=1; --i){
    int didSwap = false;
    for(int j=0; j<i; ++j){
      if(nums[j]>nums[j+1]){
        swap(nums[j], nums[j+1]);
        didSwap = true;
      } 
    }
    if(!didSwap) break;
  }
  return nums;
}


// BEST CASE:  O(n)
// AVG CASE:   O(n^2)
// WORST CASE: O(n^2)
vector<int> insertionSort(vector<int> nums){
  int n = nums.size();
  for(int i = 0; i<n-1; ++i){
    int currIdx = i;
    while(currIdx>=0 && nums[currIdx]>nums[currIdx+1]){
      swap(nums[currIdx], nums[currIdx+1]);
      --currIdx;
    } 
  }
  return nums;
}

int main() {
  vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
  vector<int> sortedNums = selectionSort(nums);   
  cout << "Sorted array: ";
  for (int num : sortedNums) cout << num << " ";
  cout << endl;

  sortedNums = bubbleSort(nums);   
  cout << "Sorted array: ";
  for (int num : sortedNums) cout << num << " ";
  cout << endl;

  sortedNums = insertionSort(nums);   
  cout << "Sorted array: ";
  for (int num : sortedNums) cout << num << " ";
  cout << endl;
  
  return 0;
}