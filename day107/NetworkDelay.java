// 743. Network Delay Time
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class NetworkDelay {
  public int networkDelayTime(int[][] times, int n, int k) {
    Map<Integer, List<int[]>> edges = new HashMap<>();
    // {node, neighbout, time}
    for (int[] el : times)
      edges.computeIfAbsent(el[0], f -> new ArrayList<>()).add(new int[] { el[1], el[2] });

    // {time, node}
    PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
    pq.add(new int[] { 0, k });
    // {time, node}
    Map<Integer, Integer> dist = new HashMap<>();

    while (!pq.isEmpty()) {
      int[] currNode = pq.poll();
      int node = currNode[1];
      int time = currNode[0];
      if (dist.containsKey(node))
        continue;
      dist.put(node, time);

      if (edges.containsKey(node)) { 
        for (int[] neigh : edges.get(node)) {
          int nextNode = neigh[0], travelTime = neigh[1];
          if (!dist.containsKey(nextNode)) pq.add(new int[] { time + travelTime, nextNode });
        }
      }

    }
    if (dist.size() < n)
      return -1;
    int maxVal = 0;
    for (int val : dist.values()) maxVal = Integer.max(maxVal, val);
    return maxVal;
  }

  public static void main(String[] args) {
    NetworkDelay nd = new NetworkDelay();
    int[][] times = {
      {2, 1, 1},
      {2, 3, 1},
      {3, 4, 1}
    };
    int n = 4, k = 2;
    int result = nd.networkDelayTime(times, n, k);
    System.out.println("Network Delay Time: " + result); // Expected Output: 2
  }
}
