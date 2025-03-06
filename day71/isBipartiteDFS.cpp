// 785. Is Graph Bipartite?
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, vector<vector<int>>& graph, vector<int>& color){

  for(auto& neighbour: graph[i]){
      if(color[neighbour]==-1){
          color[neighbour] = !color[i];
          if(!dfs(neighbour, graph, color)) return false;
      }else if(color[neighbour] == color[i]) return false;
  }
  return true;
};

bool checkBipartite(vector<vector<int>>& graph) {
  int V = graph.size();
  vector<int> color(V, -1);

  for(int i=0; i<V; ++i){
      if(color[i] == -1){
          color[i] = 0;
          if(!dfs(i, graph, color)) return false;
      }
  }        
  return true;
}

int main() {
  vector<vector<int>> adj1 = {
      {1, 3},  // 0 - 1, 0 - 3
      {0, 2},  // 1 - 0, 1 - 2
      {1, 3},  // 2 - 1, 2 - 3
      {0, 2}   // 3 - 0, 3 - 2
  };

  cout << (checkBipartite(adj1) ? "Bipartite" : "Not Bipartite") << endl;

  vector<vector<int>> adj2 = {
      {1, 2, 3},  // 0 - 1, 0 - 2, 0 - 3
      {0, 2},     // 1 - 0, 1 - 2
      {0, 1},     // 2 - 0, 2 - 1
      {0}         // 3 - 0
  };

  cout << (checkBipartite(adj2) ? "Bipartite" : "Not Bipartite") << endl;

  return 0;
}
