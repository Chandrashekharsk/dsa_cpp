// WAF to print all the unique values in an array
#include<iostream>
#include<vector>
using namespace std;

vector<int> printUnique(int arr[], int n){
  vector<int> uniqueVals;

  for(int i=0; i<n; i++){
    bool unique = true;
    for(int j=0; j<n; j++){
      if(i != j && arr[i] == arr[j]){
        unique= false;
        break;
      }
    }
    if (unique) uniqueVals.push_back(arr[i]);
  }
  return uniqueVals;
}

int main(){

  int arr[] = {23,23,4,5,35,56,45,56,6,2};
  int size = sizeof(arr)/sizeof(arr[0]);
  for(int i : printUnique(arr,size)){
    cout<<i<<" ";
  } 

  return 0;
}

