// 215. Kth Largest Element in an Array
import java.util.PriorityQueue;

public class KthLargestElem {
  public static int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> h = new PriorityQueue<>(k);
    for(int n: nums){
      h.offer(n);
      if(h.size()>k) h.poll();
    }
    return h.poll();
  }
  public static void main(String[] args) {
    System.out.println(findKthLargest(new int[]{3,2,1,5,6,4}, 2)); // 5
  }
}
