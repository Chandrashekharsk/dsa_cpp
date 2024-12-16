// Is Armastrong
// eg.   153 = 1*1*1 + 5*5*5 + 3*3*3
      // 153 = 153
#include<iostream>
#include<vector>
using namespace std;

bool isArmstrong(int n){

  int sumOfCubes = 0, copyOfN = n;

  while (n!=0){
    int lastDigit = n%10;
    sumOfCubes += (lastDigit*lastDigit*lastDigit);
    n /= 10;
  }
  return copyOfN==sumOfCubes;
}

int main(){
  cout<<isArmstrong(153)<<"\n";
  cout<<isArmstrong(1)<<"\n";
  cout<<isArmstrong(345)<<"\n";
  


  return 0;
}