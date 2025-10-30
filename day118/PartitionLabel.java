// 763. Partition Labels

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PartitionLabel {
  public List<Integer> partitionLabels(String s) {
    List<Integer> ans = new ArrayList<>();
    Map<Character, Integer> m = new HashMap<>();
    for(int i=0; i<s.length(); ++i) m.put(s.charAt(i), i);
    int st = 0, end = 0;
    for(int i=0; i<s.length(); ++i){
      end = Math.max(end, m.get(s.charAt(i)));
      if(i == end){
        ans.add(end-st +1);
        st = i+1;
      }
    }
    return ans;
  }

  public static void main(String[] args) {
    PartitionLabel pl = new PartitionLabel();
    System.out.println(pl.partitionLabels("ababcbacadefegdehijhklij"));
  }
}
