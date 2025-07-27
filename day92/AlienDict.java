// 953. Verifying an Alien Dictionary
import java.util.HashMap;
import java.util.Map;

public class AlienDict{
  public boolean isAlienSorted(String[] words, String order) {

    Map<Character, Integer> m = new HashMap<>();
    int idx = 0;
    for(char c : order.toCharArray()){
      m.put(c, idx);
      ++idx;
    }

    for(int i=0; i<words.length-1; ++i){
      String s1 = words[i];
      String s2 = words[i+1];
      for(int j=0; j<s1.length(); ++j){
        if(j>=s2.length()) return false;
        int c1 = m.get(s1.charAt(j)), c2 = m.get(s2.charAt(j));
        if(c1<c2) break;
        else if(c1>c2) return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    AlienDict checker = new AlienDict();

    String[] words1 = {"hello", "leetcode"};
    String order1 = "hlabcdefgijkmnopqrstuvwxyz";
    System.out.println("Test 1: " + checker.isAlienSorted(words1, order1)); // true

    String[] words2 = {"word", "world", "row"};
    String order2 = "worldabcefghijkmnpqstuvxyz";
    System.out.println("Test 2: " + checker.isAlienSorted(words2, order2)); // false

    String[] words3 = {"apple", "app"};
    String order3 = "abcdefghijklmnopqrstuvwxyz";
    System.out.println("Test 3: " + checker.isAlienSorted(words3, order3)); // false

    String[] words4 = {"app", "apple"};
    String order4 = "abcdefghijklmnopqrstuvwxyz";
    System.out.println("Test 4: " + checker.isAlienSorted(words4, order4)); // true

    String[] words5 = {"ku", "kuz", "kuzz"};
    String order5 = "abcdefghijklmnopqrstuvwxyz";
    System.out.println("Test 5: " + checker.isAlienSorted(words5, order5)); // true

    String[] words6 = {"a", "b", "c"};
    String order6 = "abcdefghijklmnopqrstuvwxyz";
    System.out.println("Test 6: " + checker.isAlienSorted(words6, order6)); // true

    String[] words7 = {"z", "x"};
    String order7 = "zyxwvutsrqponmlkjihgfedcba";
    System.out.println("Test 7: " + checker.isAlienSorted(words7, order7)); // true
  }
}