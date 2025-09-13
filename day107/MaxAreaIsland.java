// 695. Max Area of Island
import java.util.LinkedList;
import java.util.Queue;

public class MaxAreaIsland {
  // // USING DFS
  // private int dfs(int[][] grid, int r, int c, int rows, int cols){
  // if(r<0 || c<0 || r>=rows || c>=cols || grid[r][c]==0) return 0;

  // grid[r][c]=0;
  // int currArea = 1;

  // int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
  // for(int d=0; d<4; ++d){
  // int nr = r+dr[d], nc = c+dc[d];
  // currArea += dfs(grid, nr, nc, rows, cols);
  // }
  // return currArea;
  // }

  // public int maxAreaOfIsland(int[][] grid) {
  // int maxArea = 0;
  // int rows = grid.length, cols = grid[0].length;

  // for(int i=0; i<rows; ++i){
  // for(int j=0; j<cols; ++j){
  // if(grid[i][j]==1) maxArea = Math.max(maxArea, dfs(grid, i, j, rows, cols));
  // }
  // }
  // return maxArea;
  // }

  // USING BFS
  public int maxAreaOfIsland(int[][] grid) {
    int maxArea = 0;
    int rows = grid.length, cols = grid[0].length;

    int[] dr = { -1, 1, 0, 0 };
    int[] dc = { 0, 0, -1, 1 };

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {

        if (grid[i][j] == 1) {
          int area = 0;
          Queue<int[]> queue = new LinkedList<>();
          queue.add(new int[] { i, j });
          grid[i][j] = 0; 

          while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0], c = cell[1];
            area++;

            // Explore 4 directions
            for (int d = 0; d < 4; d++) {
              int nr = r + dr[d], nc = c + dc[d];
              if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1) {
                queue.add(new int[] { nr, nc });
                grid[nr][nc] = 0; // mark visited
              }
            }
          }
          maxArea = Math.max(maxArea, area);
        }
      }
    }

    return maxArea;
  }

  public static void main(String[] args) {
    MaxAreaIsland obj = new MaxAreaIsland();
    int[][] grid = {
        { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
        { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }
    };

    System.out.println("Max Area of Island: " + obj.maxAreaOfIsland(grid));
  }
}