// 5. Longest Palindromic Substring

public class LogestPalindromeSubStr {
  private static String expandAroundCenter(int left, int right, String s){
    while(left>=0 && right <s.length() && 
    Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))){
      --left;
      ++right;
    }
    return s.substring(left+1,right);
  }

  public static String longestPalindrome(String s) {
    String ans = "";
    for(int i=0; i<s.length(); ++i){
      String evenLenStr = expandAroundCenter(i, i+1, s);
      if(evenLenStr.length()>ans.length()) ans = evenLenStr;
      String oddStr = expandAroundCenter(i, i, s);
      if(oddStr.length()>ans.length()) ans = oddStr;
    }
    return ans;
  }

  public static void main(String[] args) {
    System.out.println(longestPalindrome("gabafd"));
    System.out.println("hell".substring(3+1, 3+1));
  }
}

