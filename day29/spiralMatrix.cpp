// 54. Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

vector<int> printSpiralMat(vector<vector<int>> mat, int m, int n) {
  vector<int> ans;
  int srow=0, erow=mat.size() - 1, scol=0, ecol=mat[0].size() - 1;

  while (srow <= erow && scol <= ecol) {
    // top
    for (int i = scol; i <= ecol; i++) {
      ans.push_back(mat[srow][i]);
    }
    // right
    for (int i = srow + 1; i <= erow; i++) {
      ans.push_back(mat[i][ecol]);
    }
    // bottom
    for (int i = ecol - 1; i >= scol; i--) {
      if(srow == erow) break;
      ans.push_back(mat[erow][i]);
    }
    // left
    for (int i = erow - 1; i > srow; i--) {
      if(scol == ecol) break;
      ans.push_back(mat[i][scol]);
    }
    srow++;
    scol++;
    erow--;
    ecol--;
  }
  return ans;
}

int main() {
  vector<vector<int>> mat = {
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}
  };

  int m = mat.size();     // Number of rows
  int n = mat[0].size();  // Number of columns

  vector<int> spiral = printSpiralMat(mat, m, n);

  // Print the result
  for (int num : spiral) {
    cout << num << " ";
  }
  return 0;
}