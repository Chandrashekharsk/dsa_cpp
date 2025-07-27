// 349. Intersection of Two Arrays
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class IntersectionSol{
  public static int[] intersection(int[] nums1, int[] nums2) {
    // approach 1
    // Set<Integer> s = new HashSet<>();
    // Set<Integer> ansSet  = new HashSet<>();
    
    // for(int num: nums1) s.add(num);
    // for(int num: nums2){
      //   if(s.contains(num))ansSet.add(num);
      // }
      
      // int[] ans  = new int[ansSet.size()];
      // int idx = 0;
      // for(int num: ansSet) ans[idx++] = num;
      // return ans;
      
      
      // approach 2
      // Set<Integer> s1 = new HashSet<>();
      // Set<Integer> s2 = new HashSet<>();
      // for(int num: nums1){
      //   s1.add(num);
      // }
      // for(int num: nums2){
      //   s2.add(num);
      // }
      // s1.retainAll(s2);
      // int[] ans = new int[s1.size()];
      // int idx = 0; 
      // for(int n : s1){
      //   ans[idx++] = n;
      // }
      // return ans;

      // approach 3
      Map<Integer,Integer> m = new HashMap<>();
      List<Integer> ans = new ArrayList<>();
      for(int num: nums1){
        m.put(num, 1);
      }
      for(int num: nums2){
        if(m.containsKey(num)){
          ans.add(num);
          m.remove(num);
        }
      }

      int[] res = new int[ans.size()];
      int idx = 0; 
      for(int n : ans){
        res[idx++] = n;
      }
      return res;
  }
  public static void main(String[] args) {
    int[] nums1 = {2, 3,5,6};
    int[] nums2 = {2, 4, 0, 3, 6};
    for(int num: intersection(nums1, nums2)){
      System.out.println(num);
    }
  }
}