// 153. Find Minimum in Rotated Sorted Array

public class FindMinVal {

  public static int findMin(int[] nums) {
    if(nums == null || nums.length == 0) return 0;
    int start = 0, end = nums.length -1;
    if(nums[start] <= nums[end]) return nums[start]; // If the array is sorted and not rotated
    while (start<=end) {
      int mid = start + (end - start) / 2;
      if(mid>0 && nums[mid]<nums[mid-1]) {
        return nums[mid]; // Found the minimum element
      } 
      if(mid<nums.length-1 && nums[mid]>nums[mid+1]) {
        return nums[mid+1]; // Found the minimum element
      }

      if(nums[mid] >= nums[start]) {
        start = mid + 1; // Minimum must be in the right half
      } else {
        end = mid - 1; // Minimum must be in the left half
      }
    }
    return -1;
  }
  public static void main(String[] args) {
    int[] nums = {3,4,5,1,2};
    System.out.println( findMin(nums));
  }
}
