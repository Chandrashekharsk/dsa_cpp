// 509. Fibonacci Number
import java.util.HashMap;
import java.util.Map;

public class RecursionIntro{
  Map<Integer, Integer> m = new HashMap<>();
  int fibOfNthTerm(int n){
    if(n<=1) return n;
    if(m.containsKey(n))return m.get(n);
    int res = fibOfNthTerm(n-1)+fibOfNthTerm(n-2);
    m.put(n, res);
    return res;
  }

  public static void main(String[] args) {
    RecursionIntro obj = new RecursionIntro();
    System.out.println(obj.fibOfNthTerm(3));
  }
}