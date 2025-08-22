// 1046. Last Stone Weight
import java.util.PriorityQueue;

public class LastStoneWt {
  public static int lastStoneWeight(int[] stones) {
    PriorityQueue<Integer> h = new PriorityQueue<>((a, b)-> b-a);
    for(int n: stones) h.offer(n);
    while(h.size()>1){
      int curr = h.poll(), next = h.peek();
      if(curr>next){
        h.poll();
        h.offer(curr-next);
      }else if(next == curr){
        h.poll();
        h.offer(0);
      }
    }
    return h.poll();
  }
  public static void main(String[] args) {
    int[] stones = {2,7,4,1,8,1};
    System.out.println(lastStoneWeight(stones));
  }
}
