#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int& timer, int parent, vector<int>& vis, vector<int>& mark,
         vector<int>& steps, vector<int>& low, vector<vector<int>>& adj) {
  vis[node] = 1;
  steps[node] = low[node] = timer++;
  int child = 0;

  for (auto& it : adj[node]) {
    if (it == parent) continue;
    if (!vis[it]) {
      ++child;
      dfs(it, timer, node, vis, mark, steps, low, adj);
      low[node] = min(low[node], low[it]);

      if (low[it] >= steps[node] && parent != -1) {
        mark[node] = 1;
      }
    } else {
      low[node] = min(low[node], steps[it]);
    }
  }

  if (child > 1 && parent == -1) {
    mark[node] = 1;
  }
}

vector<int> articulationPoints(int n, vector<vector<int>>& adj) {
  vector<int> vis(n, 0);
  vector<int> mark(n, 0);
  vector<int> steps(n, 0);
  vector<int> low(n, 0);
  int timer = 1;

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i, timer, -1, vis, mark, steps, low, adj);
    }
  }

  vector<int> result;
  for (int i = 0; i < n; ++i) {
    if (mark[i] == 1) result.push_back(i);
  }
  
  return result.empty() ? vector<int>{-1} : result;
}

int main() {
  int n = 5;
  vector<vector<int>> adj(n);
  
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[1].push_back(3);
  adj[3].push_back(1);
  adj[3].push_back(4);
  adj[4].push_back(3);

  vector<int> result = articulationPoints(n, adj);

  cout << "Articulation points in the graph:" << endl;
  for (int point : result) {
    cout << point << " ";
  }
  cout << endl;

  return 0;
}
