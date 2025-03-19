#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
  vector<vector<pair<int, int>>> adj(n + 1);
  for (auto& edge : edges) {
    adj[edge[0]].push_back({edge[1], edge[2]});
    adj[edge[1]].push_back({edge[0], edge[2]});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
  vector<int> dist(n + 1, 1e9), parent(n + 1);
  for (int i = 0; i <= n; ++i) parent[i] = i;

  pq.push({0, 1});
  dist[1] = 0;
  parent[1] = 1;

  while (!pq.empty()) {
    auto currNode = pq.top().second;
    auto currDist = pq.top().first;
    pq.pop();

    for (auto& neighbour : adj[currNode]) {
      int neighbourNode = neighbour.first;
      int neighbourDist = neighbour.second;
      if (currDist + neighbourDist < dist[neighbourNode]) {
        dist[neighbourNode] = currDist + neighbourDist;
        pq.push({currDist + neighbourDist, neighbourNode});
        parent[neighbourNode] = currNode;
      }
    }
  }
  if (dist[n] == 1e9) return {-1};

  vector<int> path;
  int node = n;
  while (parent[node] != node) {
    path.push_back(node);
    node = parent[node];
  }

  path.push_back(1); 
  reverse(path.begin(), path.end());
  return path;
}

void runTestCases() {
  vector<vector<int>> edges;
  vector<int> result;

  // **Test Case 1: Basic Test Case**
  cout << "Test Case 1: Simple Graph\n";
  int n1 = 5, m1 = 6;
  edges = {{1, 2, 2}, {1, 3, 4}, {2, 4, 7}, {2, 5, 3}, {3, 5, 1}, {4, 5, 2}};
  result = shortestPath(n1, m1, edges);
  for (int node : result) cout << node << " ";
  cout << "\nExpected: 1 2 5\n\n";

  // **Test Case 2: No Path Exists**
  cout << "Test Case 2: No Path Exists\n";
  int n2 = 4, m2 = 2;
  edges = {
      {1, 2, 5}, {3, 4, 2}  // No connection between {1, 2} and {3, 4}
  };
  result = shortestPath(n2, m2, edges);
  for (int node : result) cout << node << " ";
  cout << "\nExpected: -1\n\n";

  // **Test Case 3: Multiple Paths, Choose the Shortest**
  cout << "Test Case 3: Multiple Paths\n";
  int n3 = 4, m3 = 4;
  edges = {{1, 2, 1}, {2, 4, 2}, {1, 3, 2}, {3, 4, 1}};
  result = shortestPath(n3, m3, edges);
  for (int node : result) cout << node << " ";
  cout << "\nExpected: 1 3 4\n\n";

  // **Test Case 4: Single Edge**
  cout << "Test Case 4: Single Edge\n";
  int n4 = 2, m4 = 1;
  edges = {{1, 2, 10}};
  result = shortestPath(n4, m4, edges);
  for (int node : result) cout << node << " ";
  cout << "\nExpected: 1 2\n\n";

  // **Test Case 5: Large Graph with Direct Connection**
  cout << "Test Case 5: Large Graph with Direct Connection\n";
  int n5 = 6, m5 = 7;
  edges = {{1, 2, 4},  {2, 3, 8}, {3, 4, 7}, {4, 5, 9},
           {5, 6, 10}, {1, 6, 1}, {2, 6, 2}};
  result = shortestPath(n5, m5, edges);
  for (int node : result) cout << node << " ";
  cout << "\nExpected: 1 6\n\n";
}

int main() {
  runTestCases();
  return 0;
}
