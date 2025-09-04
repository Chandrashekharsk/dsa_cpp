// 212. Word Search II
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;



public class WordSearch2 {

  // approach 1 - USING HASHMAP & ALL POSSIBLE DIRECTIONS TRAVERSAL 
  // private boolean helper(char[][] board,int r, int c, int idx, String word, boolean vis[][]){
  //   if(idx==word.length()) return true;
  //   if (r < 0 || c < 0 || r >= board.length || c >= board[0].length) return false;
  //   if (vis[r][c] || board[r][c] != word.charAt(idx)) return false;
  
  //   vis[r][c] = true;
  //   int[] dr = {-1, 1, 0, 0};
  //   int[] dc = {0, 0, -1, 1};
  //   for(int d=0; d<4; ++d){
  //     int nr = r + dr[d], nc = c + dc[d];
  //     if(helper(board, nr, nc, idx+1, word, vis)){
  //       vis[r][c] = false; // backtrack
  //       return true;
  //     }
  //   }

  //   vis[r][c] = false; // backtrack
  //   return false;
  // }
  // public List<String> findWords(char[][] board, String[] words) {
  //   Set<String> s = new HashSet<>();

  //   for(String word: words){
  //     for(int i=0; i<board.length ; ++i){
  //       for(int j=0; j<board[0].length ; ++j){
  //           if(board[i][j]==word.charAt(0)){
  //           boolean vis[][] = new boolean[board.length][board[0].length];
  //           if(helper(board, i, j, 0, word, vis)) s.add(word);
  //         }
  //       }
  //     }
  //   }
  //   return new ArrayList<>(s);
  // }


  // approach 2 - USING TRIE
  private class TrieNode  {
    TrieNode[] children;
    String word;
    public TrieNode(){
      children = new TrieNode[26];
      word = null;
    }
  }

  private TrieNode buildTrie(String[] words){
    TrieNode root = new TrieNode();
    for(String w: words){
      TrieNode curr = root;

      for(char c: w.toCharArray()){
        int idx = c-'a';
        if(curr.children[idx] == null) curr.children[idx] = new TrieNode();
        curr = curr.children[idx];
      }
      curr.word = w;
    }
    return root;
  }
  private void helper(char[][] board, int r, int c, TrieNode root, Set<String> ans){
    char ch = board[r][c];
    if(board[r][c] == '#' || root.children[ch-'a']== null) return;
    TrieNode curr = root.children[ch-'a'];
    if(curr.word != null){
      ans.add(curr.word);
      curr.word = null; // avoid duplicate word
    }
    board[r][c] = '#';
    
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    for(int i=0; i<4; ++i){
      int nr = r + dr[i], nc = c + dc[i];
      if(nr>=0 && nc>=0 && nr<board.length && nc <board[0].length){
        helper(board, nr, nc, curr, ans);
      }
    }
    board[r][c] = ch;
  }
  public List<String> findWords(char[][] board, String[] words) {
    TrieNode root = buildTrie(words);
    Set<String> ans = new HashSet<>();
    
    for(int i=0; i<board.length; ++i){
      for(int j=0; j<board[0].length; ++j){
        helper(board, i, j, root, ans);
      }
    }
    
    return new ArrayList<>(ans);
  }

  public static void main(String[] args) {
    WordSearch2 ws = new WordSearch2();
      char[][] board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
      };
      String[] words = {"oath", "pea", "eat", "rain"};
      List<String> res = ws.findWords(board, words);
      System.out.println("Words found: " + res);
      // Expected Output: ["oath", "eat"]
  }
}