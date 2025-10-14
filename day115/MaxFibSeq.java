public class MaxFibSeq {
  public int longestSubarray(int[] nums) {
    int n = nums.length;
    if (n < 3)
      return n;
    int maxCnt = 2;
    int cnt = 2;
    for (int i = 2; i < n; ++i) {
      if (nums[i - 2] + nums[i - 1] == nums[i])
        ++cnt;
      else
        cnt = 2;
      maxCnt = Math.max(cnt, maxCnt);
    }
    return maxCnt;
  }

  public static void main(String[] args) {
    
  }
}
