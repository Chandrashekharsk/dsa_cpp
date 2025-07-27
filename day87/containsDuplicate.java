import java.util.HashSet;
import java.util.Set;

public class containsDuplicate {
  public static boolean containsDuplicateFunc(int[] nums) {
    Set<Integer> s = new HashSet<>();
    for(int i=0; i<nums.length; ++i){
      if(s.contains(nums[i])) return true;
      s.add(nums[i]);
    }
    return false;
  }

  public static void main(String[] args) {
    // int nums[] = {1,2, 3, 5, 8};
    int nums[] = {1,2, 5, 5, 8};
    System.out.println(containsDuplicateFunc(nums));
  }
}
