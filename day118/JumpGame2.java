// 45. Jump Game II

public class JumpGame2 {
  public int jump(int[] nums) {
    int cm = 0, ce = 0, totalJumps = 0;
    for (int i = 0; i < nums.length-1; ++i) {
      cm = Math.max(cm, nums[i] + i);
      if (ce == i) {
        ++totalJumps;
        ce = cm;
      }
    }
    return totalJumps;
  }

  public static void main(String[] args) {
    JumpGame2 jg = new JumpGame2();
    System.out.println(jg.jump(new int[] { 2, 3, 1, 1, 4 }));
  }
}
