// 647. Palindromic Substrings
public class CountPalindromeStrs {

  private static int palindromeLen(int left, int right, String s){
    int cnt = 0;
    while(left>=0 && right<s.length() &&  
    Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))){
      ++cnt;
      --left; ++right;
    }
    return cnt;
  }

  public static int countSubstrings(String s) {
    int ans = 0, i=0; 
    while(i<s.length()){
      ans += palindromeLen(i, i+1, s);
      ans += palindromeLen(i, i, s);
      ++i;
    }

    return ans;
  }
  public static void main(String[] args) {

    System.out.println(countSubstrings("bcc"));   // 2 3 
  }
}
