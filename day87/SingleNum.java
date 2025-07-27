import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class SingleNum {

  public static int singleNumber(int[] nums) {
    // approach 1
    // Map<Integer, Integer> m = new HashMap<>();
    // for(int num: nums){
    //   if(m.containsKey(num))  m.put(num, m.get(num)+1);
    //   else m.put(num, 1);
    // }
    // for(int num : nums){
    //   if(m.get(num) ==1 ) return num;
    // }
    // return -1;

    // approach 2
    // Set<Integer> s = new HashSet<>();
    // int sum = 0, setSum = 0;
  
    // for(int num: nums){
    //   if(!s.contains(num)){
    //     s.add(num);
    //     setSum += num;
    //   }
    //   sum += num;
    // }
    // return sum - setSum;

    // approach 3
    int xorSum = 0;
    for(int num : nums){
      xorSum ^= num;
    }
    return xorSum;
  }

  public static void main(String[] var0) {
    int[] var1 = new int[] { 2, 3, 3, 5, 2 };
    System.out.println(singleNumber(var1));
  }
}
