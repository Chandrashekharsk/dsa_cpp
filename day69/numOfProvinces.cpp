#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void dfs(int i, vector<vector<int>>& adj, vector<int>& vis){

  vis[i] = 1;
  for(int neighbour: adj[i]){
    if(!vis[neighbour]) dfs(neighbour, adj, vis);
  }
};

int numberOfProvinces(int v, vector<vector<int>>& adj){
  vector<int> vis(v, 0);
  int provinces = 0;

  for(int i=0; i<v; ++i){
    if(!vis[i]){
      ++provinces;
      dfs(i, adj, vis);
    }
  }
  return provinces;
}

int main(){
  // 0 -- 1 -- 3
  // |    |    |
  // 2 -- 4 -- 5     6 -- 7    8 -- 9
  int v = 9+1;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5}, {6, 7}, {8, 9}};
  vector<vector<int>> adj(v);

  for(auto& edge: edges){
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  cout<<numberOfProvinces(v, adj);


  return 0;
}