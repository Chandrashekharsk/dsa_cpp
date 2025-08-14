// 17. Letter Combinations of a Phone Number
import java.util.ArrayList;
import java.util.List;

public class LetterCombinations {
  static String[] keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  private static void backtrack(List<String> ans, String digits, int idx, StringBuilder sb){
    if(idx == digits.length()){
      ans.add(sb.toString());
      return;
    }
    
    String s = keys[digits.charAt(idx)-'0'];
    for(char c: s.toCharArray()){
      backtrack(ans, digits, idx+1, sb.append(c));
      sb.deleteCharAt(sb.length() - 1); // backtrack
    }
  }

  public static List<String> letterCombinations(String digits) {
    List<String> ans = new ArrayList<>();
    if(digits.length() == 0 || digits.length()==1 && digits.charAt(0)-'0'==1) return ans;
    backtrack(ans, digits, 0, new StringBuilder());
    return ans;
  }

  public static void main(String[] args) {
    String digits = "13";
    // String digits = "31";
    for(String s : letterCombinations(digits)){
      System.out.println(s);
    }
  }
}
