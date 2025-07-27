// 88. Merge Sorted Arrays
import java.util.Arrays;

public class mergeSortedArr {
  public static void merge(int[] nums1, int m, int[] nums2, int n) {
    int p1 = m-1, p2 = n-1, idx = m+n-1;

    while(p1>=0 && p2>=0 && idx>=0){
      if(nums2[p2]>= nums1[p1]){
        nums1[idx] = nums2[p2];
        --p2;
      }else{
        nums1[idx] = nums1[p1];
        --p1;
      }
      --idx;
    }
    while(p2>=0 && idx>=0){
      nums1[idx--] = nums2[p2--];
    }
  }
  public static void main(String[] args) {
    int[] nums1 = {0};  // m = 3, n = 3
    int[] nums2 = {1};
    // int[] nums1 = {1, 2, 4, 7, 0, 0, 0};  // m = 3, n = 3
    // int[] nums2 = {2, 3, 6};
    int m = 0, n = 1;

    merge(nums1, m, nums2, n);

    System.out.println("Merged array: " + Arrays.toString(nums1));
    
  }
  
}
