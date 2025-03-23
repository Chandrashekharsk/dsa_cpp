#include<iostream>
#include<vector>
using namespace std;


class DistjointSet {
  vector<int> size;
  vector<int> parent;

 public:
  DistjointSet(int n) {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) parent[i] = i;
  }

  int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
  }
  void unionBySize(int u, int v) {
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    int u_size = size[ulp_u];
    int v_size = size[ulp_v];

    if (u_size < v_size) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else if (u_size > v_size) {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    } else {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
  }
};

int numberOfProvinces(vector<vector<int>>& adj, int V){
  DistjointSet ds(V);
  int cntProvinces = 0;

  for(int i=0; i<V; ++i){
    for(int j=0; j<V; ++j){
      if(adj[i][j] == 1){
        if(ds.findParent(i) != ds.findParent(j)){
          ++cntProvinces;
          ds.unionBySize(i, j);
        }
      }
    }
  }

  return cntProvinces;
}

int main(){

  


  return 0;
}