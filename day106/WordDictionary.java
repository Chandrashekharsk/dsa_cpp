// 211. Design Add and Search Words Data Structure
import java.util.HashMap;
import java.util.Map;

class TrieNode{
  Map<Character, TrieNode> m;
  boolean isEndOfWord;
  public TrieNode(){
    m = new HashMap<>();
    isEndOfWord = false;
  }
}

public class WordDictionary {
  TrieNode root;
  public WordDictionary() {
    root = new TrieNode();
  }

  public void addWord(String word) {
    TrieNode curr = root;
    for(char c: word.toCharArray()){
      curr = curr.m.computeIfAbsent(c, k-> new TrieNode());
    }
    curr.isEndOfWord = true;
  }

  private boolean helper(String word, int idx, TrieNode root) {
    if (idx == word.length()) return root.isEndOfWord;
    TrieNode curr = root;
    char c = word.charAt(idx);

    if(c == '.'){
      for(TrieNode child: curr.m.values()){
        if(helper(word, idx+1, child)) return true;
      }
      return false;
    }else{
      TrieNode nextNode = curr.m.get(c);
      if(nextNode == null) return false;
      return helper(word, idx+1, nextNode);
    }
  }
  public boolean search(String word) {
    return helper(word,0, root);
  }

  public static void main(String[] args) {
    WordDictionary wd = new WordDictionary();

    // Add words
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");

    // Search test cases
    System.out.println(wd.search("pad")); // false (not added)
    System.out.println(wd.search("bad")); // true
    System.out.println(wd.search(".ad")); // true (matches "bad", "dad", "mad")
    System.out.println(wd.search("b..")); // true (matches "bad")
    System.out.println(wd.search("..d")); // true (matches "bad", "dad", "mad")
    System.out.println(wd.search("b.d")); // true (matches "bad")
    System.out.println(wd.search("ba.")); // true (matches "bad")
    System.out.println(wd.search("ma.")); // true (matches "mad")
    System.out.println(wd.search("da.")); // true (matches "dad")
  }
}
