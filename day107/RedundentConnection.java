// 684. Redundant Connection
import java.util.ArrayList;
import java.util.List;

class GraphNode{
  int val;
  List<GraphNode> neighbors;
  public GraphNode(int _val){
    val = _val;
    neighbors = new ArrayList<>();
  }
}

public class RedundentConnection {
  private int[] parent;
  private int findParent(int n){
    if(parent[n] != n) parent[n] = findParent(parent[n]);
    return parent[n];
  }

  private boolean union(int a, int b){
    int pa = findParent(a);
    int pb = findParent(b);
    if(pa == pb) return false; // cycle detected
    parent[pa] = pb;
    return true;
  }

  public int[] findRedundantConnection(int[][] edges) {
    parent = new int[edges.length+1];
    for(int i=1; i<parent.length; ++i) parent[i] = i;
    
    for(int[] e: edges){
      if(!union(e[0], e[1])) return e;
    };
    return new int[] {-1, -1};
  }

  public static void main(String[] args) {
    int[][] edges = {
      {1,2},
      {2,3},
      {3,4},
      {1,4},
      {1,5},
    };

    RedundentConnection rn = new RedundentConnection();
    for(int i: rn.findRedundantConnection(edges)) System.out.print(i+" ");
  }
}
