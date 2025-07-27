// 26. Remove Duplicates from Sorted Array
public class RemDuplFromSortedArr {
  
  public static int removeDuplicates(int[] nums) {
    int idx = 0, p = 1;
    while(p<nums.length){
      if(nums[idx]!= nums[p]) nums[++idx] = nums[p];
      ++p;
    }
    return ++idx;
  }
  public static void main(String[] args) {
    int[] nums =  {0,0,1,1,1,2,2,3,3,4};
    int size = removeDuplicates(nums);
    for(int i=0; i<size; ++i){
      System.out.println(nums[i]);
    }

  } 
}
