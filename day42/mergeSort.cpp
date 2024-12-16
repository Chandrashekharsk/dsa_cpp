#include<iostream>
#include<vector>
using namespace std;

void conquor(int st, int end, int mid, vector<int>& nums){
  int i = st, j = mid+1, k=0;
  vector<int> temp((end-st)+1);

  while(i<=mid && j<=end){
    if(nums[i]<=nums[j]){
      temp[k++] = nums[i];
      i++;
    }else{
      temp[k++] = nums[j];
      j++;
    }
  }
  while(i<=mid){
    temp[k++] = nums[i];
    i++;
  }
  while(j<=end){
    temp[k++] = nums[j];
    j++;
  }

  // Copy sorted elements back to the original memory location (original array())
  copy(temp.begin(), temp.end(), nums.begin()+st);
}

void divide(int st, int end, vector<int>& nums){
  // st==end return;
  if(st<end){
    int mid = st + (end-st)/2;
    divide(st, mid, nums);
    divide(mid+1, end, nums);
    conquor(st,end, mid, nums);
  }
}

vector<int> sortArray(vector<int>& nums){
  divide(0, nums.size()-1, nums);
  return nums;
}

int main(){
  vector<int> nums = {5,2,3};
  for (auto i: sortArray(nums)) cout<< i<<" ";

  return 0;
}