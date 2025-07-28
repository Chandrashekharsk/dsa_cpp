// 347. Top K Frequent Elements

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class TopKFreqElements {
  public int[] topKFrequent(int[] nums, int k) {
    // approach 1
    // Map<Integer, Integer> m = new HashMap<>();
    // for(int n: nums)  m.put(n, m.getOrDefault(n, 0)+1);

    // List<Map.Entry<Integer, Integer>> list = new ArrayList<>(m.entrySet());
    // list.sort((a, b)-> b.getValue() - a.getValue());
    
    // int[] ans  = new int[k];
    // for(int i=0; i<k; ++i){
    //   ans [i] = list.get(i).getKey();
    // }
    // return ans;


    // approach 2
    // Map<Integer, Integer> m = new HashMap<>();
    // for(int n: nums)  m.put(n, m.getOrDefault(n, 0)+1);

    // PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)->m.get(b)-m.get(a));
    // for(int key: m.keySet()) pq.add(key);
    // int[] ans  = new int[k];
    // for(int i=0; i<k; ++i) ans[i] = pq.poll();
    // return ans;

    // approach 3
    Map<Integer, Integer> m = new HashMap<>();
    int mxFreq = 1;
    for(int n: nums){
      m.put(n, m.getOrDefault(n, 0)+1);
      mxFreq = Integer.max(m.get(n), mxFreq);
    }
    @SuppressWarnings("unchecked")
    List<Integer>[] freqList = new ArrayList[mxFreq+1];
    for(int i=0; i<freqList.length; ++i) freqList[i] = new ArrayList<>();

    for(Map.Entry<Integer,Integer> entry: m.entrySet()) freqList[entry.getValue()].add(entry.getKey());
    int[] ans = new int[k];
    int idx = 0;
    for(int i=freqList.length-1 ; i>=0 && idx<k; --i){
      for(int el: freqList[i]){
        ans[idx++] = el;
        if(idx == k) break;
      }
    }
    return ans;
  }

  public static void main(String[] args) {
    TopKFreqElements sol = new TopKFreqElements();
    int[] nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    int[] res = sol.topKFrequent(nums, k);
    System.out.print("Output: [");
    for (int i = 0; i < res.length; ++i) {
      System.out.print(res[i]);
      if (i < res.length - 1)
        System.out.print(", ");
    }
    System.out.println("]");
  }
}
