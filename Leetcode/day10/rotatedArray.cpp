// search in rotated sorted array
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& A, int tar){
  int st = 0;
  int end = A.size()-1;

  while(st<=end){
    int mid = st + (end-st)/2;
    if(A[mid] == tar) return mid;
    // left sorted
    if( A[st]<= A[mid]){
      if(A[st]<= tar && tar <= A[mid]){
        end = mid-1;
      }else {
        //search in right part
        st = mid+1;
      }

    }else{
      // right sorted
      if(A[mid]<=tar && tar <= A[end]){
        st =  mid+1;
      }else{
        //search in left part
        end = mid-1;
      }
    }
  }
  return -1;
}

int main(){

  vector<int> vec = {4,5,6,7,0,1,2};
  cout<<search(vec, 0);

  return 0;
}