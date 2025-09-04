// 621. Task Scheduler
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class TaskScheduler {

    public static int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> m = new HashMap<>();
        for (char c : tasks) m.put(c, m.getOrDefault(c, 0) + 1);

        // Max heap by frequency
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        pq.addAll(m.values());

        int cnt = 0;
        while (!pq.isEmpty()) {
            List<Integer> freqs = new ArrayList<>();

            // Process up to n+1 tasks in one cycle
            for (int i = 0; i < n + 1; ++i) {
                if (!pq.isEmpty())
                    freqs.add(pq.poll());
            }

            // Decrease freq and re-add if still > 0
            for (int f : freqs) {
                if (--f > 0) pq.add(f);
            }

            // If heap is empty, add only executed tasks; otherwise full cycle
            cnt += pq.isEmpty() ? freqs.size() : n + 1;
        }
        return cnt;
    }

    public static void main(String[] args) {
        char[] tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
        System.out.println(leastInterval(tasks, 2)); // Expected 8
        System.out.println(leastInterval(tasks, 3)); // Expected 10
    }
}
