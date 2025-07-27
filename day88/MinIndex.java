// 599. Minimum Index Sum of Two Lists 
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MinIndex {
  public static String[] findRestaurant(String[] list1, String[] list2) {
    Map<String, Integer> m = new HashMap<>();
    for(int i=0; i<list1.length; ++i){
      m.put(list1[i], i);
    }
    List<String> ans = new ArrayList<>();
    int minIndexSum = Integer.MAX_VALUE;

    for(int i=0; i<list2.length; ++i){
      if(i>minIndexSum) break;
      if(m.containsKey(list2[i])){
        int currIdxSum = i+m.get(list2[i]);
        if(currIdxSum==minIndexSum) ans.add(list2[i]);
        if(currIdxSum<minIndexSum){
          minIndexSum = currIdxSum;
          ans.clear();
          ans.add(list2[i]);
        }
      }
    }
    return ans.toArray(new String[0]);
  }

  public static void main(String[] args) {
    // Sample input
    String[] list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    String[] list2 = {"KFC","Piatti", "The Grill at Torrey Pines","Shogun", "Hungry Hunter Steakhouse"};
    String[] result = findRestaurant(list1, list2);
    System.out.println("Common restaurants with minimum index sum:");
    for(String s : result) {
      System.out.println(s);
    }
  }
}
