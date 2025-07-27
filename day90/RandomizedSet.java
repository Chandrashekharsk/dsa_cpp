// 380. Insert Delete GetRandom O(1)
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class RandomizedSet {
  private Map<Integer, Integer> m;
  private List<Integer> list;
  private Random rand;

  public RandomizedSet() {
    m = new HashMap<>();
    list = new ArrayList<>();
    rand = new Random();
  }

  public boolean insert(int val) {
    if(m.containsKey(val)) return false;

    list.add(val);
    m.put(val, list.size()-1);
    return true;
  }

  public boolean remove(int val) {
    if(!m.containsKey(val)) return false;
    int idxToRemove = m.get(val);
    int lastVal = list.get(list.size()-1);

    list.set(idxToRemove, lastVal);
    m.put(lastVal, idxToRemove);

    list.remove(list.size()-1);
    m.remove(val);
    return true;
  }

  public int getRandom() {
    int idx =  rand.nextInt(list.size());
    return list.get(idx);
  }
  public static void main(String[] args) {
    RandomizedSet set = new RandomizedSet();
    System.out.println("Insert 1: " + set.insert(1)); // true
    System.out.println("Remove 2: " + set.remove(2)); // false
    System.out.println("Insert 2: " + set.insert(2)); // true
    System.out.println("Random: " + set.getRandom()); // 1 or 2
    System.out.println("Remove 1: " + set.remove(1)); // true
    System.out.println("Insert 2 again: " + set.insert(2)); // false
    System.out.println("Random: " + set.getRandom()); // 2
  }
}