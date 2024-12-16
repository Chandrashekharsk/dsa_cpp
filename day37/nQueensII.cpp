// 52. N-Queens II
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int helper(int r, int n, unordered_set<int>& cols, unordered_set<int>& diag, unordered_set<int>& anti_diag){
  if(r== n) return 1;

  int count = 0;
  for(int c=0; c<n; c++){
    if(cols.count(c) || diag.count(r-c) || anti_diag.count(r+c)) continue;

    cols.insert(c); diag.insert(r-c); anti_diag.insert(r+c);
    count += helper(r+1, n, cols, diag, anti_diag);
    cols.erase(c); diag.erase(r-c); anti_diag.erase(r+c);
  }
  return count;
}

int solveNQueens(int n) {
  unordered_set<int> cols, diag, anti_diag;
  return helper(0, n, cols, diag, anti_diag);
}

int main(){
  int n=4;
  cout<<solveNQueens(4);

  return 0;
}