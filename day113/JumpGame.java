// 55. Jump Game

public class JumpGame {
  private boolean helper(int i, int[] nums){
    if(i>=nums.length-1) return true;

    int MaxJump = Math.min(i+nums[i], nums.length-1);
    for(int nextJump=i+1; nextJump<=MaxJump; ++nextJump){
      if(helper(nextJump, nums)) return true;
    }
    return false;
  }
  public boolean canJump(int[] nums) {
    return helper(0, nums);
  }


  private boolean helper2(int i, int[] nums){
    if(dp[i] != 0) return dp[i]==1; // if already visited return computed value(true/false)

    int MaxJump = Math.min(i+nums[i], nums.length-1);
    for(int nextJump=i+1; nextJump<=MaxJump; ++nextJump){
      if(helper2(nextJump, nums)){
        dp[i] = 1;
        return true;
      };
    }
    dp[i] = -1;
    return false;
  }
  private int[] dp;
  public boolean canJump2(int[] nums) {
    dp = new int[nums.length];
    dp[nums.length-1] = 1;
    return helper2(0, nums);
  }

  public boolean canJump3(int[] nums) {
    int n = nums.length;
    dp = new int[n];
    dp[n-1] = 1;
    for(int i=n-2; i>=0; --i){
      int MaxJump = Math.min(n-1, i+nums[i]);
      for(int j=i+1; j<=MaxJump; ++j){
        if(dp[j] ==1){
          dp[i] = 1;
          break;
        }
      }
    }
    return dp[0]==1;
  }

  public boolean canJump4(int[] nums) {
    int n = nums.length;
    int farthest = 0;

    for(int i=0; i<n; ++i){
      if(i>farthest)return false;
      farthest = Math.max(farthest, i+nums[i]);
    }
    return true;
  }

  public static void main(String[] args) {
    JumpGame jg = new JumpGame();
    // System.out.println(jg.canJump2(new int[]{3,2,1,0,4}));
    System.out.println(jg.canJump2(new int[]{2,3,1,1,4}));
  }
}
