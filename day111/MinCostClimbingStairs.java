// 746. Min Cost Climbing Stairs

import java.util.Arrays;

public class MinCostClimbingStairs {
  private int helper(int[] cost, int i){
    if(i==1 || i==0)return cost[i];
    if(i == cost.length) return Math.min(helper(cost, i-1), helper(cost, i-2)); // top
    return cost[i] + Math.min(helper(cost, i-1), helper(cost, i-2));
  }
  public int minCostClimbingStairs(int[] cost) {
    int n = cost.length;
    return helper(cost, n);
  }


  private int helper2(int[] cost, int i, int[] dp){
    if(i==1 || i==0)return cost[i];
    if(dp[i] != -1) return dp[i];

    if(i == cost.length) return dp[i] =  Math.min(helper(cost, i-1), helper(cost, i-2)); // top
    return dp[i] = cost[i] + Math.min(helper(cost, i-1), helper(cost, i-2));
  }

  public int minCostClimbingStairs2(int[] cost) {
    int n = cost.length;
    if(n<=0) return 0;
    if(n-1 == 0) return cost[0];
    if(n-1 == 1) return Math.min(cost[0], cost[1]);

    int[] dp = new int[n + 1];
    Arrays.fill(dp, -1);
    return helper2(cost, n, dp);
  }
  

  public int minCostClimbingStairs3(int[] cost) {
    int n = cost.length;
    if(n<=0) return 0;
    if(n-1 == 0) return cost[0];
    if(n-1 == 1) return Math.min(cost[0], cost[1]);

    int[] dp = new int[n + 1];
    Arrays.fill(dp, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2; i<=n; ++i){
      if(i == n) dp[i] =  Math.min(dp[i-1], dp[i-2]); 
      else dp[i] = cost[i] + Math.min(dp[i-1], dp[i-2]);
    }
    return dp[n];
  }

  public int minCostClimbingStairs4(int[] cost) {
    int n = cost.length;
    if(n<=0) return 0;
    if(n-1 == 0) return cost[0];
    if(n-1 == 1) return Math.min(cost[0], cost[1]);

    int dp2 = cost[0];
    int dp1 = cost[1];
    for(int i=2; i<=n; ++i){
      int curr;
      if(i == n) curr =  Math.min(dp1, dp2); 
      else curr = cost[i] + Math.min(dp1, dp2);

      dp2 = dp1;
      dp1 = curr;
    }
    return dp1;
  }
  

  public static void main(String[] args) {
    MinCostClimbingStairs mcs = new MinCostClimbingStairs();
    // int[] cost = {10,1,20,1};
    // int[] cost = {10,15,20};
    int[] cost = {1, 100};
    System.out.println(mcs.minCostClimbingStairs4(cost));
  }
}
