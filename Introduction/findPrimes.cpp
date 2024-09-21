#include <iostream>
using namespace std;

int main()
{

  cout << "Enter Range: ";
  int n;
  cin >> n;
  // if(n<=)
  int count = 1;
  cout << "1 : is Prime Number\n";

  for (int i = 2; i <= n; i++)
  {
  // cout<< "i: "<<i<<"\n";
    bool isPrime = true;
    for (int j = 2; j*j<=i; j++)  // here we optimized the code using (j*j<=n)
    {
      if (i % j == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
    {
      cout << i << " : is Prime Number\n";
      count += 1;
    }
  }

  // here count value will be 1 extra because we did count++, but 2 is a prime number also which we do not consider in total primes number we have to include 2.
  cout << "Total : " << count;

  return 0;
}