// 210. Course Schedule II
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class CorseSeduleII {
  private boolean dfs(int course, Map<Integer, List<Integer>> m, int[] states,
  List<Integer> ans){
    if(states[course]==1) return false;
    if(states[course]==2) return true;

    states[course] = 1;
    for(int neighbour: m.get(course)){
      if(!dfs(neighbour, m, states, ans)) return false;
    }
    states[course] = 2;
    ans.add(course);
    return true;
  }
  public int[] findOrder2(int numCourses, int[][] prerequisites) {
    Map<Integer, List<Integer>>  m = new HashMap<>();
    for(int i=0; i<numCourses; ++i) m.put(i, new LinkedList<>());
    for(int[] pair: prerequisites) m.get(pair[1]).add(pair[0]);
    
    
    int[] states = new int[numCourses];
    List<Integer> ans = new ArrayList<>();
    for(int i=0; i<numCourses; ++i){
      if(states[i] == 0 && !dfs(i, m, states, ans)) return new int[]{};
    }
    Collections.reverse(ans);
    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  // USING TOPSORT (require DAG)
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    Map<Integer, List<Integer>>  m = new HashMap<>();
    for(int i=0; i<numCourses; ++i) m.put(i, new LinkedList<>());
    int[] indegree = new int[numCourses];
    for(int[] pair: prerequisites){
      m.get(pair[1]).add(pair[0]);
      ++indegree[pair[0]];
    }
    
    Queue<Integer> q = new LinkedList<>();
    for(int i=0; i<numCourses; ++i){
      if(indegree[i]==0) q.offer(i);
    }
    
    List<Integer> ans = new ArrayList<>();
    while (!q.isEmpty()) {
      int curr = q.poll();
      ans.add(curr);
      for(int n: m.get(curr)){
        --indegree[n];
        if(indegree[n] == 0) q.offer(n);
      }
    }
    if(ans.size() != numCourses) return new int[0];
    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  public static void main(String[] args) {
    CorseSeduleII cs = new CorseSeduleII();

    int[][] pr1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int[][] pr2 = {{1, 0}, {0, 1}}; // cycl
    System.out.println(Arrays.toString(cs.findOrder(4, pr1))); // [0, 1, 2, 3] or [0, 2, 1, 3]
    System.out.println(Arrays.toString(cs.findOrder(2, pr2))); // []
  }
}
