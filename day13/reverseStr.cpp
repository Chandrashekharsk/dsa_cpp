// reverse string using recursion
#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void reverse(vector<int>& nums,int st, int end){
  if(st>=end) return;
  swap(nums[st], nums[end]);
  reverse(nums, st+1, end-1);
}

int main(){

  vector<int> vec = {23,5,3,2,34};
  reverse(vec, 0,vec.size()-1);
  for(int i: vec){
    cout<<i<<"\n";
  }

  return 0;
}