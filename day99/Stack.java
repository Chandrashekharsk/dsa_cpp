import java.util.ArrayList;
import java.util.List;

public class Stack {
  List<Integer> l;
  public Stack(){
    l = new ArrayList<>();
  }
  public Integer peek(){
    return l.isEmpty()? null :  l.get(l.size()-1);
  }
  public void push(int n){
    l.addLast(n);
  }
  public Integer pop(){
    return l.isEmpty()? null: l.remove(l.size()-1);
  }

  public static void main(String[] args) {
    Stack s = new Stack();
    System.out.println(s.peek());
    s.push(1);
    s.push(4);
    s.push(3);
    System.out.println(s.peek());
    s.pop();
    System.out.println(s.peek());
  }
}
