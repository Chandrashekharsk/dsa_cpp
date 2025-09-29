// 139. Word Break
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.HashSet;

public class WordBreak {
  public boolean wordBreak(String s, List<String> wordDict) {
    if(s.length() == 0) return true;
    Set<String> hs = new HashSet<>(wordDict);

    boolean[]dp = new boolean[s.length()+1];
    dp[0] = true;
    for(int i=1; i<=s.length(); ++i){
      for(int j=0; j<i; ++j){
        if(dp[j] && hs.contains(s.substring(j, i))){
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.length()];
  }

  public static void main(String[] args) {
    String s = "catsandog";
    // String s = "leetcode";
    List<String> wordDict = new ArrayList<>(List.of("cats","dog","sand","and","cat"));
    // List<String> wordDict = new ArrayList<>(List.of("leet","code"));

    WordBreak wb = new WordBreak();
    System.out.println(wb.wordBreak(s,wordDict));
  }
}
