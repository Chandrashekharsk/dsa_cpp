// 200. Number of Islands
public class NumIslands {
  private static int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  private void dfs(int r, int c, int m, int n, char[][] grid){
    if(grid[r][c] == '0') return;
    grid[r][c] = '0';
    for(int[] d : dirs){
      int nr = r+d[0], nc = c+d[1];
      if(nr>=0 && nc >=0 && nr<m && nc<n) dfs(nr, nc, m, n, grid);
    }
  }
  public int numIslands(char[][] grid) {
    int m = grid.length, n = grid[0].length;

    int cnt = 0;
    for(int i=0; i<m; ++i){
      for(int j=0; j<n; ++j){
        if(grid[i][j] == '1'){
          ++cnt;
          dfs(i, j, m, n, grid);
        }
      }
    }
    return cnt;
  }

  public static void main(String[] args) {
    NumIslands ni = new NumIslands();

    char[][] grid = {
      {'1','1','0','0','0'},
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}
    };

    System.out.println("Number of islands = " + ni.numIslands(grid));
  }
}
