// 1. Two Sum
import java.util.HashMap;
import java.util.Map;

public class TwoSum2 {
  public int[] twooSum(int[] nums, int target) {
    Map<Integer, Integer> m = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      int currDiff = target - nums[i];
      if (m.containsKey(currDiff)) {
        return new int[] { m.get(currDiff), i };
      }
      m.put(nums[i], i);
    }
    return null;
  }

  public static void main(String[] args) {
    int[] nums = { 2, 7, 11, 15 };
    int target = 9;
    int[] result = new TwoSum2().twooSum(nums, target);
    for(int i: result ){
      System.out.println(i);
    }
  }

}