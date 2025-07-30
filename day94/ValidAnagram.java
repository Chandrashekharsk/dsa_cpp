// 242. Valid Anagram
public class ValidAnagram {
  public static boolean isAnagram(String s, String t) {
    if(s.length()!= t.length()) return false;

    int[] freq = new int[26];
    for(int i=0; i<s.length(); ++i){
      ++freq[s.charAt(i)-'a'];
      --freq[t.charAt(i)-'a'];
    }
    for(int n : freq) if(n != 0) return false;
    return true;
  }

  public static void main(String[] args) {
    String s = "car", t = "roc";
    System.out.println(isAnagram(s, t));
  }
}
