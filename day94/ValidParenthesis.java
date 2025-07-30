// 20. Valid Parentheses
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Map;

public class ValidParenthesis {
  public static boolean isValid(String s) {
    // approach 1
    // if((s.length()&1)== 1) return false;
    // Deque<Character> st = new ArrayDeque<>();

    // for(int i=0; i<s.length(); ++i){
    //   char c = s.charAt(i);
    //   if(c == '(' || c == '{' || c == '[')  st.push(c);
    //   else{
    //     if(st.isEmpty()) return false;
    //     char top = st.pop();
    //     if((c == ')'&& top != '(') || (c=='}' && top !='{') || (c==']' && top !='[')) return false;
    //   } 
    // }
    // return st.isEmpty();

    
    // approach 2
    if((s.length()&1)== 1) return false;
    Deque<Character> st = new ArrayDeque<>();
    Map<Character, Character> m = Map.of(
      ')', '(',
      '}', '{',
      ']', '['
    );

    for(char c : s.toCharArray()){
      if(m.containsValue(c)) st.push(c);
      else if(m.containsKey(c)){
        if(st.isEmpty() || st.pop() != m.get(c)) return false;
      }else{
        return false;
      }
    }
    return st.isEmpty();
  }
  public static void main(String[] args) {
    System.out.println(isValid("([]("));
    System.out.println(isValid("()"));
  }
}
