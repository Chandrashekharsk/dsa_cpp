// 125. Valid Palindrome
public class ValidPalindrome{

  public static boolean isPalindrome(String s){
    // approach 1
    // int st = 0, end = s.length()-1;
    // while(st<end){
    //   if(s.charAt(st) != s.charAt(end)) return false;
    //   ++st; --end;
    // }
    // return true;


    // approach 2 (complex error handling)
    int st = 0, end = s.length()-1;
    while(st<end){
      while(st<end && !Character.isLetterOrDigit(s.charAt(st))) ++st;
      while(st<end && !Character.isLetterOrDigit(s.charAt(end))) --end;
      if (Character.toLowerCase(s.charAt(st)) != Character.toLowerCase(s.charAt(end))) return false;

      ++st; --end;
    }
    return true;


    // approach 3 (complex error handling)
    // int idx = 0;
    // StringBuilder sb = new StringBuilder();
    // while(idx<s.length()){
    //   if(Character.isLetterOrDigit(s.charAt(idx))) sb.append(Character.toLowerCase(s.charAt(idx)));
      
    //   ++idx;
    // }
    // String processedStr = sb.toString();
    // String reversedStr = sb.reverse().toString();
    // return processedStr.equals(reversedStr);
  }

  public static void main(String[] args) {
    String s = "niti n";
    System.out.println(isPalindrome(s));
  }
}