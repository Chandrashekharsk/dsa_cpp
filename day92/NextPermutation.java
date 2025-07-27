// 31. Next Permutation
import java.util.Arrays;

public class NextPermutation {

  private  static void swap (int[] nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  private static void reverse(int[] nums, int st, int end){
    while(st<end){
      swap(nums, st, end);
      ++st; --end;
    }
  }

  public static void nextPermutation(int[] nums) {
    int n = nums.length;
    int idx = n - 2;
    // 1, 2, 5, 4, 3
    while (idx >= 0 && nums[idx] >= nums[idx + 1])  --idx;

    if (idx>=0) {
      int j=n-1;
      while(j>=0 && nums[j]<=nums[idx]) --j;
      swap(nums, idx, j);
    }
    reverse(nums, idx+1, n-1);
  }

  public static void main(String[] args) {
    // int[] nums = {1, 2, 3}; 
    // int[] nums = { 3, 2, 1}; 
    // int[] nums = {1, 2, 5, 4, 3}; 
    int[] nums = {1,5,1}; 
    nextPermutation(nums);
    System.out.println("Next Permutation: " + Arrays.toString(nums));
  }
}
