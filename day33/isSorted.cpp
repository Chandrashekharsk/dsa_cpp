#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int i, vector<int> nums){
  if(i<=1) return true;
  if(nums[i-1]<nums[i-2]) return false;
  
  return isSorted(i-1, nums);
}

bool isSorted( vector<int> nums){
  if(nums.size()<=1) return true;

  for(int i=1; i<nums.size(); i++){
    if(nums[i] < nums[i-1]) return false;
  }
  
  return true;
}

int main(){
  // testCases:
  // vector<int> nums = {1,2,3,4,5,6};
  // vector<int> nums = {1,2,3,4,3,6};
  vector<int> nums = {1,2};

  cout<<isSorted(nums.size(), nums)<<" \n";
  cout<<isSorted(nums)<<" \n";


  return 0;
}