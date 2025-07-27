// 18. 4Sum
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FourSum {
  public List<List<Integer>> fourSum(int[] nums, int target) {
    Arrays.sort(nums);
    int n = nums.length;
    List<List<Integer>> ans = new ArrayList<>();

    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      
      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int left = j + 1, right = n - 1;

        while (left < right) {
          long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];

          if (sum == target) {
            List<Integer> matchTarget = new ArrayList<>();
            matchTarget.add(nums[i]);
            matchTarget.add(nums[j]);
            matchTarget.add(nums[left]);
            matchTarget.add(nums[right]);
            ans.add(matchTarget);
            ++left;
            --right;
            while (left < right && nums[right] == nums[right + 1])
              --right;
            while (left < right && nums[left] == nums[left - 1])
              ++left;
          } else if (sum < target)
            ++left;
          else
            --right;
        }
      }
    }

    return ans;
  }

  public static void main(String[] args) {
    // int[] nums = {1, 0, -1, 0, -2, 2};
    int[] nums = { -3,-1,0,2,4,5 };
    int target = 0;
    FourSum fs = new FourSum();
    List<List<Integer>> result = fs.fourSum(nums, target);
    System.out.println(result);
  }
}
