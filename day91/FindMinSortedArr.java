// 153. Find Minimum in Rotated Sorted Array

public class FindMinSortedArr {
  public static int findMin(int[] nums) {
    int start = 0, end = nums.length-1;
    if (nums[start] <= nums[end]) return nums[start];

    while(start<=end){
      int mid = (end-start)/2 + start;
      if( mid!= 0 && nums[mid]< nums[mid-1]) return nums[mid];
      if(mid<nums.length-1 && nums[mid+1]<nums[mid]) return nums[mid+1];
      if(nums[start]<=nums[mid]) start  = mid+1;
      else  end = mid - 1;
    }
    return -1;
  }

  public static void main(String[] args) {
    int[] nums = {1,2 ,3 , 5, 7};
    System.out.println(findMin(nums));
  }
}
