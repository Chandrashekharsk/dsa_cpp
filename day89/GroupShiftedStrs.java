// 249. Group Shifted Strings
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GroupShiftedStrs{
  public static List<List<String>> groupShifting(String[] strs){
    Map<String,List<String>> m = new HashMap<>();
    for(String s: strs){
      StringBuilder key = new StringBuilder();
      for(int i=1; i<s.length(); ++i){
        int diff = s.charAt(i) - s.charAt(i-1);
        if(diff<0) diff+=26;
        key.append(diff).append(",");
      }
      String pattern = key.toString();
      m.computeIfAbsent(pattern, k -> new ArrayList<>()).add(s);
    }
    return new ArrayList<>(m.values());
  }
  public static void main(String[] args) {
    // Sample input
    String[] input = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    List<List<String>> result = groupShifting(input);
    System.out.println(result);
  }
}

