// 128. Longest Consecutive Sequence
import java.util.HashSet;
import java.util.Set;

public class LongestConsecSeq {
  public int longestConsecutive(int[] nums) {
    if (nums == null || nums.length == 0)  return 0;

    Set<Integer> numSet = new HashSet<>();
    for (int num : nums) numSet.add(num);
    int longestStreak = 0;

    for (int num : numSet) {
      if (!numSet.contains(num - 1)) {
        int currentNum = num;
        int currentStreak = 1;
        System.out.print(currentStreak +" ");
        
        while (numSet.contains(currentNum + 1)) {
          ++currentNum;
          ++currentStreak;
          System.out.print(currentStreak +" ");
        }
        System.out.println();
        longestStreak = Math.max(longestStreak, currentStreak);
      }
    }

    return longestStreak;
  }

  public static void main(String[] args) {
    LongestConsecSeq lcs = new LongestConsecSeq();
    System.out.println(lcs.longestConsecutive(new int[]{100, 1, 1, 200, 3, 4, 2}));
  }
}