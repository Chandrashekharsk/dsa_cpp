// 31. next permutation
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void nextPermutation(vector<int>& nums) {
  int n = nums.size(), pivot = -1;
// find pivot 
  for(int i=n-2; i>=0; i--){
    if(nums[i]<nums[i+1]){
      pivot = i;
      break;
    }
  }
  cout<<"pivot: "<< pivot<<" \n";
  // edge case if whole array is in decreasizing fashion
  if(pivot == -1){
    int st = 0, end = n-1;
    while(st<=end){
      swap(nums[st], nums[end]);
      st++; end--;
    }
    return;
  }
  cout<< "done\n";

  // find next larger element
  for(int i=n-1; i>pivot; i--){
    if(nums[i]> nums[pivot]){
      swap(nums[i], nums[pivot]);
      break;
    }
  }
  
  int st = pivot+1, end = n-1;
  while(st<end){
    swap(nums[st], nums[end]);
    st++; end--;
  }

}

int main(){

  // vector<int> vec = {3,2,1};
  // vector<int> vec = {1,1,5};
  vector<int> vec = {1,2,3};
  nextPermutation(vec);
  for(auto i: vec) cout<< i<<" ";

  return 0;
}