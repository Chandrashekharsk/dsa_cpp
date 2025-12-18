// 90. Subsets II
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindSubsets2 {
  private List<List<Integer>> ans;
  private void helper(int i, int[] nums, List<Integer> curr){
    ans.add(new ArrayList<>(curr));

    for(int j=i; j<nums.length; ++j){
      if(j>i && nums[j]==nums[j-1]) continue;
      curr.add(nums[j]);
      helper(j+1, nums, curr);
      curr.remove(curr.size()-1);
    }
  }

  public List<List<Integer>> subsetsWithDup(int[] nums) {
    ans = new ArrayList<>();
    Arrays.sort(nums);
    helper(0, nums, new ArrayList<>());
    return ans;
  }

  public static void main(String[] args) {
    FindSubsets2 fs = new FindSubsets2();
    for(List<Integer> l: fs.subsetsWithDup(new int[]{1,2,2})){
      for(int i: l) System.out.print(i+" ");
      System.out.println();
    }
  }
}
