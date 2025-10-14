// 72. Edit Distance

public class EditDistance {
  private int helper(int i, int j, String w1, String w2){
    if (i == w1.length()) return w2.length() - j; // Insert remaining chars of w2
    if (j == w2.length()) return w1.length() - i; // Delete remaining chars of w1
    if(dp[i][j] != null) return dp[i][j];

    if(w1.charAt(i) == w2.charAt(j)) return dp[i][j] = helper(i+1, j+1, w1, w2); // when char matches need 0 operations
    int insert = helper(i, j + 1, w1, w2);      // Insert
    int delete = helper(i + 1, j, w1, w2);      // Delete
    int replace = helper(i + 1, j + 1, w1, w2); // Replace
    return dp[i][j] = 1 + Math.min(replace, Math.min(insert, delete));
  }

  Integer[][] dp;
  public int minDistance(String word1, String word2) {
    if(word2.length()==0) return word1.length();
    dp = new Integer[word1.length()][word2.length()];
    return helper(0, 0, word1, word2);
  }
  public int minDistance2(String word1, String word2) {
    int m= word1.length(), n = word2.length();
    if(n==0) return m;
    int[][] dp = new int[m+1][n+1];
    for(int i=0; i<=m; ++i) dp[i][0] = i;
    for(int j=0; j<=n; ++j)dp[0][j] = j;
    
    for(int i=1; i<=m; ++i){
      for(int j=1; j<=n; ++j){
        if(word1.charAt(i-1) == word2.charAt(j-1)) dp[i][j] = dp[i-1][j-1];
        else {
          int insert = dp[i][j-1];
          int delete = dp[i-1][j];
          int replace = dp[i-1][j-1];
          dp[i][j] = 1+Math.min(insert, Math.min(delete, replace));
        }
      }
    }

    return dp[m][n];
  }
  public int minDistance3(String word1, String word2) {
    int m= word1.length(), n = word2.length();
    if(n==0) return m;
    int[] prev = new int[n+1], curr = new int[n+1];
    for(int i=0; i<=n; ++i) prev[i] = i;
    
    for(int i=1; i<=m; ++i){
      curr[0] = i;
      for(int j=1; j<=n; ++j){
        if(word1.charAt(i-1) == word2.charAt(j-1)) curr[j] = prev[j-1];
        else {
          int insert = curr[j-1];
          int delete = prev[j];
          int replace = prev[j-1];
          curr[j] = 1+Math.min(insert, Math.min(delete, replace));
        }
      }
      prev = curr.clone();
    }

    return prev[n];
  }

  public static void main(String[] args) {
    String w1 = "horse", w2 = "ros";
    EditDistance obj = new EditDistance();
    System.out.println(obj.minDistance3(w1, w2));
  }
}
