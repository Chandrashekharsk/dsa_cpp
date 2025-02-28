#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> bfsOfGraph(int n, vector<vector<int>>& edges) {
  vector<int> ans;
  vector<vector<int>> adj(n);
  for (const auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);  // remove it in case of directed graph
  }

  vector<int> vis(n, 0);
  queue<int> q;

  q.push(0);
  vis[0] = 1;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    ans.push_back(curr);
    for (int neighbour : adj[curr]) {
      if (!vis[neighbour]) {
        vis[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }
  return ans;
}
vector<int> bfsOfGraph2(int n, vector<vector<int>>& edges) {
  vector<int> ans;
  vector<vector<int>> adj(n);
  for(int i=0; i<edges.size(); ++i){
    auto curr = edges[i];
    adj[curr[0]].push_back(curr[1]);
    adj[curr[1]].push_back(curr[0]);
  }
  
  queue<int> q;
  vector<int> vis(n, 0);
  q.push(0);
  vis[0] = 1;
  while(!q.empty()){
    int curr = q.front();
    ans.push_back(curr);
    q.pop();
    for(int neighbour: adj[curr]){
      if(!vis[neighbour]){
        vis[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }
  return ans;
}

int main() {
  int n = 6, m = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4},{2, 4}, {3, 5}, {4, 5}};

  vector<int> result = bfsOfGraph(n, edges);
  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}