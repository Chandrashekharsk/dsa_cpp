import java.util.HashMap;
import java.util.Map;

public class Factorial {
  Map<Integer,Integer> m = new HashMap<>();
  int findFactorial(int n){
    if(n<=1) return 1;
    if(m.containsKey(n)) return m.get(m);
    int res = n * findFactorial(n-1);
    m.put(n, res);
    return res;
  }
  public static void main(String[] args) {
    Factorial f = new Factorial();
    System.out.println(f.findFactorial(3));
  }
}
