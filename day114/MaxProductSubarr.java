// 152. Maximum Product Subarray

public class MaxProductSubarr {
  public int maxProduct(int[] nums) {
    if (nums.length == 0) return -1;
    int max = 1, min = 1, mp = nums[0];
    for (int n : nums) {
      int temp = max;
      max = Integer.max(n * min, Integer.max(n, max * n));
      min = Integer.min(n * temp, Integer.min(n, min * n));
      mp = Integer.max(mp, max);
    }
    return mp;
  }

  public static void main(String[] args) {
    MaxProductSubarr mps = new MaxProductSubarr();
    System.out.println(mps.maxProduct(new int[] {-2,0,-1}));
  }
}
