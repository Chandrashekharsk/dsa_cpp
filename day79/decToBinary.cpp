#include<iostream>
#include<vector>
#include<string>
using namespace std;


string decToBinary(int n){
  string binary = "";
  while(n>1){
    if(n%2) binary = '1' + binary;
    else binary = '0' + binary;
    n /= 2;
  }

  return '1' + binary;
}

int binaryToDec(string binary){
  int decimal = 0;
  int n = binary.size();
  for(int i = n-1; i>=0; --i){
    decimal |= ((binary[i]-'0')<<(n-1-i));
  }
  return decimal;
}

int main(){
  cout<<decToBinary(5)<<'\n'; // 101
  cout<<binaryToDec("101")<<'\n'; // 5
  cout<<binaryToDec("1010")<<'\n'; // 
  


  return 0;
}