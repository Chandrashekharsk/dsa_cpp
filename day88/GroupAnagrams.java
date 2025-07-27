// 49. Group Anagrams
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

import java.util.List;
import java.util.Map;

public class GroupAnagrams {
  public List<List<String>> groupAnagrams(String[] strs) {
    Map<String,List<String>> m = new HashMap<>();
    for(String s: strs){
      char[] charsArr = s.toCharArray();
      Arrays.sort(charsArr);

      String sortedStr = new String(charsArr);
      if(!m.containsKey(sortedStr)){
        m.put(sortedStr, new ArrayList<>());
      }
      m.get(sortedStr).add(s);
    }
    return new ArrayList<>(m.values());
  }

   public static void main(String[] args) {
    GroupAnagrams ga = new GroupAnagrams();
    String[] input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    List<List<String>> result = ga.groupAnagrams(input);
    System.out.println("Grouped Anagrams:");
    for (List<String> group : result) {
      System.out.println(group);
    }
  }
}
