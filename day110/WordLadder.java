// 127. Word Ladder
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

public class WordLadder{
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> s = new HashSet<>(wordList);
    if(!s.contains(endWord)) return 0;

    Queue<String> q = new LinkedList<>();
    q.offer(beginWord);
    int lvl = 1;

    while (!q.isEmpty()) {
      int size = q.size();

      for(int i=0; i<size; ++i){
        String curr = q.poll();
        if(curr.equals(endWord)) return lvl;

        char[] charArr = curr.toCharArray();
        for( int k = 0; k<charArr.length; ++k){
          char originalChar = charArr[k];
          for(char j = 'a'; j<='z'; ++j){
            if(j==originalChar) continue;
            charArr[k] = j;

            String newWord = new String(charArr);
            if(s.contains(newWord)){
              q.offer(newWord);
              s.remove(newWord);
            }
          }
          charArr[k] = originalChar;
        }
      }
      ++lvl;
    }
    return 0;
  }

  public static void main(String[] args) {
    WordLadder wl = new WordLadder();
    List<String> wordList = Arrays.asList("hot","dot","dog","lot","log","cog");
    String beginWord = "hit";
    String endWord = "cog";

    int result = wl.ladderLength(beginWord, endWord, wordList);
    System.out.println("Shortest transformation sequence length: " + result);
  }
}