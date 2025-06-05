#include<iostream>
#include<vector>
using namespace std;

int clearBit(int num, int pos){
  return num & (~(1<<pos));
}

int toggleBit(int num, int pos){
  return num ^ (1<<pos);
}

int removeLastSetBit(int num){
  return num & num-1;
}

bool isPowOf2(int num){
  return (( num & (num-1)) == 0);
}

// int cntSetBits(int num){
//   int cnt = 0;
//   while(num != 0){
//     if(num & 1) ++cnt;
//     num >>= 1;
//   }
//   return cnt;
// }

int cntSetBits(int num){
  int cnt = 0;
  while(num != 0){
    ++cnt;
    num &= num-1;
  }
  return cnt;
}

int main(){
  cout<<clearBit(13, 2)<<endl;
  cout<<toggleBit(13, 2)<<endl;
  cout<<toggleBit(16, 2)<<endl;
  cout<<removeLastSetBit(16)<<endl;
  cout<<isPowOf2(16)<<endl;
  cout<<isPowOf2(10)<<endl;
  cout<<cntSetBits(10)<<endl;
  cout<<cntSetBits(4)<<endl;
  cout<<cntSetBits(2)<<endl;

  return 0;
}