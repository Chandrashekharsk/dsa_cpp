// 287. Find the Duplicate Number
public class FindDuplicate {
  public static int findDuplicate(int[] nums) {
    int fast = nums[0], slow = nums[0];
    do{
      slow = nums[slow];
      fast = nums[nums[fast]];
    }while(slow != fast);
    slow = nums[0];
    while(slow!=fast){
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
  public static void main(String[] args) {
    // int[] nums = {1, 2, 3, 2, 4};
    int[] nums = {3, 3, 3, 3, 3};
    System.out.println(findDuplicate(nums));
  }
}
