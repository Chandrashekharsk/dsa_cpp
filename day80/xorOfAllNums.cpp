// 1863. Sum of All Subset XOR Totals
#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, const vector<int>& nums, vector<int>& temp, vector<vector<int>>& subsets){
  if(i == nums.size()){
    subsets.push_back(temp);
    return;
  }

  dfs(i+1, nums, temp, subsets); 
  temp.push_back(nums[i]);
  dfs(i+1, nums, temp, subsets);
  temp.pop_back();
}


int xorOfAllNums(vector<int> nums) {
  int n = nums.size();
  if(n==0) return 0; 

  vector<vector<int>> subsets;
  vector<int> temp;
  dfs(0, nums, temp, subsets);
  
  int xorSum = 0;
  for(int i=0; i<subsets.size(); i++){
    int currXorSum = 0;
    for(auto& it: subsets[i]){
      currXorSum ^= it;
    }
    xorSum += currXorSum;
  }
  return xorSum;
};


int dfs2(int i, vector<int>& nums, int total){
  if(i == nums.size()) return total;

  int take = dfs2(i+1, nums, total^nums[i]);
  int notTake = dfs2(i+1, nums, total);
  return take + notTake;
}

int xorOfAllNums2(vector<int>& nums) {
  if(nums.empty()) return 0; // Handle empty array case
  return dfs2(0, nums, 0);
}

int xorOfAllNums3(vector<int>& nums) {

  if(nums.empty()) return 0; 
  int orTotal = 0;
  for(auto& it: nums){
    orTotal |= it; 
  }
  int n = nums.size();
  return orTotal<<(n-1);
}

int main() {
  // Test Case 1: Non-empty array
  vector<int> nums1 = {5, 1, 6};
  cout << "Test Case 1 - XOR of all numbers: " << xorOfAllNums(nums1) << endl;

  // Test Case 2: Array with all elements the same
  vector<int> nums2 = {7, 7, 7, 7};
  cout << "Test Case 2 - XOR of all numbers: " << xorOfAllNums(nums2) << endl;

  // Test Case 3: Array with a single element
  vector<int> nums3 = {42};
  cout << "Test Case 3 - XOR of all numbers: " << xorOfAllNums(nums3) << endl;

  // Test Case 4: Empty array
  vector<int> nums4 = {};
  cout << "Test Case 4 - XOR of all numbers: " << xorOfAllNums(nums4) << endl;

  // Test Case 5: Array with alternating 0s and 1s
  vector<int> nums5 = {0, 1, 0, 1, 0, 1};
  cout << "Test Case 5 - XOR of all numbers: " << xorOfAllNums(nums5) << endl;

  // Test Case 6: Array with alternating 0s and 1s
  vector<int> nums6 = {1, 3};
  cout << "Test Case 6 - XOR of all numbers: " << xorOfAllNums(nums6) << endl;
  cout << "------------------------------------------------"<<endl;
  // Test Case 5: Array with alternating 0s and 1s
  vector<int> nums7 = {0, 1, 0, 1, 0, 1};
  cout << "Test Case 5 - XOR of all numbers: " << xorOfAllNums2(nums7) << endl;

  // Test Case 6: Array with alternating 0s and 1s
  vector<int> nums8 = {1, 3};
  cout << "Test Case 6 - XOR of all numbers: " << xorOfAllNums2(nums8) << endl;

  cout << "------------------------------------------------"<<endl;
  // Test Case 5: Array with alternating 0s and 1s
  vector<int> nums9 = {0, 1, 0, 1, 0, 1};
  cout << "Test Case 5 - XOR of all numbers: " << xorOfAllNums3(nums9) << endl;

  // Test Case 6: Array with alternating 0s and 1s
  vector<int> nums10 = {1, 3};
  cout << "Test Case 6 - XOR of all numbers: " << xorOfAllNums3(nums10) << endl;

  return 0;
}