// 288. Unique Word Abbreviation

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class uniqueWordAbbr {
  Map<String, Integer> m; 
  Set<String> s; 
  public uniqueWordAbbr(String[] dict){
    m = new HashMap<>();
    s = new HashSet<>();
    for(String str : dict){
      if(s.contains(str)) continue;
      String abb = getAbbr(str);
      m.put(abb, m.getOrDefault(abb, 0)+1);
      s.add(str);
    }
  }
  private String getAbbr(String s){
    int length  = s.length();
    if(length <= 2) return s;
    return s.charAt(0) + Integer.toString(length-2) + s.charAt(length-1);
  }

  public boolean isUniqueWord(String word){
    String abbr = getAbbr(word);
    if(m.containsKey(abbr) && (m.get(abbr) != 1 || !s.contains(word))) return false;
    return true;
  }
  public static void main(String[] args) {
    String[] dict = {"deer", "door", "cake", "card"};
    uniqueWordAbbr obj = new uniqueWordAbbr(dict);
    String[] testWords = {"dear", "cart", "cane", "make", "cake", "deer"};
    for(String word : testWords) {
      System.out.println("isUniqueWord(\"" + word + "\"): " + obj.isUniqueWord(word));
    }
  }
}
