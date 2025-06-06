//121. Best Time to Buy and Sell Stock 
public class BuySellStocks{

  public int maxProfit(int[] nums){
    if(nums.length == 0)return 0;
    int maxProfit = 0, start = nums[0];
    
    for(int i=1; i<nums.length; ++i){
      if(nums[i]<start) start = nums[i];
      else maxProfit = Math.max(maxProfit, nums[i]-start);
    }
    return maxProfit;
  }

  public static void main(String[] args) {
    BuySellStocks bss = new BuySellStocks();
    int[] prices1 = {7, 1, 5, 3, 6, 4};
    int[] prices2 = {7, 6, 4, 3, 1};
    System.out.println("Test 1: " + bss.maxProfit(prices1)); // Expected: 5
    System.out.println("Test 2: " + bss.maxProfit(prices2)); // Expected: 0
  }
}