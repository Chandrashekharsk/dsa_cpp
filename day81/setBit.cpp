#include<iostream>
#include<vector>
using namespace std;

int setBitAtPos(int num, int pos){
  return num | (1<<pos);
}

int main(){
  cout<<setBitAtPos(13, 1)<<endl;

  return 0;
}