// 309. Best Time to Buy and Sell Stock with Cooldown

public class BestTimeToBuyNSellCooldown{
  // recursive + memoization
  private int helper(int i, int status, int[] prices){
    if(i == prices.length) return 0;
    if(dp[i][status] != null) return dp[i][status];

    int currProfit = 0;
    if(status==0){
      int buy = -prices[i] + helper(i + 1, 1, prices);
      int skip = helper(i + 1, 0, prices);
      currProfit = Math.max(buy, skip);
    } else if(status== 1){
      int sell = prices[i] + helper(i+1, 2, prices);
      int skip = helper(i+1, status, prices);
      currProfit = Math.max(sell, skip);
    }else if(status==2) currProfit = helper(i+1, 0, prices);
    
    return dp[i][status] = currProfit;
  }
  private Integer[][] dp;
  public int maxProfit(int[] prices) {
    dp = new Integer[prices.length][3];
    return helper(0, 0,  prices);
  }
  // tabulation
  public int maxProfit2(int[] prices) {
    int n= prices.length, states = 3;
    int[][] dp = new int[n+1][states];
    for(int i=0; i<states; ++i) dp[n][i] = 0;

    for(int i=n-1; i>=0; --i){
      for(int state=0; state<states; ++state){
        int currProfit = 0;
        if(state == 0){
          int buy = -prices[i]+dp[i+1][1];
          int skip = dp[i+1][state];
          currProfit = Math.max(buy, skip);
        }else if(state == 1){
          int sell = prices[i] + dp[i+1][2];
          int skip = dp[i+1][state];
          currProfit = Math.max(sell, skip);
        }else if(state == 2) currProfit = dp[i+1][0];

        dp[i][state] = currProfit;
      }
    }
    return dp[0][0]; // start at day 0, status = not holding
  }

  // optimized tabulation
  public int maxProfit4(int[] prices) {
    int n = prices.length, states = 3;
    int[] next = new int[3], curr = new int[3];

    for(int i=n-1; i>=0; --i){
      for(int state=0; state<states; ++state){
        int currProfit = 0;
        if(state == 0){
          int buy = -prices[i]+next[1];
          int skip = next[state];
          currProfit = Math.max(buy, skip);
        }else if(state == 1){
          int sell = prices[i] + next[2];
          int skip = next[state];
          currProfit = Math.max(sell, skip);
        }else if(state == 2) currProfit = next[0];

        curr[state] = currProfit;
      }
      next = curr.clone();
    }
    return next[0];   //status = not holding
  }
  public static void main(String[] args) {
    int[] prices = {1,2,3,0,2};
    BestTimeToBuyNSellCooldown bsc = new BestTimeToBuyNSellCooldown();
    System.out.println(bsc.maxProfit(prices));
  }
}