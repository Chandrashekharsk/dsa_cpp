// 509. Fibonacci Number
// First 8 terms = 0, 1, 1, 2, 3, 5, 8, 13
import java.util.Arrays;

public class Fibonacci{
  private int[] dp;

  // using recursion
  public int fibSeq(int term){
    if(term<=1) return term;
    return fibSeq(term-2) + fibSeq(term-1);
  }

  public int helper(int term){
    if(dp[term] != -1) return dp[term];
    return dp[term] = helper(term-2) + helper(term-1);
  }
  // using memoization (top-down approach)
  public int fibSeq2(int term){
    dp = new int[term+1];
    Arrays.fill(dp, -1);
    dp[0] = 0;
    dp[1] = 1;
    if(term<=1) return dp[term];
    return helper(term);
  }
  
  // using tabulation (bottom-up approach)
  public int fibSeq3(int term){
    if(term<=1) return term;
    dp = new int[term+1];
    Arrays.fill(dp, -1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=term; ++i) dp[i] = dp[i-1] + dp[i-2];
    return dp[term];
  }
  
  // using optimize tabulation (bottom-up approach)
  public int fibSeq4(int term){
    if(term<=1) return term;
    int prev2 = 0, prev1 = 1;
    
    for(int i=2; i<=term; ++i){
      int curr = prev1 + prev2;
      
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
  

  public static void main(String[] args) {
    Fibonacci solver = new Fibonacci();
    int n = 7;
    System.out.println("Fibonacci(" + n + ") = " + solver.fibSeq4(n));
  }
}