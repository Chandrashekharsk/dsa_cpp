// 51. N-Queens
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void helper(int r, int n, vector<string>& board, vector<vector<string>>& ans,
            unordered_set<int>& cols, unordered_set<int>& diag,
            unordered_set<int>& anti_diag) {
  if (r == n) {
    ans.push_back(board);
    return;
  }

  for (int c = 0; c < n; c++) {
    // Check if column, diagonal, or anti-diagonal is under attack
    if (cols.count(c) || diag.count(r - c) || anti_diag.count(r + c)) continue;

    // Place the queen
    board[r][c] = 'Q';
    cols.insert(c);
    diag.insert(r - c);
    anti_diag.insert(r + c);

    // Recurse to the next row
    helper(r + 1, n, board, ans, cols, diag, anti_diag);

    // Backtrack
    board[r][c] = '.';
    cols.erase(c);
    diag.erase(r - c);
    anti_diag.erase(r + c);
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));
  unordered_set<int> cols, diag, anti_diag;
  helper(0, n, board, ans, cols, diag, anti_diag);
  return ans;
}

int main() {
  int n = 4;
  vector<vector<string>> solutions = solveNQueens(n);

  for (const auto& solution : solutions) {
    for (const auto& row : solution) {
      cout << row << endl;
    }
    cout << endl;  // Separate different solutions
  }

  return 0;
}
