// *------*
// **----**
// ***--***
// ********
// ********
// ***--***
// **----**
// *------*

#include<iostream>
using namespace std;

int main(){

  cout<<"Enter number of rows: ";
  int n; cin>>n;

  for(int i=0; i<n; i++){
    // II quadrant
    for(int j=0; j<i+1;j++){
      cout<<"*";
    }
    
    for(int j=n-i-1; j>0; j--){
      cout<<" ";
    }
    // I quadrant
    for(int j=0; j<n-i-1; j++){
      cout<<" ";
    }
    for(int j=0; j<i+1;j++){
      cout<<"*";
    }
    cout<< "\n";
  }
  for(int i=0;i<n; i++){
    for(int j=n; j>i;j--){
      cout<<"*";
    }

    for(int j=0; j<i; j++){
      cout<<" ";
    }
    for(int j=0; j<i; j++ ){
      cout<<" ";
    }
     for(int j=n; j>i;j--){
      cout<<"*";
    }
    

    cout<<"\n";
  }

  return 0;
}