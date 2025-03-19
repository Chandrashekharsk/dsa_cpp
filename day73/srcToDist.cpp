#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findDistance(vector<vector<int>>& grid, pair<int,int> src, pair<int,int> dest){
  int n = grid.size(), m = grid[0].size();
  queue<pair<int,pair<int,int>>> q;
  vector<vector<int>> dist(n, vector<int>(m, 1e9));

  q.push({0, src});
  dist[0][0] = 0;

  int delRow[] = {-1,1,0,0};
  int delCol[] = {0,0,-1,1};

  while(!q.empty()){
    auto curr = q.front();
    int currDist = curr.first;
    int currR = curr.second.first;
    int currC = curr.second.second;

    for(int d=0; d<4; ++d){
      int nRow = currR + delRow[d];
      int nCol = currC + delCol[d];
      if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && grid[nRow][nCol]==1 && dist[nRow][nCol]> 1+currDist){
        dist[nRow][nCol] = 1+currDist;
        q.push({1+currDist, {nRow, nCol}});
      }
    }
  }
  
  if(dist[dest.first][dest.second] == 1e9) return -1;
  return dist[dest.first][dest.second];
}

int main(){

  


  return 0;
}