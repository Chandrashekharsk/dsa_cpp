// 128. Longest Consecutive Sequence

import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSeq {
  public static int longestConsecutive(int[] nums) {
    if (nums == null || nums.length == 0) return 0;

    Set<Integer> numSet = new HashSet<>();
    for (int num : nums) numSet.add(num);

    int longestStreak = 0;

    for (int num : nums) {
      if (!numSet.contains(num - 1)) {
        int currentNum = num;
        int currStreak = 1;

        while (numSet.contains(currentNum + currStreak)) ++currStreak;
        longestStreak = Integer.max(longestStreak, currStreak);
      }
    }

    return longestStreak;
  }

  public static void main(String[] args) {
    int[] nums = { 100, 4, 200, 1, 3, 2 };
    System.out.println(longestConsecutive(nums));
  }
}
