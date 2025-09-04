// 295. Find Median from Data Stream
import java.util.PriorityQueue;

public class MedianFinder {
    private PriorityQueue<Integer> maxpq;
    private PriorityQueue<Integer> minpq;

    public MedianFinder() {
        maxpq = new PriorityQueue<>((a,b)->Integer.compare(b, a));
        minpq = new PriorityQueue<>();
    }

    public void addNum(int num) {
        maxpq.offer(num);
        minpq.offer(maxpq.poll());

        // Step 3: rebalance (maxpq can have 1 more than minpq)
        if (minpq.size() > maxpq.size())  maxpq.offer(minpq.poll());
    }

    public double findMedian() {
        if(maxpq.isEmpty()) return 0.0;

        if(maxpq.size()==minpq.size()) return (maxpq.peek()+minpq.peek())/2.0;
        return maxpq.peek();
    }

    public static void main(String[] args) {
        MedianFinder obj = new MedianFinder();
        obj.addNum(2);
        // obj.addNum(3);
        // obj.addNum(1);
        // obj.addNum(6);
        System.out.println(obj.findMedian());
    }
}
