// 350. Intersection of Two Arrays II
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class IntersactionOf2Arr {
  public static int[] intersect(int[] nums1, int[] nums2) {
    Map<Integer,Integer> m = new HashMap<>();
    for(int i=0; i<nums1.length; ++i){
      m.put(nums1[i], m.getOrDefault(nums1[i], 0)+1);
    }
    List<Integer> ans = new ArrayList<>();
    for(int i=0; i<nums2.length; ++i){
      if(m.containsKey(nums2[i]) && m.get(nums2[i]) != 0){
        m.put(nums2[i], m.get(nums2[i])-1);
        ans.add(nums2[i]);
      }
    }

    int[] intersaction = new int[ans.size()];
    for(int i=0; i<ans.size(); ++i){
      intersaction[i] = ans.get(i);
    }
    return intersaction;
  }
  public static void main(String[] args) {
    int[] n1 = {1,2,2,1}, n2 = {2, 2};
    for(int n: intersect(n1, n2)){
      System.out.print(n+" ");
    }
    
  }
}
