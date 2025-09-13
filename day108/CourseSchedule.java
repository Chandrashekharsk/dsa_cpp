// 207. Course Schedule
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class CourseSchedule{
  private boolean dfs(Map<Integer, List<Integer>> m, int course, Set<Integer>visited, Set<Integer> recStack){
    if(recStack.contains(course)) return false;
    if(visited.contains(course)) return true;

    recStack.add(course); // mark visited

    for(int neighbour: m.get(course)){
      if(!dfs(m, neighbour, visited, recStack)) return false;
    }

    recStack.remove(course);
    visited.add(course); // mark as fully processed
    return true;
  }

  public boolean canFinish2(int numCourses, int[][] prerequisites) {
    Map<Integer, List<Integer>> m = new HashMap<>();
    for (int i = 0; i < numCourses; i++)  m.put(i, new ArrayList<>());
    for(int[] pair : prerequisites) m.get(pair[0]).add(pair[1]);  // course0 depends on course1

    Set<Integer> visited = new HashSet<>();
    Set<Integer> recStack = new HashSet<>();

    for(int c=0; c<numCourses; ++c){
      if(!dfs(m, c, visited, recStack)) return false;
    }
    return true;
  }

  // USING TOPSORT (require DAG)
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    Map<Integer, List<Integer>> m = new HashMap<>();
    int[] indegree = new int[numCourses];
    for(int i=0; i<numCourses; ++i) m.put(i, new ArrayList<>());
    for(int[] p: prerequisites){
      m.get(p[1]).add(p[0]);
      ++indegree[p[0]];
    }

    Queue<Integer> q  = new LinkedList<>();
    for(int i=0; i<numCourses; ++i){
      if(indegree[i]==0) q.offer(i);
    }

    int processed = 0;
    while (!q.isEmpty()) {
      int curr = q.poll();
      ++processed;
      for(int neighbour: m.get(curr)){
        --indegree[neighbour];
        if(indegree[neighbour] == 0) q.offer(neighbour);
      }
    }

    return processed == numCourses;
  }

  public static void main(String[] args) {
    int[][] pr = {{1, 0}, {0, 2}, {0, 3}};
    // int[][] pr = {{1, 0}, {0, 1}};
    CourseSchedule cf = new CourseSchedule();
    System.out.println(cf.canFinish(3, pr));;
  }
}