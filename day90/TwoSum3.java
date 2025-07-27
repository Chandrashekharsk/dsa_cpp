
// 170. Two Sum III - Data structure design
import java.util.HashMap;
import java.util.Map;

public class TwoSum3 {
  static class TwoSum{
    Map<Integer, Integer> m;
    public TwoSum(){
      m = new HashMap<>();
    }

    public void add (int num){
      m.put(num, m.getOrDefault(num, 0)+1);
    }
    public boolean find (int sum){
      for(int key: m.keySet()){
        int valueToFind = sum-key;
        if(valueToFind == key){
          if(m.get(valueToFind)>1) return true;
        } 
        else if(m.containsKey(valueToFind)) return true;
      }
      return false;
    }
  }
  
  public static void main(String[] args) {
    TwoSum ts = new TwoSum();
    // ts.add(1);
    // ts.add(5);
    // ts.add(3);
    ts.add(2);
    // System.out.println(ts.find(7));
    System.out.println(ts.find(4));
  }
}
