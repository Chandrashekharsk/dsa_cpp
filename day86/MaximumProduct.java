// 152. Maximum Product Subarray

public class MaximumProduct {
  public static int maxProduct(int[] nums) {
    if(nums == null || nums.length == 0) return 0;
    int max = nums[0], min = nums[0], ans = nums[0];

    for(int i=1; i<nums.length; ++i){
      int curr = nums[i];
      int previousMax = Math.max(curr, Math.max(max * curr, min * curr));
      min = Math.max(curr, Math.max(max * curr, min * curr));
      max = previousMax;
      if(max > ans)  ans = max;
    }
    return ans;
  }
  public static void main(String[] args) {
    int[] nums = {2,3,-2,4};
    // int[] nums = {-3,-1, -1};
    // int[] nums = {0, -1};
    // int[] nums = {3, -1, 4};
    // int[] nums = {0, 2};
    System.out.println(maxProduct(nums));
  }
}
 