// 1 1 1 1
// 2 2 2
// 3 3
// 4

#include<iostream>
using namespace std;

int main(){

  cout<<"Enter number of rows or columns: ";
  int n;cin>>n;

  for(int i=0; i<n;i++){
    for(int j=n-i; j>0; j--){
      cout<<i+1<<" ";
    }
    cout<<"\n";
  }

  return 0;
}