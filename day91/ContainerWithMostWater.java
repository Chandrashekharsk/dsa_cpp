// 11. Container With Most Water
public class ContainerWithMostWater {
  public static int maxArea(int[] height) {
    // approach 1
    // int n = height.length;
    // int max = 0;

    // for (int i = 0; i < n; ++i) {
    //   for (int j = i + 1; j < n; ++j) {
    //     int width = j - i;
    //     int ht = Math.min(height[i], height[j]);
    //     int currArea = width * ht;
    //     max = Math.max(max, currArea);
    //   }
    // }
    // return max;

    // approach 2
    int n = height.length;
    int max = 0;
    int st = 0, end = n-1;
    while(st<end){
      int wt = end - st;
      int ht = Math.min(height[st], height[end]);
      int currArea = wt * ht;
      max = Math.max(max, currArea);
      if(height[st]<=height[end]) ++st;
      else --end;
    }
    
    return max;
  }

  public static void main(String[] args) {
    int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    System.out.println("Max area: " + result);
  }
}

