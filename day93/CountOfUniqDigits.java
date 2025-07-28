// 357. Count Numbers with Unique Digits

public class CountOfUniqDigits {

  public static int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;

    int ans = 10;
    int digitsCount = 9;
    int availableDigits = 9;

    for (int i = 2; i <= n; i++) {
      digitsCount *= availableDigits;
      ans += digitsCount;
      --availableDigits;
      if (availableDigits == 0) break;
    }

    return ans;
  }

  public static void main(String[] args) {
    System.out.println("--------------------");
    // System.out.println(power(10, 1));
    System.out.println(countNumbersWithUniqueDigits(3));
    System.out.println(countNumbersWithUniqueDigits(2));
    System.out.println(countNumbersWithUniqueDigits(1));
  }
}
