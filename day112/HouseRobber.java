// 198. House Robber
import java.util.Arrays;

public class HouseRobber {
  // private int helper(int[] nums, int i) {
  //   if (i < 0) return 0;
  //   if (i == 0) return nums[0];

  //   int rob = nums[i] + helper(nums, i - 2);
  //   int notRob = helper(nums, i - 1);

  //   return Math.max(rob, notRob);
  // }
  // public int rob(int[] nums) {
  //   return helper(nums, nums.length - 1);
  // }

  private int[] dp;
  // private int helper2(int idx, int[] nums) {
  //   if (idx==0) return nums[idx];
  //   if (idx<0) return 0;
  //   if (dp[idx] != -1) return dp[idx];

  //   // Max(Pick, NotPick)
  //   return dp[idx] = Math.max(nums[idx] + helper2(idx-2, nums), helper2(idx-1, nums));
  // }

  // public int rob2(int[] nums) {
  //   dp = new int[nums.length];
  //   Arrays.fill(dp, -1);
  //   return helper2(nums.length - 1, nums);
  // }

  // public int rob3(int[] nums) {
  //   int n = nums.length;
  //   if(n==0) return 0;
  //   if(n==1) return nums[0];

  //   dp = new int[n];
  //   Arrays.fill(dp, -1);
  //   dp[0] = nums[0];
  //   dp[1] = Math.max(nums[1], nums[0]);
  //   for(int i=2; i<n; ++i){
  //     dp[i] = Math.max(nums[i]+dp[i-2], dp[i-1]);
  //   }

  //   return dp[n-1];
  // }

  public int rob4(int[] nums) {
    int n = nums.length;
    if(n==0) return 0;
    if(n==1) return nums[0];

    int prev2 = nums[0];
    int prev = Math.max(nums[1], nums[0]);
    for(int i=2; i<n; ++i){
      int curr = Math.max(nums[i]+prev2, prev);
      prev2 = prev;
      prev = curr;
    }

    return prev;
  }

  public static void main(String[] args) {
    HouseRobber hr = new HouseRobber();
    System.out.println(hr.rob4(new int[] { 2, 7, 9, 3, 1 }));
  }
}
