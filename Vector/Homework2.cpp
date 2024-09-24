// WAF to reverse an vector/arr
// use 2 pointer approach
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void reverse(vector<int>& vec){
  int start= 0;
  int end = vec.size()-1;
  while(end>start){
    swap(vec[start], vec[end]);
    end--; start++;
  }
}

int main(){

  vector<int> vec = {3,5,43,2,5,9,24,6,4};
  reverse(vec);
  for(int v: vec){
    cout<<v<<" ";
  }

  return 0;
}