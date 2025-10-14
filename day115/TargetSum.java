// 494. Target Sum
import java.util.HashMap;
import java.util.Map;

public class TargetSum {
  private int helper(int i, int currSum, int[] nums, int target){
    if(i>=nums.length) return currSum==target? 1: 0;
    String key = i+","+ currSum;
    if(m.containsKey(key)) return m.get(key);

    int add = helper(i+1, currSum+nums[i], nums, target);
    int substract = helper(i+1, currSum-nums[i], nums, target);
    m.put(key, add + substract);
    return add + substract;
  }
  private Map<String, Integer> m;
  public int findTargetSumWays(int[] nums, int target) {
    m =  new HashMap<>();
    return helper(0, 0, nums, target);
  }


  public int findTargetSumWays3(int[] nums, int target) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    // If target sum can't be formed
    if ((totalSum + target) % 2 != 0 || totalSum < Math.abs(target)) return 0;

    int S1 = (totalSum + target) / 2;
    int n = nums.length;

    int[][] dp = new int[n + 1][S1 + 1];

    // Base case: 1 way to make sum 0 (empty subset)
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int sum = 0; sum <= S1; sum++) {
        if (nums[i - 1] <= sum)
          dp[i][sum] = dp[i - 1][sum] + dp[i - 1][sum - nums[i - 1]];
        else
          dp[i][sum] = dp[i - 1][sum];
      }
    }

    return dp[n][S1];
  }
  public int findTargetSumWays2(int[] nums, int target) {
    int totSum = 0;
    for(int n: nums) totSum+= n;
    int s1 = (totSum+target)/2;
    if((totSum+target)%2 !=0 || totSum<Math.abs(target)) return 0;
    int[][] dp = new int[nums.length][s1+1];
    for(int i=0; i<nums.length; ++i) dp[i][0] = 1;

    for(int i=1; i<=nums.length; ++i){
      for(int j=0; j<=s1; ++j){
        if(nums[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
        else dp[i][j] = dp[i-1][j];
      }
    }
    return dp[nums.length][s1];
  }
  public int findTargetSumWays4(int[] nums, int target) {
    int totSum = 0;
    for(int n: nums) totSum+= n;
    int s1 = (totSum+target)/2;
    if((totSum+target)%2 !=0 || totSum<Math.abs(target)) return 0;
    int[] prev = new int[s1+1], curr = new int[s1+1];
    prev[0] = 1;

    for(int i=1; i<=nums.length; ++i){
      for(int j=0; j<=s1; ++j){
        if(nums[i-1]<=j) curr[j] = prev[j] + prev[j-nums[i-1]];
        else curr[j] = prev[j];
      }
      prev = curr.clone();
    }
    return prev[s1];
  }
  
  public static void main(String[] args) {
    int[] nums = {1, 1, 1, 1, 1};
    int tar = 3;
    TargetSum ts  = new TargetSum();
    System.out.println(ts.findTargetSumWays4(nums, tar));
  }
}
