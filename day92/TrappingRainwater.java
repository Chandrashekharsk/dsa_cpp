// 42. Trapping Rain Water 
public record TrappingRainwater() {
  public  static int trap(int[] height) {
    // approach 1
    // int n = height.length, mx = 0;
    // int[] maxRight = new int[n];
    // for(int i=n-1; i>=0; --i){
    //   maxRight[i] = mx;
    //   mx = Integer.max(mx, height[i]);
    // }
    
    // int mn = 0, sum = 0;
    // for(int i=0; i<n; ++i){
    //   int storageDefinerPiller = Integer.min(mn, maxRight[i]);
    //   if(storageDefinerPiller>height[i]) sum  += storageDefinerPiller-height[i];
    //   mn = Integer.max(mn, height[i]);
    // }
    // return sum;


    // approach 2
    int lMax = 0, rMax = 0;
    int st = 0, end  = height.length-1, sum = 0;
    while(st<end){
      if(height[st]<=height[end]){
        if(height[st]<lMax) sum+= lMax-height[st];
        lMax = Integer.max(lMax, height[st]);
        ++st;
      }else{
        if(height[end]<rMax) sum+= rMax-height[end];
        rMax = Integer.max(rMax, height[end]);
        --end;
      }
    }
    return sum;
  }
  public static void main(String[] args) {
    int[] nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    System.out.println(trap(nums));
  }
}
