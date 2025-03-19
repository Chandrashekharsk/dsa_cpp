#include<iostream>
#include<vector>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold){
  vector<vector<int>> distMat(n, vector<int> (m, 1e9));

  for(auto& edge: edges){
    distMat[edge[0]][edge[1]] = edge[2];
    distMat[edge[1]][edge[0]] = edge[2];
  }

  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(i==j) distMat[i][j] = 0;
    }
  }

  for(int k=0; k<n; ++k){
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        if(distMat[i][k] == 1e9 && distMat[k][j] == 1e9) continue;
        distMat[i][j] = min(distMat[i][j], distMat[i][k]+ distMat[k][j]);
      }
    }
  }

  for(int k=0; k<n; ++k){
    if(distMat[k][k] < 0){
      for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
          if(distMat[i][k] != 1e9 && distMat[k][j] != 1e9){
            distMat[i][j] = -2;
          }
        }
      }
    }
  };

  int cntCity = n;
  int cityNo = -1; 

  for(int city=0; city<n; ++city){
    int cnt = 0;
    for(int neighbour=0; neighbour<n; ++neighbour){
      if(distMat[city][neighbour] <= distanceThreshold)  ++cnt;
    }
    if(cnt <= distanceThreshold){
      cntCity = cnt;
      cityNo = city;
    }
  }
  return cityNo;
}

int main(){

  


  return 0;
}