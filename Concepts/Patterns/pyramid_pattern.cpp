// ___1____ 
// __121___ 
// _12321__
// 1234321_

#include<iostream>
using namespace std;

int main(){

  cout <<"Enter number of rows: ";
  int n;cin>>n;

  // for(int i=0; i<4; i++){
  //   // 1-HALF
  //   for(int j=n; j>i+1; j--){
  //     cout<<"_";
  //   }

  //   for(int k=0; k<i+1; k++){
  //     cout<<k+1;
  //   }

  //   // 2-HALF
  //   for(int l=i; l>0; l--){ 
  //     cout<<l;
  //   }
  //   for(int m=i; m<n;m++){
  //     cout<<"_";
  //   }
  //   cout<<"\n";
  // }

  for(int i=0; i<n; i++){
    // SPACES
    for(int j=0;j<n-i-1;j++){
      cout<<" ";
    }
    // NUMBERS1
    for(int k=0; k<i+1; k++){
      cout<<k+1;
    }
    // NUMBERS2
    for(int l=i;l>0;l--){
      cout<< l;
    }
    cout<<"\n";
  }


  return 0;
}
