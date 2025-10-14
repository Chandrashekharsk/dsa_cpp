// 10. Regular Expression Matching

public class RegularExpMathing {
  public boolean helper(int i, int j, String s, String p){
    if(i>=s.length() && j>=p.length()) return true;
    if(j>=p.length()) return false;
    if(dp[i][j]!= null) return dp[i][j];

    boolean isMatch =(i<s.length() && s.charAt(i) == p.charAt(j))  ||  p.charAt(j)=='.';
    
    boolean ans;
    if(j+1<p.length() && p.charAt(j+1)=='*'){
      // skip star & it's preceding char
      // use '*' to match one more char (if possible)
      ans = helper(i, j + 2, s, p) || isMatch && helper(i + 1, j, s, p);
    }else ans = isMatch && helper(i+1, j+1, s, p);
    return dp[i][j] = ans;
  }
  private Boolean[][] dp;
  public boolean isMatch(String s, String p) {
    dp = new Boolean[s.length() + 1][p.length()+1];
    return helper(0, 0, s, p);
  }
  
  public boolean isMatch2(String s, String p) {
    boolean[][] dp = new boolean[s.length() + 1][p.length()+1];
    int m = s.length(), n = p.length();
    dp[m][n] = true;
    
    for(int i=m; i>=0; --i){
      for(int j=n-1; j>=0; --j){
        boolean isMatch = (i < m && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.'));
        boolean ans;
        if(j+1<n && p.charAt(j+1)== '*'){
          ans = dp[i][j+2] || isMatch && dp[i+1][j];
        }else ans = isMatch && dp[i+1][j+1];
        dp[i][j] = ans;
      }
    }
    return dp[0][0];
  }




  public static void main(String[] args) {
    String s = "aa", p="a*";
    RegularExpMathing re = new RegularExpMathing();

    System.out.println(re.isMatch2(s, p));
  }
}

