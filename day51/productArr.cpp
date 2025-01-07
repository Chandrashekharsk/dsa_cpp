// Q1. Maximum Subarray With Equal Products
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


int maxLength(vector<int>& nums){
  int maxLength = 0;
  for (int i=0; i<nums.size(); ++i){
    int currLcm = nums[i];
    int currGcd = nums[i];
    double prod = 1;

    for(int j=i; j<nums.size(); ++j){
      currLcm = lcm(currLcm, nums[j]);
      currGcd = gcd(currGcd, nums[j]);
      prod *= nums[j];
      if(prod == currLcm*currGcd) maxLength = max(maxLength, j-i+1);
    }
  }
  return maxLength;
}

int main(){

  vector<int> nums1 = {1, 2, 1, 2, 1, 1, 1};
  vector<int> nums2 = {2, 3, 4, 5, 6};
  vector<int> nums3 = {1, 2, 3, 1, 4, 5, 1};
  cout << "Example 1 Output: " << maxLength(nums1) << endl; // Output: 5
  cout << "Example 2 Output: " << maxLength(nums2) << endl; // Output: 3
  cout << "Example 3 Output: " << maxLength(nums3) << endl; // Output: 5


  return 0;
}