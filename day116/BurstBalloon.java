// 312. Burst Balloons
public class BurstBalloon {

  private int helper(int l, int r, int[] nums){
    if(l+1 == r) return 0;
    if(dp[l][r] != null) return dp[l][r];

    int maxCoins = 1;
    for(int m= l+1; m<r; ++m){
      int coins = nums[l]* nums[m]* nums[r] + helper(l, m, nums) + helper(m, r, nums);
      maxCoins = Math.max(maxCoins, coins);
    }
    return dp[l][r] =  maxCoins;
  }
  Integer[][] dp;
  public int maxCoins(int[] nums) {
    int n = nums.length;
    int[] newArr = new int[n+2];
    newArr[0] = 1;
    newArr[n+1] = 1;
    dp = new Integer[n+2][n+2];

    for(int i=0; i<n; ++i) newArr[i+1] = nums[i];
    return helper(0, n+1, newArr);
  }

  public int maxCoins2(int[] nums) {
    int n = nums.length;
    int[] newArr = new int[n+2];
    newArr[0] = 1;
    newArr[n+1] = 1;
    int[][] dp = new int[n+2][n+2];

    for(int i=0; i<n; ++i) newArr[i+1] = nums[i];
    
    for(int len = 2; len<n+2; ++len){
      for(int left = 0; left + len<n+2; ++left){
        int right = left + len;
        for(int k = left+1; k<right; ++k){
          dp[left][right] = Math.max(dp[left][right], 
            newArr[left] * newArr[k] * newArr[right] + dp[left][k] + dp[k][right]
          );
        }
      }
    }
    return dp[0][n+1];
  }
  public static void main(String[] args) {
    BurstBalloon bb = new BurstBalloon();
    System.out.println(bb.maxCoins2(new int[]{3,1,5,8}));
  }
}
