#include<iostream>
#include<vector>
using namespace std;

class DistjointSet{
  vector<int> rank;
  vector<int> parent;

  public:
  DistjointSet(int n){
    rank.resize(n+1, 0);
    parent.resize(n+1, 0);

    for(int i=0; i<n+1; ++i){
      parent[i] = i;
    }
  }

  int findParent(int x){
    if(parent[x] == x) return x;
    // path compression
    return parent[x] = findParent(parent[x]);
  }

  void unionByRank(int u, int v){
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);
    if(ulp_u == ulp_v) return;

    int u_rank = rank[ulp_u];
    int v_rank = rank[ulp_v];

    if(u_rank<v_rank){
      parent[ulp_u] = ulp_v;
    }else if(u_rank>v_rank){
      parent[ulp_v] = ulp_u;
    }else {
      parent[ulp_v] = ulp_u;
      ++rank[ulp_u];
    }
  }
};


int main(){
  DistjointSet ds(7);
  ds.unionByRank(1,2);
  ds.unionByRank(2,3);
  ds.unionByRank(4,5);
  ds.unionByRank(6,7);
  ds.unionByRank(5,6);
  
  cout<<ds.findParent(3)<<"\n";
  cout<<ds.findParent(7)<<"\n";
  ds.unionByRank(3,7);
  cout<<ds.findParent(3)<<"\n";
  cout<<ds.findParent(7)<<"\n";

  return 0;
}