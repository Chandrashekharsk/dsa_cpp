// 704. Binary Search

public class BinarySearch{
  public static int search(int[] nums, int target) {
    int st = 0, end = nums.length-1;
    while(st<=end){
      int mid = (end-st)/2 + st;
      if(nums[mid]== target) return mid;
      else if(nums[mid]<target){
        st = mid+1;
      }else end = mid-1;
    }
    return -1;
  }
  public static void main(String[] args) {
    int[] nums = {3,4,7, 8, 24};
    // System.out.println(search(nums, 5));
    System.out.println(search(nums, 7));
  }
}