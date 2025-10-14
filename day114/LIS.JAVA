// 300. Longest Increasing Subsequence
import java.util.ArrayList;
import java.util.List;

public class LIS {
  // O(n^2) DP approach
  public int lengthOfLIS(int[] nums) {
    int n = nums.length;
    int lis = 1;
    int[] dp = new int[n];

    for (int i = 0; i < n; ++i) {
      dp[i] = 1; // every element is a subsequence
      for (int prev = 0; prev < i; ++prev) {
        if (nums[prev] < nums[i]) {
          dp[i] = Math.max(dp[i], dp[prev] + 1);
        }
      }
      lis = Math.max(lis, dp[i]);
    }
    return lis;
  }

  // helper binary search to find position to replace
  private int binarySearch(List<Integer> subSeq, int num) {
    int left = 0, right = subSeq.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (subSeq.get(mid) < num) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }

  // O(n log n) LIS approach
  public int lengthOfLIS2(int[] nums) {
    int n = nums.length;
    List<Integer> subSeq = new ArrayList<>();
    subSeq.add(nums[0]);

    for (int i = 1; i < n; ++i) {
      if (nums[i] > subSeq.get(subSeq.size() - 1)) {
        subSeq.add(nums[i]);
      } else {
        int j = binarySearch(subSeq, nums[i]);
        subSeq.set(j, nums[i]);
      }
    }
    return subSeq.size();
  }

  public static void main(String[] args) {
    LIS lis = new LIS();
    System.out.println("O(n^2) LIS: " + lis.lengthOfLIS(new int[]{10,9,2,5,3,7,101,18}));
    System.out.println("O(n log n) LIS: " + lis.lengthOfLIS2(new int[]{10,9,2,5,3,7,101,18}));
  }
}
