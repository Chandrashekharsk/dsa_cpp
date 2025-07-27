// 205. Isomorphic Strings 
import java.util.HashMap;
import java.util.Map;

public class IsomorphiStr{

  private static String helper(String str){
    Map<Character, Integer> m = new HashMap<>();
    StringBuilder sb = new StringBuilder();

    for(int i=0; i<str.length(); ++i){
      if(!m.containsKey(str.charAt(i))){
        m.put(str.charAt(i), i);
      }
      sb.append(m.get(str.charAt(i)) + " ");
    }
    return sb.toString();
  }
  public static boolean isIsomorphic(String s, String t) {

    // approach 1
    // String ss = helper(s);   
    // String ts = helper(t);
    // return ss.equals(ts);   

    // approach 2
    Map<Character, Character> m1 = new HashMap<>();
    Map<Character, Character> m2 = new HashMap<>();

    for(int i=0; i<s.length(); ++i){
      Character c1 = s.charAt(i), c2 = t.charAt(i);
      if(m1.containsKey(c1) && m1.get(c1) != c2 || m2.containsKey(c2) && m2.get(c2) != c1){
        return false;
      }
      m1.put(c1, c2);
      m2.put(c2, c1);
    }
    return true;
  }
  public static void main(String[] args) {
    String s1 = "badc";
    String s2 = "baba";
    // String s1 = "foo";
    // String s2 = "bar";
    System.out.println(isIsomorphic(s1, s2));
  }
}