// 76. Minimum Window Substring
import java.util.HashMap;
import java.util.Map;

public class MinWindowSubstr {
  public static String minWindow(String s, String t) {
    Map<Character, Integer> tm = new HashMap<>(), sm = new HashMap<>();
    for (char c : t.toCharArray()) tm.put(c, tm.getOrDefault(c, 0) + 1);
    int left = 0, right = 0, sUnique = 0, tUnique = tm.size(), minLen = Integer.MAX_VALUE;
    int startIdx = 0;

    while (right < s.length()) {
      char c = s.charAt(right);
      sm.put(c, sm.getOrDefault(c, 0)+1);
      // if(tm.containsKey(c) && sm.get(c).intValue() == tm.get(c).intValue()) ++sUnique;
      if(tm.containsKey(c) && sm.get(c).equals(tm.get(c))) ++sUnique;

      while(sUnique == tUnique){
        // shrink till valid String
        if(right-left+1<minLen){
          startIdx = left;
          minLen = right-left+1;
        }

        char leftChar = s.charAt(left);
        sm.put(leftChar, sm.get(leftChar)-1);
        if(tm.containsKey(leftChar) && tm.get(leftChar)>sm.get(leftChar)) --sUnique;
        ++left;
      }

      ++right;
    }
    return minLen == Integer.MAX_VALUE? "": s.substring(startIdx, startIdx+minLen);
  }

  public static void main(String[] args) {
    String s = "ADOBECODEBANC", t = "ABC";
    System.out.println(minWindow(s, t));
  }
}
