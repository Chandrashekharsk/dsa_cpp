import java.util.Map;
import java.util.TreeMap;

class ExamTracker {
  TreeMap<Integer, Long> prefixSumMap;

  public ExamTracker() {
    prefixSumMap = new TreeMap<>();
  }

  public void record(int time, int score) {
    long lastSum = 0;
    Map.Entry<Integer, Long> e = prefixSumMap.floorEntry(time);
    if (e != null) {
      lastSum += e.getValue();
    }
    prefixSumMap.put(time, lastSum + score);
  }

  public long totalScore(int startTime, int endTime) {
    Map.Entry<Integer, Long> endEntry = prefixSumMap.floorEntry(endTime);
    Map.Entry<Integer, Long> startEntry = prefixSumMap.lowerEntry(startTime);

    long endSum = endEntry != null ? endEntry.getValue() : 0;
    long startSum = startEntry != null ? startEntry.getValue() : 0;
    return endSum - startSum;
  }

  public static void main(String[] args) {
    
  }
}