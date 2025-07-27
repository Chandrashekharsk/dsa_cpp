// 219. Contains Duplicate II
import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicate2 {
  public static boolean containsNearbyDuplicate(int[] nums, int k){
    Set<Integer> s = new HashSet<>();
    for(int i=0; i<nums.length; ++i){
      if(s.contains(nums[i])){
        return true;
      }
      s.add(nums[i]);
      if(s.size()>k){
        s.remove(nums[i-k]);
      }
    }
    return false;
  }
  public static void main(String[] args) {
    int[] nums = {1, 2, 3, 1};
    System.out.println(containsNearbyDuplicate(nums, 3));
  }
}
