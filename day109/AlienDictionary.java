// 269.Alien Dictionary

import java.util.HashMap;
import java.util.HashSet;

import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class AlienDictionary {
  public String findOrder(String[] words){
    Map<Character, Set<Character>> graph = new HashMap<>(); // dependency graph
    Map<Character, Integer> indegree = new HashMap<>();   // unique character
    Set<Character> s = new HashSet<>();

    for(String w: words){
      for(char c: w.toCharArray()){
        graph.putIfAbsent(c, new HashSet<>());
        indegree.putIfAbsent(c, 0);
      }
    }

    for(int i=0; i<words.length-1; ++i){
      String w1 = words[i];
      String w2 = words[i+1];
      if(w1.length()>w2.length() && w1.startsWith(w2)) return "";

      for(int j=0; j<Math.min(w1.length(), w2.length()); ++j){
        char c1 = w1.charAt(j), c2 = w2.charAt(j);
        if( c1 != c2){
          if(!graph.get(c1).contains(c2)){
            graph.get(c1).add(c2);
            indegree.put(c2, indegree.get(c2)+1);
          }
          break;
        }
      }
    }

    Queue<Character> q = new LinkedList<>();
    for(char c: indegree.keySet()){
      if(indegree.get(c) == 0) q.offer(c);
    }
    StringBuilder sb  = new StringBuilder();
    while (!q.isEmpty()) {
      char curr = q.poll();
      sb.append(curr);
      for(char nei: graph.get(curr)){
        indegree.put(nei, indegree.get(nei)-1);
        if(indegree.get(nei)==0) q.offer(nei);
      }
    }

    return sb.length() < indegree.size() ? "" : sb.toString();
  }

  public static void main(String[] args) {
    String[] words = {"hr", "hp", "td"};
    AlienDictionary ad = new AlienDictionary();
    System.out.println(ad.findOrder(words));
  }
}
