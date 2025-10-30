// 53. Maximum Subarray

public class MaxSubArrSum{
  public int maxSubArray(int[] nums){
    int n = nums.length;
    int MaxSum = Integer.MIN_VALUE;
    int curr = 0;

    for(int i=0; i<n; ++i){
      curr += nums[i];
      MaxSum = Math.max(curr, MaxSum);
      if(curr < 0) curr = 0;
    }
    return MaxSum;
  }
  public static void main(String[] args) {
    MaxSubArrSum mss = new MaxSubArrSum();
    int[] nums = {-1};
    System.out.println(mss.maxSubArray(nums));
  }
}