// 219. Contains Duplicate II
import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicat2 {

  public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> s = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
      if(s.contains(nums[i])) return true;
      s.add(nums[i]);
      if(s.size()>k) s.remove(nums[i-k]);
    }
    return false;
  }

  public static void main(String[] args) {
    ContainsDuplicat2 cd2 = new ContainsDuplicat2();
    int[] nums1 = { 1, 2, 3, 1 };
    int[] nums2 = { 1, 0, 1, 1 };
    int[] nums3 = { 1, 2, 3, 1, 2, 3 };
    System.out.println("Test 1: " + cd2.containsNearbyDuplicate(nums1, 3)); // Expected: true
    System.out.println("Test 2: " + cd2.containsNearbyDuplicate(nums2, 1)); // Expected: true
    System.out.println("Test 3: " + cd2.containsNearbyDuplicate(nums3, 2)); // Expected: false
  }
}
