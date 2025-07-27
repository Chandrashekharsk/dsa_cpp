// 152. Maximum Product Subarray
public class MaxSubArrProd {
  public  static int maxProduct(int[] nums) {
    if(nums.length == 0) return -1;
    int min = 1, max = 1, mp = nums[0];
    
    for(int n: nums ){
      int temp = max;
      max = Integer.max(n*max, Integer.max(n, min* n));
      min = Integer.min(n*temp, Integer.min(n, min* n));
      mp = Integer.max(mp, max);
    }
    return mp;
  }

  public static void main(String[] args) {
    int[]  nums =  {-2,0,-1};
    // int[]  nums =  {2,3,-2,4};
    System.out.println(maxProduct(nums));
  }
}
