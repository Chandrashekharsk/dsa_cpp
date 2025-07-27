// 33. Search in Rotated Sorted Array
public class SearchRotatedSortedArr {
  public static int search(int[] nums, int target) {
    int start  = 0, end = nums.length-1;
    while(start<=end){
      int mid  = (end-start)/2 + start;
      if(nums[mid] == target) return mid;
      if(nums[start]<=nums[mid]){
        if(nums[start]<=target && nums[mid]> target){
          end = mid-1;
        }else start = mid+1;
      }else{
        if(target> nums[mid] && target<=nums[end]){
          start = mid+1;
        }else end = mid-1;
      }
    }
    return -1;
  }

  public static void main(String[] args) {
    int[] nums = {5,1,2,3,4};
    // int[] nums = {4,5,6,7,8,1,2,3};
    // int[] nums = {4,5,6,7,0,1,2};
    System.out.println(search(nums, 1));
  }

}
