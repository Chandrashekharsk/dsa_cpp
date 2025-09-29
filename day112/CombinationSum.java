// 39. Combination Sum
import java.util.*;

class CombinationSum {

  // private Map<String, List<List<Integer>>> memo;
  // public List<List<Integer>> combinationSum(int[] candidates, int target) {
  //   memo = new HashMap<>();
  //   return dfs(0, target, candidates);
  // }

  // private List<List<Integer>> dfs(int idx, int target, int[] candidates) {
  //   if (idx == candidates.length) {
  //     if (target == 0) return Arrays.asList(new ArrayList<>());
  //     return new ArrayList<>();
  //   }

  //   String key = idx + "," + target;
  //   if (memo.containsKey(key)) return memo.get(key);
  //   List<List<Integer>> res = new ArrayList<>();

  //   // Pick
  //   if (candidates[idx] <= target) {
  //     for (List<Integer> comb : dfs(idx, target - candidates[idx], candidates)) {
  //       List<Integer> newComb = new ArrayList<>(comb);
  //       newComb.add(candidates[idx]);
  //       res.add(newComb);
  //     }
  //   }

  //   // Not Pick
  //   res.addAll(dfs(idx + 1, target, candidates));
  //   memo.put(key, res);
  //   return res;
  // }

  // private void helper(int idx, int[] candidates, int target, List<Integer>
  // curr, List<List<Integer>> ans){
  // if(idx == candidates.length){
  // if(target == 0) ans.add(new ArrayList<>(curr)); // create copy
  // return;
  // }
  // // pick
  // if(candidates[idx] <= target){
  // curr.add(candidates[idx]);
  // helper(idx, candidates, target - candidates[idx], curr, ans);
  // curr.remove(curr.size() - 1);
  // }
  // // not pick
  // helper(idx + 1, candidates, target, curr, ans);
  // }

  // public List<List<Integer>> combinationSum(int[] candidates, int target) {
  // List<List<Integer>> ans = new ArrayList<>();
  // helper(0, candidates, target, new ArrayList<>(), ans);
  // return ans;
  // }

  public List<List<Integer>> combinationSum(int[] candidates, int target) {
    List<List<List<Integer>>> dp = new ArrayList<>(target + 1);
    for(int i=0; i<=target; ++i) dp.add(new ArrayList<>());
    dp.get(0).add(new ArrayList<>());

    for(int curr: candidates){
      for(int t=curr; t<=target; ++t){
        for(List<Integer> comb: dp.get(t-curr)){
          List<Integer> tempComb = new ArrayList<>(comb);
          tempComb.add(curr);
          dp.get(t).add(tempComb);
        }
      }
    }
    return dp.get(target);
  }

  public static void main(String[] args) {
    CombinationSum cs = new CombinationSum();

    // ✅ Sample input
    int[] candidates = { 2, 3, 6, 7 };
    int target = 7;

    // ✅ Get combinations
    List<List<Integer>> result = cs.combinationSum(candidates, target);

    // ✅ Print output
    System.out.println("Combinations that sum to " + target + ": " + result);
  }
}
