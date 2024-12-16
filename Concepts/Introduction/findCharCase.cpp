#include<iostream>
using namespace std;

int main(){

  char c;
  cout<< "Enter charactor which you want to check: "; cin>> c;

  // if(c >= 'a' && c<= 'z'){
  //   cout<< "Lowercase";
  // }else{
  //   cout<< "Uppercase";
  // }


  // USING ASCII VALUES:
  if(c>=65 && c<=90){
    cout<<"Uppercase";
  }else if(c>=97 && c<=122){
    cout<< "Lowercase";
  }else{
    cout<<"Invalid charactor!";
  }

// for(initialization; condition; updation;){
// }
  int i=3;
  for (;i<6;i++) cout<<"\n"<<i;

  return 0;
}