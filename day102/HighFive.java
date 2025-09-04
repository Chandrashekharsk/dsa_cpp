// 1086. High Five 
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeMap;

public class HighFive {
  public static int[][] highFive(int[][] items){
    TreeMap<Integer, PriorityQueue<Integer>> m = new TreeMap<>();
    for(int[] item : items){
      m.computeIfAbsent(item[0], f-> new PriorityQueue<>((a,b)-> b-a));
      m.get(item[0]).add(item[1]);
    }
    
    int[][] ans = new int[m.size()][2];
    int idx = 0;
    for(Map.Entry<Integer, PriorityQueue<Integer>> entry: m.entrySet()){
      ans[idx][0] = entry.getKey();
      PriorityQueue<Integer> pq = entry.getValue();
      int sum = 0;
      for(int i=0; i<5; ++i) sum+=pq.poll();
      ans[idx++][1] = sum/5;
    }
    return ans;
  }
  public static void main(String[] args) {
    int[][] items = {
      {1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60},
      {2, 77}, {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}
    };

    int[][] ans = highFive(items);

    for (int[] a : ans) {
      System.out.println(a[0] + " -> " + a[1]);
    }
  }
}
