// 202. Happy Number
import java.util.HashSet;
import java.util.Set;

public class HappyNum {

  private static int calculateSumOfSquares(int n) {
    int sum = 0;
    while (n != 0) {
      int lastDigit = n % 10;
      sum += lastDigit * lastDigit;
      n = n / 10;
    }
    return sum;
  }

  public static boolean isHappy(int n) {
    // approach 1
    // Set<Integer> s = new HashSet<>();
    
    // while (n != 1 || !s.contains(n)) {
      //   n = calculateSumOfSquares(n);
      //   s.add(n);
      // }
      // if(n==1) return true;
      // return false;


      // approach 2 (Floyd's Cycle Detection - HARE TURTUL APPROACH)
      int fast = calculateSumOfSquares(calculateSumOfSquares(n));
      int slow = calculateSumOfSquares(n);
      while (fast != 1 && fast != slow) {
        fast = calculateSumOfSquares(calculateSumOfSquares(fast));
        slow = calculateSumOfSquares(slow);
      }

      return fast == 1;
  }

  public static void main(String[] args) {
    // System.out.println(isHappy(19));
    System.out.println(isHappy(2));
  }
}
