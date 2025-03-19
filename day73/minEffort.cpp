// 1631. Path With Minimum Effort
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findMinEffort(vector<vector<int>>& heights) {
  int n = heights.size(), m = heights[0].size();
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

  vector<vector<int>> diff(n, vector<int>(m, 1e9));

  pq.push({0,{0, 0}});
  diff[0][0] = 0;

  int delRow[] = {-1, 1, 0, 0};
  int delCol[] = {0, 0, -1, 1};

  while(!pq.empty()){
      auto curr = pq.top();
      pq.pop();
      int currDiff = curr.first;
      int currRow = curr.second.first;
      int currCol = curr.second.second;

      if(currRow == n-1 && currCol == m-1) return diff[currRow][currCol];
      if(currDiff> diff[currRow][currCol]) continue;

      for(int d=0; d<4; ++d){
          int nRow = currRow + delRow[d];
          int nCol = currCol + delCol[d];

          if(nRow>=0 && nCol>=0 && nRow<n && nCol<m ){
              int newEffort = max(abs(heights[currRow][currCol]-heights[nRow][nCol]), diff[currRow][currCol]);
              if(newEffort<diff[nRow][nCol]){
                  pq.push({newEffort,{nRow, nCol}});
                  diff[nRow][nCol] = newEffort;
              }
          }
      }
  }
  return 0;
}

// Test function
void testFindMinEffort(vector<vector<int>>& heights) {
  cout << "Minimum effort required: " << findMinEffort(heights) << endl;
}

int main() {
  vector<vector<int>> heights1 = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  testFindMinEffort(heights1);

  vector<vector<int>> heights2 = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
  testFindMinEffort(heights2);

  vector<vector<int>> heights3 = {{1, 2, 1, 1, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 1, 1, 2, 1}};
  testFindMinEffort(heights3);

  return 0;
}
