#include<iostream>
#include<vector>
using namespace std;

bool recursiveBinarySearch(vector<int> nums, int tar, int st, int end){
  if(st>=end) return false;

  int mid = st + (end - st)/2;
  if(nums[mid] == tar) return true;
  else if(nums[mid] < tar){
    return recursiveBinarySearch(nums, tar, mid+1, end);
  }else {
    return recursiveBinarySearch(nums, tar, st, mid-1);
  }
}

int main(){
  vector<int> nums = {1,2,3,4,5,6,7,8};
  cout<<recursiveBinarySearch(nums, 5, 0, nums.size()-1);

  return 0;
}