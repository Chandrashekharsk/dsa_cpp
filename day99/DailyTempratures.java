// 739. Daily Temperatures
import java.util.Stack;

public class DailyTempratures {
  public static int[] dailyTemperatures(int[] temperatures) {
    Stack<Integer> s = new Stack<>();
    int[] ans = new int[temperatures.length];
    for(int i=temperatures.length-1; i>=0; --i){
      while(!s.empty() && temperatures[s.peek()]<= temperatures[i]) s.pop();
      ans[i] = s.isEmpty()? 0: s.peek()-i;
      
      s.push(i);
    }
    return ans;
  }

  public static void main(String[] args) {
    for(int i: dailyTemperatures(new int[]{73,74,75,71,69,72,76,73})){
      System.out.print(i+" ");
    }
  }
}
