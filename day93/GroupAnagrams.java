// 49. Group Anagrams

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GroupAnagrams {
  public  static List<List<String>> groupAnagrams(String[] strs){
    // approach 1
    // Map<String, List<String>> m  = new HashMap<>();

    // for(String s : strs){
    //   char[] temp = s.toCharArray();
    //   Arrays.sort(temp);

    //   String key = new String (temp);
    //   if(!m.containsKey(key)) m.put(key.toString(), new ArrayList<>() );
    //   m.get(key.toString()).add(s);
    // }
    // return new ArrayList<>(m.values());


    // approach 2
    Map<String, List<String>> m  = new HashMap<>();

    for(String s : strs){
      int[] freq = new int[26];
      for(char c: s.toCharArray()) ++freq[c-'a'];
      StringBuilder sb = new StringBuilder();
      for(int f: freq) sb.append(f).append("#");
      String key = sb.toString();

      // if(!m.containsKey(key)) m.put(key.toString(), new ArrayList<>() );
      // m.get(key.toString()).add(s);
      m.computeIfAbsent(key, k-> new ArrayList<>()).add(s);
    }
    return new ArrayList<>(m.values());
  }
  public static void main(String[] args) {
    String[] strs = {"eat","tea","tan","ate","nat","bat"};
    for(List<String> list : groupAnagrams(strs)){
      System.out.print("[ ");
      for(String s: list) System.out.print(s+" ");
      System.out.println("]");
    }
  }
}
