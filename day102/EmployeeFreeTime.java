// 759. Employee Free Time 
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class EmployeeFreeTime {

  static class Interval {
    int start;
    int end;

    public Interval(int start, int end) {
      this.start = start;
      this.end = end;
    }

    @Override
    public String toString() {
      return "[" + start + "," + end + "]";
    }
  }

  public static List<Interval> empFreeTime(List<List<Interval>> schedule) {
    List<Interval> ans = new ArrayList<>();
    PriorityQueue<Interval> pq = new PriorityQueue<>((a, b) -> a.start - b.start);

    // put all intervals from all employees into pq
    for (List<Interval> intervals : schedule) pq.addAll(intervals);

    // merging
    Interval prev = pq.poll();
    while(!pq.isEmpty()){
      Interval curr = pq.poll();
      if(prev.end < curr.start){
        ans.add(new Interval(prev.end, curr.start));
        prev = curr;
      }else prev.end = Math.max(prev.end, curr.end);
    }
    
    return ans;
  }

  public static void main(String[] args) {
    // Sample input
    List<List<Interval>> schedule = new ArrayList<>();
    schedule.add(Arrays.asList(new Interval(1, 2), new Interval(5, 6)));
    schedule.add(Arrays.asList(new Interval(1, 3)));
    schedule.add(Arrays.asList(new Interval(4, 10)));

    List<Interval> freeTime = empFreeTime(schedule);

    System.out.println("Employee free time: " + freeTime);
  }
}
