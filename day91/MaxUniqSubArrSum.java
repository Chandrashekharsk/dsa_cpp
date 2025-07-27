
// 3487. Maximum Unique Subarray Sum After Deletion
import java.util.HashSet;
import java.util.Set;

public class MaxUniqSubArrSum {

  public static int maxSum(int[] nums) {
    int ms = Integer.MIN_VALUE;
    for(int n: nums){
      if(n>ms) ms = n;
    }
    if(ms<= 0) return ms;
    
    Set<Integer> s = new HashSet<>();
    int currentSum = 0;
    for(int n: nums){
      if(n>0 && !s.contains(n)){
        s.add(n);
        currentSum += n;
      }
    }
    return currentSum;
  }

  public static void main(String[] args) {
    // int[] nums1 = {1,1,0,1,1};
    int[] nums1 = { 4, 2, 3, 4, 5, 6 };
    int result1 = maxSum(nums1);
    System.out.println("Test 1: " + result1); // Expected: 17
    int[] nums2 = {-1500};
    // int[] nums2 = { -17, 17 };
    // int[] nums2 = {5,2,1,2,5,2,1,2,5};
    int result2 = maxSum(nums2);
    System.out.println("Test 2: " + result2); // Expected: 8
  }
}