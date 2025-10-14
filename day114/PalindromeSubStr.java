// 647. Palindromic Substrings

public class PalindromeSubStr {
  private int expandAroudCenter(int left, int right, String s){
    int cnt = 0;
    while(left>=0 && right<=s.length()-1 && Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))){
      ++cnt;
      --left;
      ++right;
    }
    return cnt;
  }
  public int countSubstrings(String s) {
    int MaxCnt = 0;
    for(int i=0; i<s.length(); ++i){
      MaxCnt += expandAroudCenter(i, i+1, s);
      MaxCnt += expandAroudCenter(i, i, s);
    }
    return MaxCnt;
  }
  public static void main(String[] args) {
    PalindromeSubStr ps = new PalindromeSubStr();
    System.out.println(ps.countSubstrings("aaa"));
  }
}
