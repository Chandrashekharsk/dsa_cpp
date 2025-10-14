// 518. Coin Change II

public class CoinChange2 {
  public int change(int amount, int[] coins) {
    int n = coins.length;
    int[][] dp = new int[n+1][amount+1];
    for(int i=0;i<=n; ++i) dp[i][0] = 1;

    for(int i=n-1; i>=0; --i){
      for(int j=0; j<= amount; ++j){
        int take = 0;
        if(coins[i]<= j) take = dp[i][j-coins[i]];
        int notTake = dp[i+1][j];
        
        dp[i][j] = take + notTake;
      }
    }
    return dp[0][amount];
  }

  public int change2(int amount, int[] coins) {
    int n = coins.length;
    int[] curr = new int[amount+1], next = new int[amount+1];
    next[0] = 1;

    for(int i=n-1; i>=0; --i){
      for(int j=0; j<= amount; ++j){
        int take = 0;
        if(coins[i]<= j) take = curr[j-coins[i]];
        int notTake = next[j];
        
        curr[j] = take + notTake;
      }
      next = curr.clone();
    }
    return next[amount];
  }

  public int change3(int amount, int[] coins) {
    int n = coins.length;
    int[] curr = new int[amount+1];
    curr[0] = 1;

    for(int i=n-1; i>=0; --i){
      for(int j=0; j<= amount; ++j){
        curr[j] += coins[i]<=j? curr[j-coins[i]]: 0;
      }
    }
    return curr[amount];
  }

  public static void main(String[] args) {
    CoinChange2 cc2 = new CoinChange2();
    System.out.println(cc2.change3(5, new int[]{ 1,2,5}));
  }
}
