// 703.kth Largest Element in a Stream

import java.util.PriorityQueue;

public class KthLargest {
  private PriorityQueue<Integer> mh;
  private int cap;

  public KthLargest(int k, int[] nums) {
    this.cap = k;
    mh = new PriorityQueue<>(k);
    for(int n: nums) add(n);
  }
  
  public int add(int val) {
    if(mh.size()<cap){
      mh.offer(val);
    }else if(val>mh.peek()){
      mh.poll();
      mh.offer(val);
    }
    return mh.peek();
  }

  public void printPeek(){
    System.out.println(mh.peek());
  }

  public static void main(String[] args) {
    int[] nums = {2, 4, 3, 8};
    KthLargest obj = new KthLargest(3, nums);
    obj.printPeek();
  }
}
