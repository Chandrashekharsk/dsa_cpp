// 217. Contains Duplicate
import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicate {

  public boolean containsDuplicate(int[] nums) {
    Set<Integer> s = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
      if (s.contains(nums[i])) return true;
      s.add(nums[i]);
    }
    return false;
  }

  public static void main(String[] args) {
    ContainsDuplicate cd = new ContainsDuplicate();
    int[] nums1 = { 1, 2, 3, 1 };
    int[] nums2 = { 1, 2, 3, 4 };
    int[] nums3 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    System.out.println("Test 1: " + cd.containsDuplicate(nums1)); // Expected: true
    System.out.println("Test 2: " + cd.containsDuplicate(nums2)); // Expected: false
    System.out.println("Test 3: " + cd.containsDuplicate(nums3)); // Expected: true
  }
}
