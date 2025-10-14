// 115. Distinct Subsequences
public class DistinctSubseq {
  private int helper(int i, int j, String s, String t){
    if(j==t.length()) return 1;
    if(i==s.length()) return 0;
    if(dp[i][j] != null) return dp[i][j];

    int cnt = 0;
    if(s.charAt(i) == t.charAt(j)) cnt =  helper(i+1, j+1, s, t) + helper(i+1, j, s, t);
    else cnt = helper(i+1, j, s, t);
    return dp[i][j] = cnt;
  }
  Integer[][] dp;
  public int numDistinct(String s, String t) {
    dp = new Integer[s.length()][t.length()];
    return helper(0, 0, s, t);
  }

  public int numDistinct2(String s, String t) {
    int m = s.length(), n = t.length();
    int[][] dp = new int[m+1][n+1];
    for(int i=0; i<n; ++i) dp[i][0] = 1;

    for(int i=1; i<=m; ++i){
      for(int j=1; j<=n; ++j){
        if(s.charAt(i-1) == t.charAt(j-1)) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        else dp[i][j] = dp[i-1][j];
      }
    }
    return dp[m][n];
  }
  public int numDistinct3(String s, String t) {
    int m = s.length(), n = t.length();
    int[] prev = new int[n+1], curr = new int[n+1];
    prev[0] = 1;
    for(int i=1; i<=m; ++i){
      for(int j=1; j<=n; ++j){
        if(s.charAt(i-1) == t.charAt(j-1)) curr[j] = prev[j-1] + prev[j];
        else curr[j] = prev[j];
      }
      prev = curr.clone();
    }
    return prev[n];
  }
  public int numDistinct4(String s, String t) {
    int m = s.length(), n = t.length();
    int[] curr = new int[n+1];
    curr[0] = 1;
    for(int i=1; i<=m; ++i){
      for(int j=n; j>=1; --j){
        if(s.charAt(i-1) == t.charAt(j-1)) curr[j] += curr[j-1];
      }
    }
    return curr[n];
  }

  public static void main(String[] args) {
    DistinctSubseq ds = new DistinctSubseq();
    System.out.println(ds.numDistinct4("rabbbit", "rabbit"));
  }
}
