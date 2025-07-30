// 14. Longest Common Prefix
import java.util.HashSet;
import java.util.Set;

public class LongestCommPrefix {
  public static String longestCommonPrefix(String[] strs) {
    // approach 1
    if (strs == null || strs.length == 0)
      return "";
    int baseStrLen = strs[0].length();
    for (int i = 1; i < strs.length; ++i) {
      int j = 0;
      while (j < baseStrLen && j < strs[i].length() && strs[0].charAt(j) == strs[i].charAt(j)) {
        ++j;
      }
      baseStrLen = j;
      if (baseStrLen == 0)
        return "";
    }
    return baseStrLen == strs[0].length() ? strs[0] : strs[0].substring(0, baseStrLen);

    // approach 2
    // if (strs == null || strs.length == 0) return "";
    // for(int i=0; i<strs[0].length(); ++i){
    // for(int j=1; j<strs.length; ++j){
    // if(i>=strs[j].length() || strs[j].charAt(i) != strs[0].charAt(i)) return
    // strs[0].substring(0, i);
    // }
    // }
    // return strs[0];
  }

  public static String solution(String s) {
    Set<Character> st = new HashSet<>();
    for (int i = 0; i < 26; ++i)  st.add((char)('a'+i));
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < s.length(); ++i) {
      if (st.contains(s.charAt(i))) sb.append(s.charAt(i));
      else if (s.charAt(i) == '[') {
        ++i;
        if (s.charAt(i) == ']') sb.append('a');
      }
    }
    return sb.toString();
  }

  public static void main(String[] args) {
    String[] strs = { "flower", "flow", "flight" };

    // System.out.println(longestCommonPrefix(strs));
    System.out.println(solution("@jo]y[]]]"));
  }
}