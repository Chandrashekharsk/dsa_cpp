// 70. Climbing Stairs

import java.util.HashMap;
import java.util.Map;

public class ClimbStairs {
  private Map<Integer, Integer> dp = new HashMap<>();

  // Recursive 
  // public int climbStairs(int n) {
  //   if(n<=1) return 1;
  //   return climbStairs(n-2) + climbStairs(n-1);
  // }

  // Memoization (Top-Down)
  // public int climbStairs(int n) {
  //   if(n<=1) return 1;
  //   if(dp.containsKey(n)) return dp.get(n);
  //   int ways = climbStairs(n-1) + climbStairs(n-2);
  //   dp.put(n, ways);
  //   return ways;
  // }

  // Tabulation (Bottom-Up)
  // public int climbStairs(int n) {
  //   int[] dp = new int[n+1];
  //   dp[0] = 1;
  //   dp[1] = 1;
  //   for(int i=2; i<=n; ++i) dp[i] = dp[i-2]+dp[i-1];
  //   return dp[n];
  // }


  // Optimized DP (Constant Space)
  public int climbStairs(int n) {
    if(n<=1) return 1;
    int dp2 = 1;
    int dp1 = 1;
    for(int i=2; i<=n; ++i){
      int curr = dp2+dp1;
      dp2 = dp1;
      dp1 = curr;
    }
    return dp1;
  }

  public static void main(String[] args) {
    ClimbStairs cs = new ClimbStairs();
    System.out.println(cs.climbStairs(3));
  }
}
