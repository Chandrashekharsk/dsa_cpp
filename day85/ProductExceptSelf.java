// 238. Product of Array Except Self
public class ProductExceptSelf {

  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] suffix = new int[n];
    int[] ans = new int[n];

    int prevProd = 1;
    for(int i=n-1; i>=0; --i){
      suffix[i] = prevProd;
      prevProd *= nums[i];
    }

    prevProd = 1;
    for(int i=0; i<n; ++i){
      ans[i] = prevProd*suffix[i];
      prevProd*=nums[i];
    }
    return ans;
  }
  public static void main(String[] args) {
    ProductExceptSelf pes = new ProductExceptSelf();
    int[] nums1 = {1, 2, 3, 4};
    int[] nums2 = {-1, 1, 0, -3, 3};
    int[] result1 = pes.productExceptSelf(nums1);
    int[] result2 = pes.productExceptSelf(nums2);
    System.out.print("Test 1: ");
    for (int n : result1) System.out.print(n + " ");
    System.out.println(); // Expected: 24 12 8 6
    System.out.print("Test 2: ");
    for (int n : result2) System.out.print(n + " ");
    System.out.println(); // Expected: 0 0 9 0 0

  }
}
