#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
  int V;                    // Number of vertices
  vector<vector<int>> adj;  // Adjacency list

 public:
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // For undirected graph
  }

  void bfs(int start) {
    vector<bool> visited(V, false);  // Track visited nodes
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      cout << node << " ";  // Process node

      for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
          visited[neighbour] = true;
          q.push(neighbour);
        }
      }
    }
  }
};

int main() {

//     0
//    / \
//   1   2
//  / \ / 
// 3   4
//  \  /
//   5
  Graph g(6);  // Graph with 6 nodes (0 to 5)
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);

  cout << "BFS Traversal starting from node 0: ";
  g.bfs(0);

  return 0;
}
