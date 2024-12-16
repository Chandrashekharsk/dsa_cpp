#include<iostream>
#include<vector>
using namespace std;

int findFibonacci(int n){
  if(n<2) return n;
  return findFibonacci(n-1) + findFibonacci(n-2);
}

// using memoization
int findFibonacci2(int n, vector<int> memo){
  if(n<2) return n;
  if(memo[n] != -1) return memo[n];

  return memo[n] = findFibonacci(n-1) + findFibonacci(n-2);
} 

// using Tabulation
int findFibonacci3(int n){
  vector<int> memo(n+1, -1);
  memo[0] = 0; memo[1] = 1;
  
  for(int i=2; i<=n; i++){
    memo[i] = memo[i-1] + memo[i-2];
  }
  return memo[n];
} 

// using Optimized Tabulation
int findFibonacci4(int n){
  if(n==0) return 0;
  int prev2 = 0, prev = 1;
  
  for(int i=2; i<=n; i++){
    int curr = prev + prev2;
    prev2 = prev;
    prev = curr;
  }
  return prev;
} 

int main(){
  // 1 1 2 3 5 8 13...
  int n = 6;

  cout<< findFibonacci(n)<<"\n";

  vector<int> memo(n+1, -1);
  cout<< findFibonacci2(n, memo)<<"\n";

  cout<< findFibonacci3(n)<<"\n"; 

  cout<< findFibonacci4(n)<<"\n"; 

  return 0;
}