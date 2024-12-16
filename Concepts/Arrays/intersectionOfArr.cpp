// WAF to print intersaction of 2 arrays
#include<iostream>
#include<vector>
using namespace std;

vector<int> printIntersection(int arr1[], int arr2[], int s1, int s2){
  vector<int> commonVals;
  for(int i=0; i<s1; i++){
    bool common = false;
    for(int j=0; j<s2; j++){
      if(arr1[i] == arr2[j]){
        common= true;
        break;
      }
    }
    if (common) commonVals.push_back(arr1[i]);
  }
  return commonVals;
}

int main(){

  int arr1[] = {34,2,4,5,45,2,4,3,34,2,32};
  int s1 = sizeof(arr1)/ sizeof (arr1[0]);
  int arr2[] = {2,32,4,45,5,2,2,342,41,3};
  int s2 = sizeof(arr2)/ sizeof (arr2[0]);
  for (int i: printIntersection(arr1, arr2, s1, s2)){
    cout<<i<< " ";
  };


  return 0;
}