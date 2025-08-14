// 155. Min Stack
import java.util.Stack;

class Pair{
  int first;
  int second;
  public Pair(int f, int s){
    first = f;
    second = s;
  }
}

class MinStack {
  Stack<Pair> s;

  public MinStack() {
    s = new Stack<>();
  }

  public void push(int val) {
    int minVal = s.isEmpty() ? val: Integer.min(s.peek().second, val);
    s.push(new Pair(val, minVal));
  };

  public void pop() {
    s.pop();
  }

  public int top() {
    return s.peek().first;
  }

  public int getMin() {
    return s.peek().second;
  }

  public static void main(String[] args) {
    MinStack ms = new MinStack();
    ms.push(-1);
    ms.push(0);
    ms.push(-3);
    System.out.println(ms.getMin());
    ms.pop();
    System.out.println(ms.top());
    System.out.println(ms.getMin());
  }
}