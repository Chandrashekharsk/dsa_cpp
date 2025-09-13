import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

// Note: To use TOPOSORT Graph should be -> DAG

public class TopoSort {
  public int[] topoSortSequence(int V, int[][] adj){
    List<List<Integer>> graph = new ArrayList<>();
    int[] indegree = new int[V];
    for (int i = 0; i < V; i++) graph.add(new ArrayList<>());
    for (int[] p : adj) {
      graph.get(p[0]).add(p[1]);
      ++indegree[p[1]];
    }
    
    Queue<Integer> q = new LinkedList<>();
    for(int i=0; i<V; ++i){
      if(indegree[i]==0) q.offer(i);
    }

    List<Integer> ans = new ArrayList<>();
    while (!q.isEmpty()) {
      int curr = q.poll();
      ans.add(curr);
      for(int neighbour: graph.get(curr)){
        --indegree[neighbour];
        if(indegree[neighbour] == 0) q.offer(neighbour);
      }
    }
    if(ans.size() != V) return new int[0]; // cycle detected;
    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
  public static void main(String[] args) {
    int[][] pr1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    int[][] pr2 = {{1, 0}, {0, 1}};

    TopoSort tp = new TopoSort();
    System.out.println(Arrays.toString(tp.topoSortSequence(4, pr1))); // [0, 1, 2, 3] or [0, 2, 1, 3]
    System.out.println(Arrays.toString(tp.topoSortSequence(2, pr2))); // []

  }
}
