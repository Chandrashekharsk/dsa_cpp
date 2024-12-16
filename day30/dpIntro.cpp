// DP:  1.Memoization(top-down), 2.Tabulation(bottom-up)
#include<iostream>
#include<vector>
using namespace std;

// 1.Memoization(top-down)
int fib(int n, vector<int>& dp){
  if(n<=1) return n;
  if(dp[n] != -1) return dp[n];

  return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

// 2.Tabulation(bottom-up)
int fib2(int n, int prev, int prev2){
  for(int i=2; i<=n; i++){
    int curr = prev + prev2;
    prev2 = prev;
    prev = curr;
  }
  return prev;
}


int main(){
  int n = 5;
  // int n = 15000;
  
  vector<int> dp(n+1, -1);
  cout<< fib(n, dp)<<"\n";

  int prev = 1, prev2= 0;
  cout<< fib2(n, prev, prev2)<<"\n";


  return 0;
}