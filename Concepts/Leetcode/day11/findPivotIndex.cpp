// 724. Find Pivot Index
#include<iostream>
#include<vector>
using namespace std;

  int pivotIndex(vector<int>& nums){
    int totalSum = 0;
    int leftSum = 0;
    for (int i: nums){
      totalSum += i;
    } 

    for(int i=0; i<nums.size(); i++){
      int rightSum = totalSum - nums[i] - leftSum;
      if(leftSum == rightSum) return i;
      leftSum+=nums[i];
    }
    return -1;

  }

int main(){

  // vector<int> vec = {1,7,3,6,5,6};
  vector<int> vec = {2,-5,5};
  cout<<pivotIndex(vec);

  return 0;
}