// 213. House Robber II

public class HouseRobber2{
  private int[] dp;

  private int tabHelper(int start, int end, int[] nums){
    int n = end - start + 1;
    if (n == 1) return nums[start];

    dp = new int[n];
    dp[0] = nums[start];
    dp[1] = Math.max(nums[start], nums[start+1]);

    for(int i=2; i<n; ++i){
      dp[i] = Math.max(nums[start+i]+ dp[i-2], dp[i-1]);
    }
    return dp[n-1];
  }
  public int rob(int[] nums) {
    int n = nums.length;
    if(n==0)return 0;
    if(n==1) return nums[0];
    return Math.max(tabHelper(0, n-2, nums), tabHelper(1, n-1, nums));
  }


  private int tabHelper2(int start, int end, int[] nums){
    int n = end-start +1;
    if(n==1) return nums[start];

    int prev2 = nums[start];
    int prev = Math.max(nums[start], nums[start+1]);

    for(int i=2; i<n; ++i){
      int curr = Math.max(nums[start+i]+ prev2, prev);

      prev2 = prev;
      prev = curr;
    }
    return prev;
  }

  // Optimize Tabulation
  public int rob2(int[] nums) {
    int n = nums.length;
    if(n==0)return 0;
    if(n==1) return nums[0];
    return Math.max(tabHelper2(0, n-2, nums), tabHelper2(1, n-1, nums));
  }
  public static void main(String[] args) {
    HouseRobber2 hr = new HouseRobber2();
    System.out.println(hr.rob2(new int[] { 1,2,3,1 }));
  }
}