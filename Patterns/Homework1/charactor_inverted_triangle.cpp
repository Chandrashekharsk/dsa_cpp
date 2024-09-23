// A A A A 
//   B B B 
//     C C 
//       D

#include<iostream>
using namespace std;

int main(){

  cout<< "Enter number of rows: ";
  int n; cin>>n;
  char ch = 'A';

  for(int i=0;i<n; i++){
    // PRINT SPACES
    for(int j=0;j<i;j++){
      cout<<" ";
    }
    // PRINT CHARACTORS
    for(int k=i;k<n;k++){
      cout<<ch;
    }
    ch++;
    cout<<"\n";
  }

  return 0;
}