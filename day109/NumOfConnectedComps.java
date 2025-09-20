// 323. Number of Connected Components in an Undirected Graph

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class NumOfConnectedComps {

  private void bfs(int i, List<List<Integer>> graph, boolean[] vis){
    Queue<Integer> q = new LinkedList<>();
    q.offer(i);

    while (!q.isEmpty()) {
      int curr = q.poll();
      vis[curr] = true;
      for(int nei: graph.get(curr)){
        if(!vis[nei]) q.add(nei);
      }
    }
  }
  public int cntComponents(int v, int[][] edges){
    List<List<Integer>> graph = new ArrayList<>();
    for(int i=0; i<v; ++i) graph.add(new ArrayList<>());
    for(int[] e: edges){
      graph.get(e[0]).add(e[1]);
      graph.get(e[1]).add(e[0]);
    } 

    boolean[] vis = new boolean[v];
    int cnt = 0;
    for(int i=0; i<v; ++i){
      if(!vis[i]){
        bfs(i, graph, vis);
        ++cnt;
      }
    }
    return cnt;
  }

  public static void main(String[] args) {
    int v = 5;
    int[][] edges = {{0,1},{1,2},{3,4}};
    NumOfConnectedComps ncc = new NumOfConnectedComps();
    System.out.println(ncc.cntComponents(v, edges));
  }
}
