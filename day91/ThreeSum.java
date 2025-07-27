// 15. 3Sum
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
  public static List<List<Integer>> threeSum(int[] nums) {
    List<List<Integer>> ans = new ArrayList<>();
    int n = nums.length;
    if(n<3) return ans;
    Arrays.sort(nums);

    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int lt = i + 1, rt = n - 1;
      while (lt < rt) {
        int sum = nums[i] + nums[lt] + nums[rt];
        if (sum == 0) {
          ans.add(Arrays.asList(nums[i], nums[lt], nums[rt]));
          ++lt; --rt;
          while (lt < rt && nums[lt] == nums[lt - 1])
            ++lt;
          while (lt < rt && nums[rt] == nums[rt + 1])
            --rt;
        } else if (sum > 0) {
          --rt;
        } else
          ++lt;
      }
    }
    return ans;
  }

  public static void main(String[] args) {
    // int[] nums = { -1, 0, 1, 2, -1, -4 };
    int[] nums = { 1, -1,0 };
    List<List<Integer>> list = threeSum(nums);
    for (List<Integer> triplet : list) {
      System.out.println(triplet);
    }
  }
}
