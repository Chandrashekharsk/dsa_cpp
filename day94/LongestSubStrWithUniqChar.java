// 3. Longest Substring Without Repeating Characters
import java.util.HashMap;
import java.util.Map;


public class LongestSubStrWithUniqChar {
  public static int lengthOfLongestSubstring(String s){
    int left = 0, right = 0, maxLen = 0;
    Map<Character,Integer> m = new HashMap<>();

    while(right<s.length()){
      char c = s.charAt(right);
      if(m.containsKey(c)) left = Integer.max(left, m.get(c) +1); 
      m.put(c, right);
      maxLen = Integer.max(maxLen, right-left+1);
      ++right;
    }
    return maxLen;
  }

  public static void main(String[] args) {
    System.out.println(lengthOfLongestSubstring("abcacbb"));
  }
}
