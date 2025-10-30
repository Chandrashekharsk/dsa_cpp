// 678. Valid Parenthesis String 

public class ValidParenthesisStr {
  public boolean checkValidString(String s) {
    int maxOpn = 0, minOpn = 0;
    for(char c: s.toCharArray()){
      if(c =='('){
        ++maxOpn; ++minOpn;
      }else if(c == ')'){
        --maxOpn; --minOpn;

      }else{
        ++maxOpn; --minOpn;
      }
      if(maxOpn<0)return false;
      minOpn = Math.max(0, minOpn);
    }
    return minOpn == 0;
  }
  public static void main(String[] args) {
    ValidParenthesisStr vps = new ValidParenthesisStr();
    System.out.println(vps.checkValidString("(((**)"));
  }
}
