// WAP to calculate sum & product of all numbers in an array
#include<iostream>
using namespace std;

int sumOfArr(int arr[], int size){
  int sum = 0;
  for(int i=0; i<size; i++){
    sum+= arr[i];
  }
  return sum;
}

long long int productOfArr(int arr[], int size){
  long long int product = 1;
  for(int i=0; i<size; i++){
    product *= arr[i];
  }
  return product;
}

int main(){

  int arr[] = {23,3,4,35,5,45,56,6,2};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout<< sumOfArr(arr,size)<<"\n";
  cout<< productOfArr(arr,size);

  return 0;
}