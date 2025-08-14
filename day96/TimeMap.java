// 981. Time Based Key-Value Store

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TimeMap {
  class Pair{
    int timestamp;
    String value;
    public Pair(int timestamp, String value){
      this.timestamp = timestamp;
      this.value = value;
    }
  }
  Map<String, List<Pair>> m;

  public TimeMap() {
    m = new HashMap<>();
  }

  public void set(String key, String value, int timestamp) {
    m.putIfAbsent(key, new ArrayList<>());
    m.get(key).add(new Pair(timestamp, value));
  }

  public String get(String key, int timestamp) {
    if(!m.containsKey(key)) return "";
    String prev_timeStampVal = "";

    List<Pair> list = m.get(key);
    int st = 0, end = list.size()-1;
    while (st<=end) {
      int mid = (end-st)/2 +st;
      Pair p = list.get(mid);
      if(p.timestamp == timestamp) return p.value;
      else if(p.timestamp<timestamp){
        prev_timeStampVal = p.value;
        st = mid+1;
      }else end = mid-1;
    }
    return prev_timeStampVal;
  }

  public static void main(String[] args) {
    TimeMap tm = new TimeMap();
    tm.set("foo", "bar", 1);
    System.out.println(tm.get("foo", 1));
    System.out.println(tm.get("foo", 3));
    tm.set("foo", "bar2", 4);
    System.out.println(tm.get("foo", 4));
    System.out.println(tm.get("foo", 5));
  }
}
