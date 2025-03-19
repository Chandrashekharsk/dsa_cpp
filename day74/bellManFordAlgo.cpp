#include <iostream>
#include <vector>

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
  vector<int> dist(V, 1e8);
  dist[S] = 0;  

  for (int i = 0; i < V - 1; ++i) {
    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int w = edge[2];

      if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  // Detect negative weight cycle
  for (auto& edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];

    if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
      return {-1};  // Negative cycle detected
    }
  }

  return dist;
}

int main() {
  // Test Case 1: Basic Graph
  vector<vector<int>> edges1 = {
      {0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
  vector<int> res1 = bellmanFord(4, edges1, 0);
  cout << "Test Case 1: ";
  for (int d : res1) cout << d << " ";
  cout << "(Expected: 0 3 1 4)" << endl;

  // Test Case 2: Graph with a negative edge
  vector<vector<int>> edges2 = {
      {0, 1, 4}, {0, 2, 1}, {2, 1, -2}, {1, 3, 1}, {2, 3, 5}};
  vector<int> res2 = bellmanFord(4, edges2, 0);
  cout << "Test Case 2: ";
  for (int d : res2) cout << d << " ";
  cout << "(Expected: 0 -1 1 3)" << endl;

  // Test Case 3: Graph with a negative cycle
  vector<vector<int>> edges3 = {{0, 1, 1}, {1, 2, -1}, {2, 0, -1}};
  vector<int> res3 = bellmanFord(3, edges3, 0);
  cout << "Test Case 3: ";
  cout << (res3 == vector<int>{-1}
               ? "-1 (Expected: -1, Negative Cycle Detected)"
               : "Wrong Output")
       << endl;

  // Test Case 4: Graph with disconnected nodes
  vector<vector<int>> edges4 = {{0, 1, 2}, {1, 2, 3}};
  vector<int> res4 = bellmanFord(4, edges4, 0);
  cout << "Test Case 4: ";
  for (int d : res4) cout << d << " ";
  cout << "(Expected: 0 2 5 INF)" << endl;

  return 0;
}
