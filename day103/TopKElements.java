// 347. Top K Elements
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class TopKElements {
  public static int[] topKFrequent(int[] nums, int k) {
    // approach 1
    // Map<Integer, Integer> m = new HashMap<>();

    // for(int n: nums) m.put(n, m.getOrDefault(n, 0)+1);
    // PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->
    // Integer.compare(m.get(a), m.get(b)));
    // for(int key: m.keySet()){
    // pq.offer(key);
    // m.get(key);
    // if(pq.size()>k) pq.poll();
    // }

    // int idx = 0;
    // int[] ans = new int[k];
    // while(!pq.isEmpty()) ans[idx++] = pq.poll();
    // return ans;


    // approach 2
    Map<Integer, Integer> m = new HashMap<>();

    int maxFreq = -1;
    for (int n : nums) {
      m.put(n, m.getOrDefault(n, 0) + 1);
      maxFreq = Math.max(maxFreq, m.get(n));
    }

    @SuppressWarnings("unchecked")
    List<Integer>[] freqs = new ArrayList[maxFreq + 1];

    for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
      int freq = entry.getValue();
      if (freqs[freq] == null) freqs[freq] = new ArrayList<>();
      freqs[freq].add(entry.getKey());
    }

    int[] ans = new int[k];
    int idx = 0;
    for (int i = maxFreq; i > 0 && idx < k; --i) {
      for (int n : freqs[i]) {
        ans[idx++] = n;
        if (idx == k) break;
      }
    }
    return ans;
  }

  public static void main(String[] args) {
    int[] nums = { 1, 2, 1, 2, 1, 2, 3, 1, 3, 2 };
    for (int n : topKFrequent(nums, 2)) {
      System.out.print(n + " ");
    }
  }
}