// 22. Generate Parentheses
import java.util.ArrayList;
import java.util.List;

public class GenerateParenthesis {
  private static void helper( int ob, int cb, int n, StringBuilder str, List<String> ans){
    if(ob == n && cb == n){
      ans.add(str.toString());
      return;
    }

    if(ob<n){
      helper(ob+1, cb, n, str.append("("), ans);
      str.deleteCharAt(str.length() - 1); 
    }
    if(ob>cb){
      helper(ob, cb+1, n, str.append(")"), ans);
      str.deleteCharAt(str.length() - 1); 
    }
  }
  public static List<String> generateParenthesis(int n) {
    List<String> ans = new ArrayList<>();
    helper(0, 0, n, new StringBuilder(), ans);
    return ans;
  }
  public static void main(String[] args) {
    for(String s: generateParenthesis(2)){
      System.out.print(s+" ");
    }
  }
}
