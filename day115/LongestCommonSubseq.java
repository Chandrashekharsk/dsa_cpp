// 1143. Longest Common Subsequence

public class LongestCommonSubseq {
  private int helper(int i, int j, String text1, String text2){
    if(i==text1.length() || j==text2.length()) return 0;
    if(dp[i][j] != null) return dp[i][j];
    
    int cnt = 0;
    if(text1.charAt(i) == text2.charAt(j)){
      cnt = 1 + helper(i+1, j+1, text1, text2);
    }else cnt = Math.max(helper(i+1, j, text1, text2), helper(i, j+1, text1, text2));
    return dp[i][j] = cnt;
  }
  private Integer[][] dp;
  public int longestCommonSubsequence(String text1, String text2) {
    dp = new Integer[text1.length()][text2.length()];
    return helper(0, 0, text1, text2);
  }

  public int longestCommonSubsequence2(String text1, String text2) {
    int[][] dp = new int[text1.length()+1][text2.length()+1];
    int m = text1.length(), n = text2.length();
    
    for(int i=m-1; i>=0; --i){
      for(int j=n-1; j>=0; --j){
        int cnt = 0;
        if(text1.charAt(i)== text2.charAt(j)){
          cnt = 1+ dp[i+1][j+1];
        }else cnt = Math.max(dp[i+1][j], dp[i][j+1]);

        dp[i][j] = cnt;
      }
    }
    return dp[0][0];
  }

  public int longestCommonSubsequence3(String text1, String text2) {
    int m = text1.length(), n = text2.length();
    int[] curr = new int[text2.length()+1], next = new int[text2.length()+1];
    
    for(int i=m-1; i>=0; --i){
      for(int j=n-1; j>=0; --j){
        int cnt = 0;
        if(text1.charAt(i) == text2.charAt(j)){
          cnt = 1+ next[j+1];
        }else cnt = Math.max(next[j], curr[j+1]);

        curr[j] = cnt;
      }
      next = curr.clone();
    }
    return next[0];
  }

  public static void main(String[] args) {
    LongestCommonSubseq lcs = new LongestCommonSubseq();
    System.out.println(lcs.longestCommonSubsequence3(new String("abc"), new String ("tb")));
  }
}
