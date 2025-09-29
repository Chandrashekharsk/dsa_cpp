// 118. Pascal's Triangle
import java.util.ArrayList;
import java.util.List;

public class PascalsTriangle{
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> prev  = new ArrayList<>();

    int r=1;
    while(numRows-- > 0){
      List<Integer> curr = new ArrayList<>(r);
      curr.add(1);
      for(int j=1; j<r; ++j){
        if(j==0 || j==r-1) curr.add(1);
        else curr.add(prev.get(j-1)+prev.get(j));
      }
      
      ans.add(curr);
      ++r;
      prev = curr;
    }

    return ans;
  }
  public List<Integer> generate2(int numRows) {
    List<Integer> row  = new ArrayList<>();
    if(numRows==0) return row;

    row.add(1);
    for(int i=1; i<=numRows; ++i){
      row.add(0); // increase size for make it next row(store all elements of next row)
      for(int j=i; j>0; --j){
        row.set(j, row.get(j-1)+ row.get(j));
      }
    }

    return row;
  }
  public static void main(String[] args) {
    PascalsTriangle pt = new PascalsTriangle();
    System.out.println(pt.generate(5));
  }
}