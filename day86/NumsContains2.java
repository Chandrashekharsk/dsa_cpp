import java.util.HashSet;
import java.util.Set;

public class NumsContains2{

  public static boolean containsNearbyDuplicate(int[] nums, int k){
    Set<Integer> s = new HashSet<>();
    for(int i=0; i<nums.length; ++i){
      if(s.contains(nums[i])) return true;
      s.add(nums[i]);
      if(s.size()> k) s.remove(i-k);
    }
    return false;
  }

  public static void main(String[] args){
    int[] arr;
    arr = new int[] {1,2 , 3, 1};

    int[] arr2 = {1,2 ,3, 1};
    int[] arr3 = {1,0,0,1};
    System.out.println(containsNearbyDuplicate(arr2, 3));
    System.out.println(containsNearbyDuplicate(arr3, 1));
  }
}