// 239. Sliding Window Maximum

import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Set;

public class MaxSlidingWindow{
  
  public static int[] maxSlidingWindow(int[] nums, int k) {
    int n=nums.length, idx = 0;
    int[] ans = new int[(n-k)+1];
    Deque<Integer> deq = new LinkedList<>();

    for(int i=0; i<n; ++i){
      while(!deq.isEmpty() && deq.peek()<i-k+1) deq.poll();
      while(!deq.isEmpty() && nums[deq.peekLast()]<nums[i]) deq.pollLast();
      deq.offer(i);
      if(i>=k-1) ans[idx++] = nums[deq.peek()];
    }

    return ans;
  }
  public static void main(String[] args) {
    for(int n: maxSlidingWindow(new int[]{1,3,-1,-3,5,3,6,7}, 3)) System.out.print(n+" ");
  }
}