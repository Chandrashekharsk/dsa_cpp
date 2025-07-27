public class TwoSum2 {
  public static int[] twoSum(int[] numbers, int target) {

    // approach 1
    // for(int i=0; i<numbers.length; ++i){
    //   int st = i+1, end = numbers.length -1;
    //   int currTar = target-numbers[i];

    //   while(st<=end){
    //     int mid = (end-st)/2 + st;
    //     if(numbers[mid] == currTar) return new int[]{++i, ++mid};
    //     if(numbers[mid]<currTar){
    //       st = mid+1;
    //     }else end = mid-1;
    //   }
    // }
    // return new int[]{};

    // approach 2
    int st = 0, end = numbers.length-1;
    while(st<end){
      int sum = numbers[st] + numbers[end];
      if(sum == target) return new int[]{++st, ++end};
      if(sum<target){
        ++st;
      }else --end;
    }
    return new int[]{};
  }
  public static void main(String[] args) {
    int[] nums = {2,7,11,15};
    for(int n: twoSum(nums, 9)){
      System.out.println(n);;
    }
  }
}
