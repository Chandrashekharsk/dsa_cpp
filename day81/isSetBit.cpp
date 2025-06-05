#include<iostream>
#include<vector>
using namespace std;

bool isSetBit(int num, int pos){
  return num & (1<<pos);
} 

int main(){
  cout<< isSetBit(13, 1)<<" \n";
  cout<< isSetBit(13, 0)<<" \n";
  


  return 0;
}