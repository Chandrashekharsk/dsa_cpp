// Weekly Contest 470. Compute Alternating Sum
public class ComputeAlternateSum{
  public int alternatingSum(int[] nums) {
    boolean minus = true;
    int total = nums[0];
    for(int i=1; i<nums.length; ++i){
        if(minus) total-= nums[i];
        else total+=nums[i];
        minus = !minus;
    }
    return total;
  }
}