// 55. Jump Game

public class JumpGame {
  public boolean canJump(int[] nums){
    // int finalDest = nums.length-1;
    // for(int i=finalDest-1; i>=0; --i){
    //   if(i+nums[i]>=finalDest)finalDest = i;
    // }
    // return finalDest == 0;
    int farthestJump = 0;
    for(int i=0; i<nums.length; ++i){
      if(i>farthestJump)return false;
      farthestJump = Math.max(farthestJump, i+nums[i]);
    }
    return true;
  }
  public static void main(String[] args) {
    JumpGame jg = new JumpGame();
    System.out.println(jg.canJump(new int[]{3,2,1,0,4}));
  }
}
