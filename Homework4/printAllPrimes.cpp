// print all prime numbers form 2 to N;

#include <iostream>
using namespace std;

bool isPrime(int n)
{
  if (n == 1)
  {
    return false;
  }
  bool prime = true;
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      prime = false;
    }
  }
  return prime;
}

void printPrimeInRange(int n)
{
  int count = 0;
  for (int i = 2; i <= n; i++)
  {
    if (isPrime(i))
    {
      cout << i << " ";
      count++;
    }
  }
  cout<<"count: "<<count;
}

int main()
{

  cout << "Enter range: ";
  int n;
  cin >> n;
  printPrimeInRange(n);

  return 0;
}