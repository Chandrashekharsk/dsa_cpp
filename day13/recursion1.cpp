#include<iostream>
using namespace std;

// void printName(int i, int n){
//   if(i>n) return ;
//   cout<<("palak\n");
//   printName(i+1, n);
// }
void printName(int i, int n){
  if(i>n) return ;
  printName(i+1, n);
  cout<<i<<("\n");
}

int main(){
printName(1,4);

  return 0;
}