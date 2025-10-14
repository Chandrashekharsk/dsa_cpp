// 97. Interleaving String

public class InterleavingStr {
  private boolean helper(int i, int j, int k, String s1, String s2, String s3) {
    if (i == s1.length() && j == s2.length() && k == s3.length())
      return true;
    if (dp[i][j] != null)
      return dp[i][j];

    boolean ans = false;
    if (i < s1.length() && k < s3.length() && s3.charAt(k) == s1.charAt(i))
      ans = helper(i + 1, j, k + 1, s1, s2, s3);
    if (!ans && j < s2.length() && k < s3.length() && s3.charAt(k) == s2.charAt(j))
      ans = helper(i, j + 1, k + 1, s1, s2, s3);
    return dp[i][j] = ans;
  }

  Boolean[][] dp;

  public boolean isInterleave(String s1, String s2, String s3) {
    dp = new Boolean[s1.length() + 1][s2.length() + 1];
    if (s3.length() != s1.length() + s2.length())
      return false;
    return helper(0, 0, 0, s1, s2, s3);
  }

  public boolean isInterleave2(String s1, String s2, String s3) {
    if(s3.length() != s1.length()+s2.length())return false;

    int m = s1.length(), n = s2.length();
    boolean[][] dp = new boolean[m + 1][n + 1];
    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        int k = i + j - 1;
        if (i > 0) dp[i][j] |= dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(k);
        if (j > 0) dp[i][j] |= dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(k);
      }
    }
    return dp[m][n];
  }

  public static void main(String[] args) {
    String s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    InterleavingStr is = new InterleavingStr();
    System.out.println(is.isInterleave2(s1, s2, s3));
  }
}
