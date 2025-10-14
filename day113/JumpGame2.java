// 45. Jump Game II

import java.util.Arrays;

public class JumpGame2 {
  private int minCount;
  private void helper(int i, int[] nums, int currCnt){
    if(i==nums.length-1) {
      minCount = Math.min(minCount, currCnt);
      return;
    };
    int MaxJump = Math.min(nums.length-1, i+nums[i]);
    for(int j=i+1; j<=MaxJump; ++j) helper(j, nums, currCnt+1);
  }
  public int jump(int[] nums) {
    minCount = Integer.MAX_VALUE;
    
    helper(0, nums, 0);
    return minCount;
  }


  private int helper2(int i, int[] nums){
    if(i==nums.length-1) return 0;
    if(dp[i] != -1) return dp[i];

    int MaxJump = Math.min(nums.length-1, i+nums[i]);
    int minSteps = Integer.MAX_VALUE;
    for(int j=i+1; j<=MaxJump; ++j){
      int sub = helper2(j, nums);
      if (sub != Integer.MAX_VALUE) { // only valid path
        minSteps = Math.min(minSteps, 1 + sub);
      }
    }
    return dp[i] = minSteps;
  }
  private int[] dp;
  public int jump2(int[] nums) {
    dp = new int[nums.length];
    Arrays.fill(dp, -1);
    return helper2(0, nums);
  }
  public int jump3(int[] nums) {
    int n = nums.length;
    dp = new int[n];
    Arrays.fill(dp, -1);
    dp[n-1] = 0;
    for(int i=n-2; i>=0; --i){
      int MaxJump = Math.min(n-1, i+nums[i]);
      int minSteps = Integer.MAX_VALUE;
      for(int j=i+1; j<=MaxJump; ++j){
        if(dp[j] != Integer.MAX_VALUE){
          minSteps = Math.min(minSteps, 1+dp[j]);
        }
      }
      dp[i] = minSteps;
    }
    return dp[0];
  }

  public static void main(String[] args) {
    JumpGame2 jg = new JumpGame2();
    System.out.println(jg.jump3(new int[]{2,3,1,1,4}));
  }
}
