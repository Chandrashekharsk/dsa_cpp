// 2210. Count Hills and Valleys in an Array

public class CountHillsNValleys {
  public static int countHillValley(int[] nums) {
    int hills = 0, valleys = 0, i = 1;

    while(i<nums.length-1){
      int prevIdx = i-1, nextIdx = i+1;
      while(i<nums.length-1 && nums[i]==nums[nextIdx]){
        ++i;
        ++nextIdx;
      }
      if(i<nums.length-1 && nums[i]<nums[prevIdx] && nums[i]<nums[nextIdx]) ++valleys;
      if(i<nums.length-1 && nums[i]>nums[prevIdx] && nums[i]>nums[nextIdx]) ++hills;
      ++i;
    }
    return hills+valleys;
  }
  public static void main(String[] args) {
    // int[] nums = {2,4,1,1,6,5};
    // System.out.println(countHillValley(nums));
    System.out.println(countHillValley(new int[]{2,4,1,1,6,5}));
    // System.out.println(countHillValley(new int[]{6,6,5,5,4,1}));
  }
}
