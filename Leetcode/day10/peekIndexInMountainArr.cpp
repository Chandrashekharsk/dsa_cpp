// 852: peak index in mountain array
#include<iostream>
#include<vector>
using namespace std;

int findPeakIndex(vector<int> nums){
  // int st = 0, end = nums.size()-1;
  int st = 0, end = nums.size()-2;
  // This is to avoid error check if mid-1 or mid+1 doesn't exists and we already know 
  // 3 <= arr.length <= 105, array length will be at least 3 and there definatly peak will exists.
  
  while(st<=end){
    int mid = st + (end-st)/2;
    if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;
    
    if(nums[mid-1]<nums[mid]){
      st = mid+1;
    }else{
      end = mid-1;
    }
    
  }
  return -1;
}

int main(){

  vector<int> vec = {0,3,8,9,5,2};
  cout<< findPeakIndex(vec);

  return 0;
}