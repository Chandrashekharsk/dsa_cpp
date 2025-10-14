// 416. Partition Equal Subset Sum
import java.util.Arrays;

public class CanPartition {
  private  boolean helper(int i, int target, int[] nums){
    if(target == 0)return true;
    if(i == nums.length) return false;

    
    boolean pick = nums[i]<= target? helper(i+1, target-nums[i], nums): false;
    boolean notPick = helper(i+1, target, nums);

    return  pick || notPick;
  }

  public boolean canPartition(int[] nums) {
    int total = 0;
    for(int num: nums) total+= num;
    if((total & 1) == 1) return false;

    return helper(0, total/2, nums);
  }

  private  boolean helper2(int i, int target, int[] nums){
    if(target == 0)return true;
    if(i == nums.length) return false;
    if(dp[i][target] != null) return dp[i][target];
    
    boolean pick = nums[i]<= target? helper2(i+1, target-nums[i], nums): false;
    boolean notPick = helper2(i+1, target, nums);

    return  dp[i][target] = pick || notPick;
  }

  Boolean[][] dp;
  public boolean canPartition2(int[] nums) {
    int total = 0;
    for(int num: nums) total+= num;
    if((total & 1) == 1) return false;
    dp = new Boolean[nums.length][(total/2)+1];

    return helper2(0, total/2, nums);
  }

  public boolean canPartition3(int[] nums) {
    int total = 0;
    for(int num: nums) total+= num;
    if((total & 1) == 1) return false;
    int n = nums.length;
    int target = total/2;
    boolean[][] dp = new boolean[n + 1][target + 1];

    for(int i=0; i<n; ++i) dp[i][0] = true;

    for(int i=1; i<=n; ++i){
      for(int tar=1; tar<=target; ++tar){
        boolean pick = nums[i-1]<= tar? dp[i-1][tar-nums[i-1]]:false;
        boolean notPick = dp[i-1][tar];
        dp[i][tar] = pick|| notPick;
      }
    }
    return dp[n][target];
  }
  public static void main(String[] args) {
    CanPartition cp = new CanPartition();
    System.out.println(cp.canPartition3(new int[]{1,5,11,5}));
  }
}
