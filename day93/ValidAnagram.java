// 242. Valid Anagram
import java.util.HashMap;
import java.util.Map;

public class ValidAnagram{
  public static boolean isAnagram(String s, String t) {
    // approach 1
    // if(s.length() != t.length()) return false;
    // Map<Character,Integer> m = new HashMap<>();
    
    // for(char c: s.toCharArray()) m.put(c, m.getOrDefault(c, 0)+1);
    // for(char c: t.toCharArray()){
    //   if(!m.containsKey(c) || m.get(c)==0) return false;
    //   m.put(c, m.get(c)-1);
    // }

    // for(int val: m.values()){
    //   if(val != 0) return false;
    // }
    // return true;


    // approach 2
    if(s.length() != t.length()) return false;
    int[] freq = new int[26];

    for(int i=0; i<s.length(); ++i){
      ++freq[(int) s.charAt(i)-'a'];
      --freq[(int) t.charAt(i)-'a'];
    }
    for(int n: freq) if (n!= 0) return false;
    return true;
  }
  
  public static void main(String[] args) {
    // String  s = "anagram", t = "nagaram";
    String  s = "rat", t = "car";
    System.out.println(isAnagram(s, t));
  }
}