#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void helper(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
  if(vis[i] == 1) return;
  ans.push_back(i);
  vis[i] = 1;
  for(const auto& neighbour: adj[i]){
    if(!vis[neighbour]) helper(neighbour, adj, vis, ans);
  }
};

vector<int> dfsOfGraph(int n, vector<vector<int>>& edges){
  vector<int> ans;
  vector<vector<int>> adj(n);

  for(const auto& edge: edges){
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  };

  vector<int> vis(n, 0);
  helper(0, adj, vis, ans);
  return ans;
}

int main(){
//     0
//    / \
//   1   2
//  / \   \
// 3   4 - 5
// !-------!
  int n = 6, m = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4},{2, 4}, {3, 5}, {4, 5}};

  vector<int> result = dfsOfGraph(n, edges);
  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;


  return 0;
}