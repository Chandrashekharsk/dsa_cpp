// 78. Subsets
import java.util.ArrayList;
import java.util.List;

public class FindSubsets {
  private static List<List<Integer>> ans;
  void helper(int i, int[] nums, List<Integer> curr){
    if(i==nums.length){
      ans.add(new ArrayList<>(curr));
      return;
    }
    helper(i+1, nums, curr);
    curr.add(nums[i]);
    helper(i+1, nums, curr);
    curr.remove(curr.size()-1);
  }
  public List<List<Integer>> subsets(int[] nums) {
    ans = new ArrayList<>();
    List<Integer> curr = new ArrayList<>();
    helper(0, nums, curr);
    return ans;
  }

  public static void main(String[] args) {
    FindSubsets fs = new FindSubsets();
    for(List<Integer> l: fs.subsets(new int[]{1,2,3})){
      for(int i: l) System.out.print(i+" ");
      System.out.println();
    }
  }
}
