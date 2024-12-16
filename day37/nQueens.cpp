#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> board, int r, int size, int c){
  for(int i=0; i<size; i++){
    if(board[i][c] == 'Q') return false;
  }
  for(int j=0; j<size; j++){
    if(board[r][j] == 'Q') return false;
  }

  for(int i=r,j=c; i>=0 && j<size; i--, j++){
    if(board[i][j]=='Q')return false;
  }
  for(int i=r,j=c; i>=0 && j>=0; i--, j--){
    if(board[i][j]=='Q')return false;
  }
  return true;
}

void helper(vector<string>& board, vector<vector<string>>& ans, int r, int size){
  if(r == size){
    ans.push_back(board);
  }

  for(int j=0; j<size; j++){
    if(isSafe(board, r, size, j)){
      board[r][j] = 'Q';
      helper(board, ans, r+1, size);
      board[r][j] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));
  helper(board, ans, 0, n);
  return ans;
}

int main(){

int n = 4;
for(auto i: solveNQueens(n)){
  for(auto j: i){
    cout<< j<<" ";
  }
  cout<<endl;
};


  return 0;
}