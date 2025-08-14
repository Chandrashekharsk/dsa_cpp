// 150. Evaluate Reverse Polish Notation
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class ExpressionNotation {
  public static int evalRPN(String[] tokens) {
    Stack<String> stk = new Stack<>();
    Set<String> s = Set.of("+", "-", "*", "/");

    for (String str : tokens) {
      if (!s.contains(str)) {
        stk.push(str);
        continue;
      }
      int a = Integer.parseInt(stk.pop());
      int b = Integer.parseInt(stk.pop());

      int result = 0;
      if (str.equals("+")) result = b + a;
      else if (str.equals("-")) result = b - a;
      else if (str.equals("*")) result = b * a;
      else if (str.equals("/")) result = b / a;

      stk.push(Integer.toString(result));
    }
    return Integer.parseInt(stk.pop());
  }

  public static void main(String[] args) {
    System.out.println(evalRPN(new String[] { "4", "13", "5", "/", "+" }));
    // System.out.println(evalRPN(new String[]{"2","1","+","3","*"}));
  }
}
