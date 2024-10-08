// Remove Duplicates from Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  int i = 0;
  for(int j=1; j<nums.size(); j++){
    if(nums[i]!=nums[j]){
      i++; 
      nums[i] = nums[j];
    }
  }
  return i+1;
}

int main(){
  vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
  // vector<int> nums = {1,1,2};
  cout<<removeDuplicates(nums);
  return 0;
}