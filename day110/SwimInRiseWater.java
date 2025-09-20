// 778. Swim in Rising Water

public class SwimInRiseWater {
  private static int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  private boolean dfs(int r, int c, int[][] grid, int n, int t, boolean[][] vis){
    if(r<0 || c<0 || r>=n || c>=n || vis[r][c] || grid[r][c]>t) return false;

    if(r==n-1 && c == n-1) return true; //destination
    vis[r][c] = true;

    for(int[] dir: dirs){
      int nr = r+dir[0], nc=c+dir[1];
      if(dfs(nr, nc, grid, n, t, vis)) return true;
    }
    return false;
  }
  private boolean canSwim(int[][] grid, int t, int n){
    boolean[][] vis = new boolean[n][n];
    return dfs(0, 0, grid, n, t, vis);
  }
  public int swimInWater(int[][] grid) {
    int n = grid.length;
    int st = grid[0][0], end = n*n-1;

    while(st<end){
      int mid = st + (end-st)/2;
      if(canSwim(grid, mid, n)){
        end = mid;
      }else st = mid+1;
    }
    return st;
  }

  public static void main(String[] args) {
    SwimInRiseWater solver = new SwimInRiseWater();

    // Sample input (from LeetCode example)
    int[][] grid = {
      {0, 2},
      {1, 3}
    };
    // Expected output: 3
    int result = solver.swimInWater(grid);
    System.out.println("Minimum time to swim: " + result);
  }
}
