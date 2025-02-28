#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  // IN CASE OF MATRIX
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));  // Initialize adjacency matrix with 0s
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;  // remove it in case of directed graph
  }

  // IN CASE OF LIST
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);  // Initialize adjacency list as a vector of vectors
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // remove it in case of directed graph
  }

  return 0;
}
