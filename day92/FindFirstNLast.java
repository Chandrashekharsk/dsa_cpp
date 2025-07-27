// 34. Find First and Last Position of Element in Sorted Array
public class FindFirstNLast {

  private static int findFirst(int[] nums, int tar){
    int st = 0, end= nums.length-1;
    int first = -1;
    while(st<=end){
      int mid  = (end-st)/2 +st;
      if(nums[mid] == tar){
        first = mid;
        end = mid-1;
      }else if(nums[mid]>tar){
        end = mid-1;
      }else st = mid+1;
    }
    return first;
  }
  private static int findLast(int[] nums, int tar){
    int st = 0, end= nums.length-1;
    int last = -1;
    while(st<=end){
      int mid  = (end-st)/2 +st;
      if(nums[mid] == tar){
        last = mid;
        st = mid+1;
      }else if(nums[mid]>tar){
        end = mid-1;
      }else st = mid+1;
    }
    return last;
  }
  public static int[] searchRange(int[] nums, int target) {
    // approach 1
    // int st = 0, end = nums.length-1;
    // while(st<=end){
    //   int mid = (end-st)/2 + st;
    //   if(nums[mid] == target){
    //     int stIdx = mid, endIdx= mid;
    //     while(stIdx>0 && nums[stIdx] == nums[stIdx-1]) --stIdx;
    //     while(endIdx<nums.length-1 && nums[endIdx] == nums[endIdx+1]) ++endIdx;
    //     return new int[] {stIdx, endIdx};
    //   }else if(nums[mid]>target) end = mid-1;
    //   else st = mid+1;
    // }
    // return new int[]{-1, -1};
    

    // approach 2
    return new int[]{findFirst(nums, target), findLast(nums, target)};
  }
  public static void main(String[] args) {
    // int[] nums  = {1};
    int[] nums  = {5,7,7,8,8,10};
    for(int n: searchRange(nums, 8)){
      System.out.println(n);
    }
  }

}
