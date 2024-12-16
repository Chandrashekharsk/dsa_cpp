// These are used to count set bits in any number
// __builtin_popcount - int
// __builtin_popcountl -  long int
// __builtin_popcount - long long int
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
  int n = 8;
  long int n2 = 8;
  long long int n3 = 8;
  cout<< __builtin_popcount(n) <<"\n";
  cout<< __builtin_popcount(n2)<<"\n";
  cout<< __builtin_popcount(n3)<<"\n";

  return 0;
}