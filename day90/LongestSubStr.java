// 3. Longest Substring Without Repeating Characters
import java.util.HashSet;
import java.util.Set;

public class LongestSubStr {

  public static int lengthOfLongestSubstring(String s) {
    Set<Character> st = new HashSet<>();
    int ml = 0,left = 0, right = 0, i= 0;
    
    while(right<s.length()){
      char c = s.charAt(right);
      if(!st.contains(c)){
        st.add(c);
        ++right;
        ml = Math.max(ml, right-left);
      }else{
        st.remove(s.charAt(left));
        ++left;
      }
    }
    return ml;
  }

  public static void main(String[] args) {
    // String s = "carrace2";
    String s = "dvdf";
    System.out.println(lengthOfLongestSubstring(s));
  }
}
