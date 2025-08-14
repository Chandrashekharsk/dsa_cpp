// 875. Koko Eating Bananas

public class MinHours {
  private static boolean canFinish(int[] piles, int speed, int h){
    int hourCnt = 0;
    for(int p: piles) hourCnt+= Math.ceil((double) p/speed);
    return hourCnt<= h;
  }

  public static int minEatingSpeed(int[] piles, int h) {
    int st = 1, end = 1;
    for(int p: piles) end = Math.max(p, end);
    int ans = end;
    while(st<=end){
      int mid = (end-st)/2 +st;
      if(canFinish(piles, mid, h)){
        ans = mid;
        end = mid-1;
      }else st = mid+1;
    }
    return ans;
  }
  public static void main(String[] args) {
    int[] piles = {3,6,7,11};
    System.out.println(minEatingSpeed(piles, 8));
  }
}
