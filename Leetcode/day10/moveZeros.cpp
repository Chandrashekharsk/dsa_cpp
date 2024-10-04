// 283. Move Zeroes
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void moveZeros(vector<int>& nums){
  int curr = 0, next = 0;
  while(next < nums.size()){
    if(nums[next] !=0){
      swap(nums[curr], nums[next]);
      curr++;
    }
    next++;
  }
}

int main(){
  vector<int> vec = {0,1,0,3,12};
  moveZeros(vec);
  for(int i: vec){
    cout<<i<<" ";
  }

  return 0;
}