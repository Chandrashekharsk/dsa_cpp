// 1249. Minimum Remove to Make Valid Parentheses
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class MinRemToMakeValidParentheses {
  public static String minRemoveToMakeValid(String s) {
    Stack<Integer> stk = new Stack<>();
    Set<Integer> st =  new HashSet<>();
    for(int i=0; i<s.length(); ++i){
      char c = s.charAt(i);
      if(c =='(') stk.push(i);
      if(c == ')'){
        if(!stk.isEmpty() && s.charAt(stk.peek()) == '(') stk.pop();
        else st.add(i);
      }
    }
    while(!stk.isEmpty()) st.add(stk.pop());
    StringBuilder sb = new StringBuilder();
    for(int i=0; i<s.length(); ++i){
      if(!st.contains(i)) sb.append(s.charAt(i));
    }
    return sb.toString();
  }

  public static void main(String[] args) {
    // System.out.println(minRemoveToMakeValid("lee(t(c)o)de)"));
    System.out.println(minRemoveToMakeValid("(a)b(c)d)"));
  }
}
