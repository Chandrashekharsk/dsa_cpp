// selection sort
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void selectionSort(vector<int>& nums){
  for(int i=0; i<nums.size()-1; i++){
    int si = i;
    for(int j=i+1; j<nums.size(); j++){
      if(nums[j]<nums[si]) si = j;
    }
    swap(nums[si], nums[i]);
  }
}

int main(){

  vector<int> vec = {38,4,5,3,5,6,6,324};
  selectionSort(vec);
  for(int i: vec) cout<<i<<" ";

  return 0;
}