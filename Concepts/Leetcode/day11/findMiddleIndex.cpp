// 1991. Find the Middle Index in Array
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

  int findMiddleIndex(vector<int>& nums){
    int totalSum = 0;
    int leftSum = 0;
    for(int i: nums) totalSum +=i;

    for(int i=0; i<nums.size(); i++){
      int rightSum = totalSum - nums[i] - leftSum;
      if(rightSum == leftSum) return i;
      leftSum += nums[i];
    }
    return -1;
  }

int main(){

  vector<int> vec = {2,3,-1,8,4};
  cout<< findMiddleIndex(vec);

  return 0;
}