#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// It uses topSort(Kan's algorithm) to detect cycle
// if graph is DAG then length of topoSortedArray == V

bool detectCycle(int V, vector<vector<int>>& adj){
  vector<int>indegree(V, 0);
  queue<int> q;
  int cnt = 0;

  for(auto& vertices: adj){
    for(auto& neighbour: vertices){
      ++indegree[neighbour];
    };
  };

  for(int i=0; i<V; ++i){
    if(indegree[i]==0) q.push(i);
  }

  while(!q.empty()){
    int curr = q.front();
    q.pop();
    ++cnt;

    for(auto& neighbour: adj[curr]){
      --indegree[neighbour];
      if(indegree[neighbour] == 0) q.push(neighbour);
    };
  }
  return cnt != V;
}

int main(){
  vector<vector<int>> adj1 = {
    {1},  // 0 -> 1
    {2},  // 1 -> 2
    {3},  // 2 -> 3
    {1}   // 3 -> 1 (cycle)
};

cout << (detectCycle(4, adj1) ? "Cycle Detected" : "No Cycle") << endl;

vector<vector<int>> adj2 = {
    {1},  // 0 -> 1
    {2},  // 1 -> 2
    {3},  // 2 -> 3
    {}    // 3 has no outgoing edge (no cycle)
};

cout << (detectCycle(4, adj2) ? "Cycle Detected" : "No Cycle") << endl;

  return 0;
}