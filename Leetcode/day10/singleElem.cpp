// 540. Single Element in a Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums){
  if(nums.size() == 1) return nums[0];
  int st = 0, end = nums.size()-1;

  while(st<=end){
    int mid = st + (end - st)/2;
    if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];
    if(mid == nums.size()-1 && nums[mid] != nums[mid-1]) return nums[mid];
    if( nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

    if(mid%2 == 0){
      // mid is even == both arrays length is even
      if(nums[mid] == nums[mid-1]){
        // if match in left -> search in left
        end = mid-1;
      }else{
        // if match in right -> search in right
        st = mid+1;
      }

    }else{
      // mid is odd == both arrays length is odd
      if(nums[mid] == nums[mid-1]){
        // if match in left -> search in right
        st = mid+1;
      }else{
        // if match in right -> search in left
        end = mid-1;
      }

    }
  }
  return -1;
}

int main(){
  vector<int> vec = {1,1,2,3,3,4,4,8,8};
  cout<< singleNonDuplicate(vec);
  

  return 0;
}