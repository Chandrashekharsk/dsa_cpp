// 32. Longest Valid Parentheses
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class LongestValidParentheses {
  public static int longestValidParentheses(String s) {
    Stack<Integer> stk = new Stack<>();
    int maxCnt = 0;
    stk.add(-1);
    for(int i=0; i<s.length(); ++i){
      char c = s.charAt(i);
      if(c ==')'){  
        stk.pop();
        if(stk.isEmpty()) stk.add(i);
        else maxCnt = Integer.max(maxCnt, i-stk.peek());
      }else stk.add(i);
    }
    return maxCnt;
  }

  public static void main(String[] args) {
    System.out.println(longestValidParentheses("))))))(()(((("));
  }
}
