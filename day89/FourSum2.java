// 454. 4Sum II
import java.util.HashMap;
import java.util.Map;

public class FourSum2 {
  public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
    Map<Integer, Integer> m = new HashMap<>();

    for (int a : nums1) {
      for (int b : nums2) {
        int sum = a + b;
        m.put(sum, m.getOrDefault(sum, 0) + 1);
      }
    }

    int cnt = 0;
    for(int i: nums3){
      for(int j: nums4){
        int sum = i+j;
        if(m.containsKey(-sum)) ++cnt;
      }
    }
    return cnt;
  }

  public static void main(String[] args) {
    int[] nums1 = {1, 2};
    int[] nums2 = {-2, -1};
    int[] nums3 = {-1, 2};
    int[] nums4 = {0, 2};
    FourSum2 fs2 = new FourSum2();
    int result = fs2.fourSumCount(nums1, nums2, nums3, nums4);
    System.out.println(result);
  }
}
