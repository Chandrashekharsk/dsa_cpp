// WAF to swap the max & min number of an array;
#include<iostream>
#include<climits>
using namespace std;

void swap(int arr[], int &a, int &b) {
  int temp = arr[a];
  a = b;
  b = temp;
}

void swapMaxWithMin(int arr[], int size) {
  int min = INT_MAX;
  int max = INT_MIN;
  int minIdx = 0;
  int maxIdx = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
      minIdx = i;
    }
    if (arr[i] > max) {
      max = arr[i];
      maxIdx = i;
    }
  }
  swap(arr[minIdx],arr[maxIdx]);
}

int main(){

  int arr[] = {3,45,5,6,67,7,7,3,1,4};
  int size = sizeof(arr)/sizeof(arr[0]);
  swapMaxWithMin(arr, size);
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}