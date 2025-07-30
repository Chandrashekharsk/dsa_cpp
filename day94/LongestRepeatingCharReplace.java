// 424. Longest Repeating Character Replacement

public class LongestRepeatingCharReplace {
  
  public static int characterReplacement(String s, int k) {
    int[] freq = new int[26];
    int mxFreq = 1, ans = 1;
    int left = 0, right = 0;

    while (right < s.length()) {
      ++freq[s.charAt(right) - 'A'];
      mxFreq = Integer.max(mxFreq, freq[s.charAt(right) - 'A']);

      int windowSize = (right-left)+1;
      if (( windowSize - mxFreq) > k){
        --freq[s.charAt(left)-'A'];
        ++left;
      }
      ans = Integer.max(ans, (right-left)+1);
      ++right;
    }
    return ans;
  }

  public static void main(String[] args) {
    // String s = "ABAB";
    String s = "AABABBA";
    int k = 1;
    System.out.println(characterReplacement(s, k));
  }
}
