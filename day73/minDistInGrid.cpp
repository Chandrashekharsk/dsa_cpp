// 1091. Shortest Path in Binary Matrix
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

  priority_queue<pair<int, pair<int, int>>,vector<pair<int,pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
  vector<vector<int>> dist(n, vector<int> (m, 1e9));
  pq.push({1, {0, 0}});
  dist[0][0] = 0;

  
  int delRow[] = {-1, 1, 0, 0, 1, 1, -1,-1};
  int delCol[] = {0, 0, -1, 1, 1, -1, 1, -1};

  while(!pq.empty()){
      auto curr = pq.top();
      pq.pop();
      int cd = curr.first;
      int cr = curr.second.first;
      int cc = curr.second.second;

      if(cr==n-1 && cc == m-1) return dist[cr][cc];

      for(int d=0; d<8; ++d){
          int nRow = cr + delRow[d];
          int nCol = cc + delCol[d];
          if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && grid[nRow][nCol]==0 && 1+cd<dist[nRow][nCol]){
              pq.push({1+cd, {nRow, nCol}});
              dist[nRow][nCol] = 1+cd;
          }
      }
  }
  return -1 ;
}

int main(){

  


  return 0;
}