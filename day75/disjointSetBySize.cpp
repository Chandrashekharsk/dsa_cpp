#include<iostream>
#include<vector>
using namespace std;

class DistjointSet{
  vector<int> size;
  vector<int> parent;
  public:
  DistjointSet(int n){
    size.resize(n+1, 1);
    parent.resize(n+1, 0);
    for(int i=0; i<n+1; ++i) parent[i] = i;
  }

  int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
  }

  void unionBySize(int u, int v){
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);
    if(ulp_u == ulp_v) return;

    int u_size = size[ulp_u];
    int v_size = size[ulp_v];

    if(u_size<v_size){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }else if(u_size>v_size){
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }else{
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }

};

int main(){
  DistjointSet ds(7);
  ds.unionBySize(1,2);
  ds.unionBySize(2,3);
  ds.unionBySize(4,5);
  ds.unionBySize(6,7);
  ds.unionBySize(5,6);
  
  cout<<ds.findParent(3)<<"\n";
  cout<<ds.findParent(7)<<"\n";
  ds.unionBySize(3,7);
  cout<<ds.findParent(3)<<"\n";
  cout<<ds.findParent(7)<<"\n";

  return 0;
}