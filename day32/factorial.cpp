#include<iostream>
#include<vector>
using namespace std;

int findFactorial(int n){
  if(n<=1) return 1;
  return n* findFactorial(n-1);
}

// using memoization
int findFactorial2(int n, vector<int>& dp){
  if(n<=1) return 1;
  if(dp[n] != -1) return dp[n];

  return dp[n] = n* findFactorial2(n-1, dp);
}

// using tabulation
int findFactorial3(int n, vector<int>& dp){
  dp[1] = 1;
  for(int i=2;i<=n; i++){
    dp[i] = i * dp[i-1];
  }
  return dp[dp.size()-1];
}

// using optimized tabulation
int findFactorial4(int n){
  // if(n>20){
  //   cout<<"Integer overflow";
  //   return-1;
  // }
  
  if(n<= 1) return 1;

  int prev = 1;
  for(int i=2;i<=n; i++){
    prev = i * prev;
  }
  return prev;
}

int main(){

  // cout<< findFactorial(4);

  // int n=10;
  // vector<int> dp(n+1,-1);
  // cout<<findFactorial2(n, dp);

  // int n=10;
  // vector<int> dp(n+1,-1);
  // cout<<findFactorial3(n, dp);

  int n=10;
  cout<<findFactorial4(n);

  return 0;
}