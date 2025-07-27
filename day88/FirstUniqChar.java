// 387. First Unique Character in a String
import java.util.HashMap;
import java.util.Map;

public class FirstUniqChar{
  public static int findRestaurant(String s) {
    Map<Character, Integer> m = new HashMap<>();
    for(int i=0; i<s.length(); ++i){
      Character c = s.charAt(i);
      m.put(c, m.getOrDefault(c, 0)+1);
    }
    for(int i=0; i<s.length(); ++i) if(m.get(s.charAt(i))==1) return i;
    return -1;
  }
  public static void main(String[] args) {
    // String s = "leetcode";
    String s = "lolveleetcode";
    System.out.println(findRestaurant(s));
  }

}