// 973. K Closest Points to Origin
import java.util.PriorityQueue;

public class ClosestPointToOrigin {
  public static int[][] kClosest(int[][] points, int k) {
    PriorityQueue<int[]> h = new PriorityQueue<>((a,b)->Integer.compare(b[0]*b[0]+b[1]*b[1], a[0]*a[0]+a[1]*a[1]));

    for(int[] p: points){
      h.offer(p);
      if(h.size()>k) h.poll();
    }

    int[][] ans = new int[k][2];
    int idx = 0;
    while(!h.isEmpty()) ans[idx++] = h.poll();
    return ans;
  }
  public static void main(String[] args) {
    int[][] nums = {{1,3}, {-2, 2}};
    for(int[] p: kClosest(nums, 1)){
      System.out.println(p[0]+" "+p[1]);
    }
  }
}
