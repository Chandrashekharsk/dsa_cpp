// 322. Coin Change

import java.util.Arrays;

public class CoinChange {
  private int helper(int[] coins, int amount) {
    if (amount < 0)
      return Integer.MAX_VALUE;
    if (amount == 0)
      return 0;

    int minCoins = Integer.MAX_VALUE;
    for (int coin : coins) {
      int curr = helper(coins, amount - coin);
      if (curr != Integer.MAX_VALUE)
        minCoins = Math.min(minCoins, curr + 1);
    }
    return minCoins;
  }

  public int coinChange(int[] coins, int amount) {
    int ans = helper(coins, amount);
    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  private int helper2(int[] coins, int amount, int[] dp) {
    if (amount < 0)
      return Integer.MAX_VALUE;
    if (amount == 0)
      return 0;
    if (dp[amount] != -1)
      return dp[amount];

    int minCoins = Integer.MAX_VALUE;
    for (int coin : coins) {
      int curr = helper2(coins, amount - coin, dp);
      if (curr != Integer.MAX_VALUE)
        minCoins = Math.min(minCoins, curr + 1);
    }
    return dp[amount] = minCoins;
  }

  public int coinChange2(int[] coins, int amount) {
    int[] dp = new int[amount + 1];
    Arrays.fill(dp, -1);
    int ans = helper2(coins, amount, dp);
    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  public int coinChange3(int[] coins, int amount) {
    if (amount == 0) return 0;

    int[] dp = new int[amount + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[0] = 0;


    for (int i = 1; i <= amount; ++i) {
      for (int coin : coins) {
        if (i - coin >= 0 && dp[i-coin] != Integer.MAX_VALUE) {
          int curr = dp[i - coin];
          dp[i] = Math.min(dp[i], 1 + curr);
        }
      }
    }
    return dp[amount] == Integer.MAX_VALUE? -1: dp[amount];
  }

  public static void main(String[] args) {
    int[] coins = { 1, 2, 5 };
    int amount = 3;
    CoinChange cc = new CoinChange();
    System.out.println(cc.coinChange3(coins, amount));
  }
}
