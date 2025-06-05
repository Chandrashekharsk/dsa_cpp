#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;

bool isDistinct(int start, vector<int> nums){
  unordered_set<int> s;
  while(start<nums.size()){
    if(s.count(nums[start])) return false;
    s.insert(nums[start]);
    ++start;
  }
  return true;
}


int minimumOperations(vector<int>& nums) {
  int n = nums.size();
  int ops = 0;

  for(int i=0; i<n; i+=3){
    if(isDistinct(i, nums)) return ops;
    ++ops;
  } 
  return ops;
}
int minimumOperations2(vector<int>& nums) {
  int n = nums.size();
  unordered_set<int> s;
  for(int i=n-1; i>=0; --i){
    if(s.count(nums[i])) return ceil((i+1)/3.0);
    s.insert(nums[i]);
  } 
  return 0;
}

int main(){
  vector<int> nums1 = {1, 2, 2, 3, 3, 3, 4};
  vector<int> nums2 = {1, 1, 1, 1, 1};
  vector<int> nums3 = {1, 2, 3, 4, 5};

  cout << "Test Case 1: " << minimumOperations2(nums1) << endl;
  cout << "Test Case 2: " << minimumOperations2(nums2) << endl;
  cout << "Test Case 3: " << minimumOperations2(nums3) << endl;

  return 0;
}