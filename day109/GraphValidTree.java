// 261.Graph Valid Tree 

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

// SOLVED USING - ITERATIVE DFS TRAVERSAL(possible using stack)
public class GraphValidTree {
  public boolean isValidTree(int V, int[][] edges){
    if(edges.length != V-1) return false;

    List<List<Integer>> graph = new ArrayList<>();
    for(int i=0; i<V; ++i) graph.add(new ArrayList<>());
    for(int[] p: edges){
      graph.get(p[0]).add(p[1]);
      graph.get(p[1]).add(p[0]);
    }
    
    Set<Integer> vis = new HashSet<>();
    Stack<Integer> stk = new Stack<>();

    vis.add(0);
    stk.add(0);
    while (!stk.isEmpty()) {
      int curr = stk.pop();
      for(int neighbour: graph.get(curr)){
        if(!vis.contains(neighbour)){
          vis.add(neighbour);
          stk.add(neighbour);
        }
      }
    }
    return vis.size() == V;
  }

  public static void main(String[] args) {
    GraphValidTree gvt = new GraphValidTree();

    // ✅ Example 1: Valid tree
    int V1 = 5;
    int[][] edges1 = {
      {0,1}, {0,2}, {0,3}, {1,4}
    };
    System.out.println(gvt.isValidTree(V1, edges1)); // true

    // ❌ Example 2: Not valid (contains cycle)
    int V2 = 5;
    int[][] edges2 = {
      {0,1}, {1,2}, {2,3}, {1,3}, {1,4}
    };
    System.out.println(gvt.isValidTree(V2, edges2)); // false

    // ❌ Example 3: Not valid (disconnected)
    int V3 = 4;
    int[][] edges3 = {
      {0,1}, {2,3}
    };
    System.out.println(gvt.isValidTree(V3, edges3)); // false
  }
}
