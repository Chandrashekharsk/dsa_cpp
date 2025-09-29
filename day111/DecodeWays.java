// 91. Decode Ways
import java.util.Arrays;

public class DecodeWays {
  private int helper(String s, int i){
    if (i == s.length()) return 1;
    if(s.charAt(i)=='0') return 0;

    int totalWays = helper(s, i+1);  // choose one element

    if(i+1<s.length()){
      int twoDigits = Integer.parseInt(s.substring(i, i+2));  // choose two elements if valid
      if(twoDigits>=10 && twoDigits<=26) totalWays+= helper(s, i+2);
    }
    return totalWays;
  }
  public int numDecodings(String s) {
    return helper(s, 0);
  }


  private int helper2(String s, int i, int[] dp){
    if (i == s.length()) return 1;
    if(s.charAt(i)=='0') return 0;
    if(dp[i] != -1) return dp[i];

    int totalWays = helper2(s, i+1, dp);  // choose one element

    if(i+1<s.length()){
      int twoDigits = Integer.parseInt(s.substring(i, i+2));  // choose two elements if valid
      if(twoDigits>=10 && twoDigits<=26) totalWays+= helper2(s, i+2, dp);
    }
    return dp[i] = totalWays;
  }
  public int numDecodings2(String s) {
    int[]dp = new int[s.length()];
    Arrays.fill(dp, -1);
    return helper2(s, 0, dp);
  }


  public int numDecodings3(String s) {
    int n = s.length();
    int[]dp = new int[n+1];
    Arrays.fill(dp, -1);
    dp[n] = 1;  // base case
    dp[n-1]  = s.charAt(n-1)!='0'? 1:0;
    
    for(int i=n-2; i>=0; --i){
      if (s.charAt(i)=='0') dp[i] = 0;
      else { 
        dp[i] = dp[i+1];
        if(i+1<n){
          int twoDigits = Integer.parseInt(s.substring(i, i+2));  // choose two elements if valid
          if(twoDigits>=10 && twoDigits<=26) dp[i] += dp[i+2];
        }
      };
    }
    return dp[0];
  }


  public int numDecodings4(String s) {
    int n = s.length();
    int next2 = 1; // base case
    int next  = s.charAt(n-1)!='0'? 1:0;
    
    for(int i=n-2; i>=0; --i){
      int curr = 0;
      if (s.charAt(i)!='0'){
        curr = next;
        if(i+1<n){
          int twoDigits = Integer.parseInt(s.substring(i, i+2));  // choose two elements if valid
          if(twoDigits>=10 && twoDigits<=26) curr += next2;
        }
      };

      next2 = next;
      next = curr;
    }
    return next;
  }



  public static void main(String[] args) {
    DecodeWays dw = new DecodeWays();
    System.out.println(dw.numDecodings4("213"));
  }
}
