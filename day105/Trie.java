// 208. Implement Trie (Prefix Tree)

class TrieNode{
  TrieNode[] children;
  boolean isEndOfWord;
  public TrieNode(){
    children = new TrieNode[26];
    isEndOfWord = false;
  }
}

public class Trie{
  private TrieNode root;

  public Trie(){
    root = new TrieNode();
  }

  public void insert(String word) {
    TrieNode curr = root;
    for(char c: word.toCharArray()){
      int idx = c - 'a';
      if(curr.children[idx] == null) curr.children[idx] = new TrieNode();
      curr = curr.children[idx];
    }
    curr.isEndOfWord = true;
  }
  
  public boolean search(String word) {
    TrieNode curr = root;
    for(char c: word.toCharArray()){
      int idx = c - 'a';
      if(curr.children[idx] == null) return false;
      curr = curr.children[idx];
    }
    return curr.isEndOfWord;
  }
  
  public boolean startsWith(String prefix) {
    TrieNode curr = root;
    for(char c: prefix.toCharArray()){
      int idx = c - 'a';
      if(curr.children[idx] == null) return false;
      curr = curr.children[idx];
    }
    return true;
  }

  public static void main(String[] args) {
    Trie trie = new Trie();
    trie.insert("apple");
    System.out.println(trie.search("apple"));   // true
    System.out.println(trie.search("app"));     // false
    System.out.println(trie.startsWith("app")); // true
    trie.insert("app");
    System.out.println(trie.search("app"));     // true
  }
}
