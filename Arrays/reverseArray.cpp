// Reverse given array 
// hint: use two pointer approach

#include<iostream>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void reverseArr(int arr[], int size){
  int startptr = 0;
  int endptr = size-1;
  while(endptr>startptr){
    swap(arr[startptr], arr[endptr]);
    endptr--;
    startptr++;
  }
}

int main(){

  int arr[] = {23,4,15,9,7,6,35,2,43};
  int n = sizeof(arr) / sizeof(arr[0]);
  reverseArr(arr, n);
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}