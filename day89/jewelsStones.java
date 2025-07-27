// 771. Jewels and Stones
import java.util.HashSet;
import java.util.Set;

public class jewelsStones {
  public static int numJewelsInStones(String jewels, String stones) {
    // approach 1
    // Set<Character> s = new HashSet<>();
    // int count = 0;
    // for(int i=0; i<jewels.length(); ++i) s.add(jewels.charAt(i));
    
    // for(int i=0; i<stones.length(); ++i) if(s.contains(stones.charAt(i))) ++count;
    // return count;

    // approach 2
    // All characters are letters (a–z, A–Z) → fits in ASCII range 65–122
    int size = 122-65 +1, cnt = 0;
    boolean[] isValid = new boolean[size];
    for(char c: jewels.toCharArray()) isValid[c - 'A'] = true;
    for(char c: stones.toCharArray()) if(isValid[c-'A']) ++cnt;

    return cnt;
  }

  public static void main(String[] args) {
    String jewels = "aA";
    String stones = "aAAbbbb";
    System.out.println(numJewelsInStones(jewels, stones));
  }
}
