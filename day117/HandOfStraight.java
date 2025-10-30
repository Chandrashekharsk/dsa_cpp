// 846. Hand of Straights
import java.util.Map;
import java.util.TreeMap;

public class HandOfStraight {
  public boolean isNStraightHand(int[] hand, int groupSize) {
    TreeMap<Integer,Integer> tm = new TreeMap<>();
    for(int n: hand) tm.put(n, tm.getOrDefault(n, 0)+1);

    while (!tm.isEmpty()) {
      int st = tm.firstKey();
      for(int i=0; i<groupSize; ++i){
        int curr = st+i;
        if(!tm.containsKey(curr)) return false;
        int f = tm.get(curr);
        if(f==1)tm.remove(curr);
        else tm.put(curr, f-1);
      }
    }
    return true;
  }
  public static void main(String[] args) {
    int[] h = {1,2,3,6,2,3,4,7,8}; int s = 3;
    HandOfStraight hs = new HandOfStraight();
    System.out.println(hs.isNStraightHand(h, s));
  }
}
