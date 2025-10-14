import java.util.ArrayList;
import java.util.List;

public class DecimalRepresentaion{

  public int[] decimalRepresentation(int n) {
    String s = Integer.toString(n);
    int len = s.length();

    List<Integer> ans = new ArrayList<>();
  
    for(int i = 0; i<len; ++i){
      char c = s.charAt(i);
      int digit = (int) c-'0';
      if(digit == 0) continue;
      digit = (int) (digit * Math.pow(10, len-i-1));
      ans.add(digit);
    }
    int[] temp = new int[ans.size()];
    int idx = 0;
    while(idx<ans.size()) temp[idx] = ans.get(idx++);
    return temp;
  }

  public static void main(String[] args) {
    DecimalRepresentaion dr = new DecimalRepresentaion();
    for(int n: dr.decimalRepresentation( 102)){
      System.out.print(n+" ");
    }
  }
}