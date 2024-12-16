// *
// * *
// * * *
// * * * *

#include<iostream>
using namespace std;

int main(){

  cout<< "Enter number of rows or columns: ";
  int n; cin >> n;

  // PRINT STARTS
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<i+1; j++){
  //     cout<<"* ";
  //   }
  //   cout<<"\n";
  // }

  // PRINT NUMBERS
  for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
      cout<<i+1<<" ";
    }
    cout<<"\n";
  }

  return 0;
}