#include <limits.h>  // For INT_MAX
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void shortest_dist(vector<vector<int>>& matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == -1)
        matrix[i][j] = INT_MAX / 2;  // Using INT_MAX/2 to prevent overflow
    }
  }

  // Floyd-Warshall Algorithm
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] > matrix[i][k] + matrix[k][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }

  // detect negative cycle exists
  for (int k = 0; k < n; ++k) {
    if(matrix[k][k] < 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][k] != INT_MAX / 2 && matrix[k][j] != INT_MAX / 2) {
            matrix[i][j] = -2;  // (-2 or "NEG")
          }
        }
      }
  }
  }

  // Convert large values back to -1 (indicating no path)
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == INT_MAX / 2) matrix[i][j] = -1;
    }
  }
}

void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int val : row) {
      if (val == -1)
        cout << "INF ";
      else
        cout << val << " ";
    }
    cout << endl;
  }
}

int main() {
  // ✅ Test Case 1: Basic Graph
  vector<vector<int>> graph1 = {
      {0, 3, -1, 7}, {8, 0, 2, -1}, {5, -1, 0, 1}, {2, -1, -1, 0}};
  cout << "Test Case 1: \n";
  shortest_dist(graph1);
  printMatrix(graph1);

  // ✅ Test Case 2: Graph with No Direct Paths
  vector<vector<int>> graph2 = {{0, -1, 4}, {-1, 0, -1}, {4, -1, 0}};
  cout << "\nTest Case 2: \n";
  shortest_dist(graph2);
  printMatrix(graph2);

  // ✅ Test Case 3: Complete Graph
  vector<vector<int>> graph3 = {{0, 1, 2}, {1, 0, 3}, {2, 3, 0}};
  cout << "\nTest Case 3: \n";
  shortest_dist(graph3);
  printMatrix(graph3);

  // ✅ Test Case 4: Single Node Graph
  vector<vector<int>> graph4 = {{0}};
  cout << "\nTest Case 4: \n";
  shortest_dist(graph4);
  printMatrix(graph4);

  return 0;
}
