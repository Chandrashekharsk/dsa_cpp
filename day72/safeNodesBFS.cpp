#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> safeNodeBFS(int V, vector<vector<int>>& adj) {
  vector<vector<int>> revAdj(V);
  vector<int> indegree(V, 0);
  vector<int> ans;
  queue<int> q;

  for (int i = 0; i < V; ++i) {
    for (auto& j : adj[i]) {
      revAdj[j].push_back(i);
      ++indegree[i];
    }
  };

  for (int i = 0; i < V; ++i) {
    if (!indegree[i]) q.push(i);
  };
  while (!q.empty()) {
    int curr = q.front();
    ans.push_back(curr);
    q.pop();

    for (auto& r : revAdj[curr]) {
      --indegree[r];
      if (!indegree[r]) q.push(r);
    }
  };

  // return (ans.size()==V)? ans :vector<int>();
  sort(ans.begin(), ans.end());
  return ans;
}

void printVector(const vector<int>& vec) {
  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  vector<vector<int>> adj1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  vector<int> result1 = safeNodeBFS(7, adj1);
  cout << "Safe nodes for graph 1: ";
  printVector(result1);

  vector<vector<int>> adj2 = {{1, 2, 3, 4}, {2, 3}, {3}, {4}, {}};
  vector<int> result2 = safeNodeBFS(5, adj2);
  cout << "Safe nodes for graph 2: ";
  printVector(result2);

  vector<vector<int>> adj3 = {{}, {0, 2, 3, 4}, {3}, {4}, {}};
  vector<int> result3 = safeNodeBFS(5, adj3);
  cout << "Safe nodes for graph 3: ";
  printVector(result3);

  return 0;
}