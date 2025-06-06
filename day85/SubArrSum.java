// 53. Maximum Subarray
public class SubArrSum {
  public int maxSubArray(int[] nums) {
    int n = nums.length;
    int maxSum = Integer.MIN_VALUE;
    int currSum = 0;
    for (int i=0; i<n; ++i){
      if(currSum<0) currSum = 0;
      currSum += nums[i];
      maxSum = Math.max(currSum, maxSum);
    }
    return maxSum;
  }
  public static void main(String[] args) {
    SubArrSum sas = new SubArrSum();
    int[] nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    int[] nums2 = {1};
    int[] nums4 = {-1};
    int[] nums3 = {5,4,-1,7,8};
    System.out.println("Test 1: " + sas.maxSubArray(nums1)); // Expected: 6
    System.out.println("Test 2: " + sas.maxSubArray(nums2)); // Expected: 1
    System.out.println("Test 3: " + sas.maxSubArray(nums3)); // Expected: 23
    System.out.println("Test 3: " + sas.maxSubArray(nums4)); // Expected: 23

  }
}
