// 62. Unique Paths
import java.util.HashSet;
import java.util.Set;

public class UniquePaths {
  private Set<String> s;
  private void helper(int r, int c, int m, int n, StringBuilder curr){
    if(r==0 && c== 0){
      String str = curr.toString();
      if(!s.contains(str)) s.add(str);
      return;
    }

    if(r-1 >= 0){
      curr.append("U");
      helper(r - 1, c, m, n, curr);
      curr.deleteCharAt(curr.length() - 1); // backtrack
    }
    if(c-1>=0){
      curr.append("L");
      helper(r, c-1, m, n, curr);
      curr.deleteCharAt(curr.length() - 1); // backtrack
    }
  }
  public int uniquePaths(int m, int n) {
    s = new HashSet<>();
    helper(m-1, n-1, m, n, new StringBuilder());
    return s.size();
  }

  public int uniquePaths2(int m, int n) {
    int[][] dp  = new int[m][n];
    for(int i=0; i<m; ++i) dp[i][0] = 1; // all rows, col 0 -> true
    for(int i=0; i<n; ++i) dp[0][i] = 1; // row 0, all col -> true

    for(int i=1; i<m; ++i){
      for(int j=1; j<n; ++j){
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
    return dp[m-1][n-1];
  }

  public static void main(String[] args) {
    UniquePaths up = new UniquePaths();
    System.out.println(up.uniquePaths2(3, 7)); // Example test
  }
}
