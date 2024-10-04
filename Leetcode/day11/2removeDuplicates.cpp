// 80: remove duplicates from sorted array II
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> nums){
  if(nums.size()<=2) return nums.size();
  int i = 2;
  for(int j=2; j<nums.size(); j++){
    if(nums[j] != nums[i-2]){
      nums[i] = nums[j];
      i++;
    }
  }
  return i;
}


int main(){
  vector<int> vec = {1,1,1,1,2,2,3};
  cout<< removeDuplicates(vec);

  return 0;
}