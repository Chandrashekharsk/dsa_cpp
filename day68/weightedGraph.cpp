#include <iostream>
#include <vector>
using namespace std;

void printAdjMatrix(const vector<vector<int>>& adjMatrix) {
  int n = adjMatrix.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << adjMatrix[i][j] << " ";
    }
    cout << endl;
  }
}

void printAdjList(const vector<vector<pair<int, int>>>& adjList) {
  int n = adjList.size();
  for (int i = 0; i < n; ++i) {
    cout << i << ": ";
    for (const auto& p : adjList[i]) {
      cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
  }
}

int main() {
  // IN CASE OF MATRIX
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;  // remove it if graph is directed
  }

  // IN CASE OF LIST
  vector<vector<pair<int, int>>> adjList(n);  // Use pair to store vertex and weight
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});  // remove it if graph is directed
  }

  cout << "Adjacency Matrix:" << endl;
  printAdjMatrix(adjMatrix);

  cout << "Adjacency List:" << endl;
  printAdjList(adjList);

  return 0;
}