// 329. Longest Increasing Path in a Matrix

public class LongestIncPath {
  private static int[][] dirs = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

  private int helper(int i, int j, int[][] matrix){
    if(dp[i][j]!= null) return dp[i][j];
    int maxcnt = 1;
    for(int[] d: dirs){
      int ni = i+d[0], nj = j+d[1];
      
      if(ni>=0 && nj>=0 && ni<matrix.length && nj<matrix[0].length && matrix[ni][nj]>matrix[i][j]) maxcnt = Math.max(maxcnt, 1+helper(ni, nj, matrix));
    }
    return dp[i][j] = maxcnt;
  }
  private Integer[][] dp;
  public int longestIncreasingPath(int[][] matrix) {
    int maxCnt = 0;
    dp = new Integer[matrix.length][matrix[0].length];
    for(int i=0; i<matrix.length; ++i){
      for(int j=0; j<matrix[0].length; ++j) maxCnt = Math.max(maxCnt, helper(i, j, matrix));
    }
    return maxCnt;
  }

  public static void main(String[] args) {
    LongestIncPath lip = new LongestIncPath();
    System.out.println(lip.longestIncreasingPath(new int[][]{
      {3,4,5},{3,2,6},{2,2,1}
    }));
  }
}
