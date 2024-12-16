#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int r, int c, vector<vector<char>>& board, char val){
  // check columns
  for(int j=0; j<9; j++){
    if(board[r][j] == val) return false;
  }
  // check rows 
  for(int i=0; i<9; i++){
    if(board[i][c] == val) return false;
  }
  // check grid
  int startRow = (r/3)*3;
  int startCol = (c/3)*3;
  for(int i=startRow; i<startRow+3; i++){
    for(int j=startCol; j<startCol+3; j++){
      if(board[i][j] == val) return false;
    }
  }
  return true;
}

bool helper(int r, int c, vector<vector<char>>& board) {
  // destination
  if(r==9) return true;
  // current row's end column 
  if(c==9) return helper(r+1, 0, board);

  if (board[r][c] != '.') return helper(r, c + 1, board);

  for (char i = '1'; i <= '9'; i++) {
    if (isSafe(r, c, board, i)) {
      board[r][c] = i;
      if (helper(r, c+1, board)) return true;
      board[r][c] = '.';
    }
  }
  return false;
}

void sudokuSolver(vector<vector<char>>& board) { 
  helper(0, 0, board); 
}

void printBoard(const vector<vector<char>>& board) {
  for (const auto& row : board) {
    for (const auto& cell : row) {
      cout << cell << ' ';
    }
    cout << '\n';
  }
}

int main() { 
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << "Original Board:\n";
  printBoard(board); 
  sudokuSolver(board);
  cout << "\nSolved Board:\n";
  printBoard(board);

  return 0; 
}