// 4. Median of Two Sorted Arrays

public class MedianOfSortedArr {
  private static int[] mergeArrays(int[] nums1, int[] nums2) {
    int l1 = nums1.length, l2 = nums2.length;
    int[] res = new int[l1 + l2];
    
    int idx = 0, left = 0, right = 0, l3 = res.length;

    while (left < l1 && right < l2 && idx<l3 ) {
      if (nums1[left] <= nums2[right]) {
        res[idx++] = nums1[left];
        ++left;
      } else {
        res[idx++] = nums2[right];
        ++right;
      }
    }
    while (left < l1 && idx<l3){
      res[idx++] = nums1[left];
      ++left;
    }
    while (right < l2 && idx<l3){
      res[idx++] = nums2[right];
      ++right;
    }
    return res;
  }

  public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
    // approach 1
    int[] result = mergeArrays(nums1, nums2);
    int size = result.length;
    int  mid = size / 2;
    if ((size & 1) == 1)
      return result[mid];
    return (result[mid - 1] + result[mid]) / 2.0;
  }

  public static void main(String[] args) {
    int[] nums1 = { 1, 3 }, nums2 = { 2, 4 };
    // int[] nums1 = { 1, 3 }, nums2 = { 2 };
    System.out.println(findMedianSortedArrays(nums1, nums2));
  }
}
