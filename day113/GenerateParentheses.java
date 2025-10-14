// 22. Generate Parentheses

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GenerateParentheses {
  private void helper(int open, int close, StringBuilder curr, int n){
    if(open==close && open+close == 2*n){
      ans.add(curr.toString());
      return;
    }

    if(open<n) {
      curr.append("(");                  // choose "("
      helper(open + 1, close, curr, n);
      curr.deleteCharAt(curr.length() - 1); // backtrack
    }
    if(close<open){
      curr.append(")");
      helper(open, close+1, curr, n);
      curr.deleteCharAt(curr.length()-1);
    }
  }
  private List<String> ans;
  public List<String> generateParenthesis(int n){
    ans = new ArrayList<>();
    helper(0, 0, new StringBuilder(), n);
    return ans;
  }


  private List<String> helper2(int n){
    if(n==0)return List.of("");
    if(memo.containsKey(n))return memo.get(n);

    List<String> res = new ArrayList<>();
    for(int left=0; left<n; ++left){
      List<String> leftString = helper2(left);
      List<String> righString = helper2(n-1-left);
      for (String l : leftString) {
        for (String r : righString) {
          res.add("(" + l + ")" + r);
        }
      }
    }
    memo.put(n, res);
    return res;
  }
  Map<Integer, List<String>> memo;
  public List<String> generateParenthesis2(int n){
    memo = new HashMap<>();
    return helper2(n);
  }

  public List<String> generateParenthesis3(int n){
    List<List<String>> dp = new ArrayList<>();
    dp.add(Arrays.asList(""));   // base: dp[0] = [""]

    for(int idx=1; idx<=n; ++idx){
      List<String> curr = new ArrayList<>();

      for(int left=0; left<idx; ++left){
        List<String> leftPart = dp.get(left);
        List<String> rightPart = dp.get(idx-1-left);
        for(String l: leftPart){
          for(String r: rightPart){
            curr.add("("+l+")"+r);
          }
        }
      }
      dp.add(curr);
    }
    return dp.get(n);
  }

  public static void main(String[] args) {
    GenerateParentheses gp = new GenerateParentheses();
    for(String s: gp.generateParenthesis3(3)){
      System.out.print(s+" ");
    }
  }
}
