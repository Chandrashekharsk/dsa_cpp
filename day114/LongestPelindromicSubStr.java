// 5. Longest Palindromic Substring

public class LongestPelindromicSubStr{
  private String expandAroudCenter(int left, int right, String s){
    while(left>=0 && right<=s.length()-1 && Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))){
      --left;
      ++right;
    }
    return s.substring(++left, right);
  }
  public String longestPalindrome(String s) {
    String ans = "";

    for(int i=0; i<s.length(); ++i){
      String pickEven = expandAroudCenter(i, i+1, s);
      String pickOdd = expandAroudCenter(i, i, s);
      String currMaxStr = pickEven.length()>pickOdd.length()? pickEven: pickOdd;
      ans = currMaxStr.length()>ans.length()? currMaxStr: ans;
    }
    return ans;
  }

  public static void main(String[] args) {
    LongestPelindromicSubStr lps = new LongestPelindromicSubStr();
    System.out.println(lps.longestPalindrome( "cbbd"));
  }
}