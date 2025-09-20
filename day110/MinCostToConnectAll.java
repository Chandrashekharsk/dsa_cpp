// 1584. Min Cost to Connect All Points

import java.util.PriorityQueue;


public class MinCostToConnectAll {

  private static class Point{
    int index;
    int distance;
    public Point(int i, int d){
      index = i;
      distance = d;
    }
  }
  
  public int minCostConnectPoints(int[][] points) {
    int n = points.length;
    PriorityQueue<Point> pq = new PriorityQueue<>((a,b)-> a.distance - b.distance);
    boolean[] visMST = new boolean[n];
    pq.offer(new Point(0, 0));
    int cnt = 0;
    int cost = 0;

    while(!pq.isEmpty()){
      Point curr = pq.poll();
      if(visMST[curr.index]) continue;
      visMST[curr.index] = true;
      cost += curr.distance;
      ++cnt;
      for(int i=0; i<n; ++i){
        if(!visMST[i]){
          int distance = Math.abs(points[i][0] - points[curr.index][0]) + Math.abs(points[i][1] - points[curr.index][1]);
          pq.offer(new Point(i, distance));
        }
      }
      if(cnt == n) return cost;
    }
    return cost;
  }

  public static void main(String[] args) {
    MinCostToConnectAll solver = new MinCostToConnectAll();

    int[][] points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    // Expected output: 20
    int result = solver.minCostConnectPoints(points);
    System.out.println("Minimum cost to connect all points: " + result);
  }
}
