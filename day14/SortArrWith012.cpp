// 75.Sort Colors
// low, mid, high   (unsorted part exists between mid & high)

#include<iostream>
#include<vector>
using namespace std;

void dutchFlagSortingAlgo(vector<int>& nums){
  int low = 0, mid = 0, high = nums.size()-1;

  while(mid<=high){
    if(nums[mid]== 0){
      swap(nums[mid], nums[low]);
      mid++; low++;
    }else if(nums[mid]==1){
      mid++;
    }else{
      swap(nums[high], nums[mid]);
      high--;
    }
  }
}


int main(){

  vector<int> vec = {0,2,1,1,1,2,0,0,2,1};
  dutchFlagSortingAlgo(vec);
  for(int i: vec) cout<<i<<" ";

  return 0;
}