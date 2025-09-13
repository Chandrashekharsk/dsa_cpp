// 417. Pacific Atlantic Water Flow
import java.util.ArrayList;
import java.util.List;

public class OceanWaterReach {
  private void dfs(int r, int c, int m, int n, boolean[][] reachable, int[][] heights){
    if(reachable[r][c]) return;
    reachable[r][c] = true;

    int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int[] d : dirs){
      int nr = r + d[0], nc = c + d[1];
      if(nr>=0 && nc>=0 && nr<m && nc<n && heights[nr][nc]>= heights[r][c]){
        dfs(nr, nc, m, n, reachable, heights);
      }
    }
  }
  public List<List<Integer>> pacificAtlantic(int[][] heights) {
    int m = heights.length, n = heights[0].length;
    boolean[][] pacificReachable = new boolean[m][n], atlanticReachable = new boolean[m][n];

    for(int i=0; i<n; ++i ){
      dfs(0, i, m, n, pacificReachable, heights);  // first row - pacific ocean
      dfs(m-1, i, m, n, atlanticReachable, heights); // last row - atlantic ocean
    }
    for(int i=0; i<m; ++i ){
      dfs(i, 0, m, n, pacificReachable, heights);  // first col - pacific ocean
      dfs(i, n-1, m, n, atlanticReachable, heights); // last col - atlantic ocean
    }

    List<List<Integer>> ans = new ArrayList<>();
    for(int i=0; i<m; ++i){
      for(int j=0; j<n; ++j){
        if(pacificReachable[i][j] && atlanticReachable[i][j]) ans.add(List.of(i, j));
      }
    }
    return ans;
  }

  public static void main(String[] args) {
    OceanWaterReach solver = new OceanWaterReach();

    int[][] heights = {
      {1, 2, 2, 3, 5},
      {3, 2, 3, 4, 4},
      {2, 4, 5, 3, 1},
      {6, 7, 1, 4, 5},
      {5, 1, 1, 2, 4}
    };

    List<List<Integer>> res = solver.pacificAtlantic(heights);
    System.out.println("Cells where water can flow to both oceans:");
    for (List<Integer> cell : res) {
      System.out.print(cell+" ");
    }
  }
}
