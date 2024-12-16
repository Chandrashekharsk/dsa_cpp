// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4

#include<iostream>
using namespace std;

int main(){

  cout<< "Enter number of rows or columns: ";int n; cin>> n;

  // PRINT NUMERICS 
  // for (int i=1; i<=n; i++){
  //   for(int j=1; j<=n; j++){
  //     cout<<j<<" ";
  //   }
  //   cout<<"\n";
  // }

// PRINT CHARACTORS
  // for (int i=1; i<=n; i++){
  //     char ch = 'A';
  //   for(int j=1; j<=n; j++){
  //     cout<<ch<<" ";
  //     ch++;
  //   }
  //   cout<<"\n";
  // }

  int count = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<count<<" ";
      count++;
    }
    cout<<"\n";
  }

  return 0;
}