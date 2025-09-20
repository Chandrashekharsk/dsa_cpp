// 322. Coin Change

public class CoinChange {

  private int helper (int cnt, int i, int[] coins, int amount){
    if(amount == 0 ) return cnt;
    if(i<0 && amount>0) return -1;
    if(coins[i]<=amount &&  amount%coins[i] <= 0 ){
      amount= amount%coins[i];
      cnt+= amount/coins[i];
    }
    return helper(cnt, i-1, coins, amount);
  }

  public int coinChange(int[] coins, int amount) {
    int cnt = 0;
    return helper(cnt, coins.length-1, coins, amount);
  }

  public static void main(String[] args) {
    int[] coins = {1,2,5};
    int amount = 11;
    CoinChange cc = new CoinChange();
    System.out.println(cc.coinChange(coins, amount));
  }
}
