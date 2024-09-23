//    *
//   * *
//  *   *
// *     *
//  *   *
//   * *
//    *

#include <iostream>
using namespace std;
#include <cmath>

int main()
{

  cout << "Enter number of rows: ";
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    cout << "*";
    for (int k = 0; k < (2 * i) - 1; k++)
    { // 2*i-1 to get odd number
      cout << " ";
    }
    if (i != 0)
      cout << "*";
    cout << "\n";
  }

  // Bottom part of the diamond
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << "*";

    for (int k = 0; k < (2 * i) - 1; k++)
    {
      cout << " ";
    }

    if (i != 0) cout << "*";
    
    cout << "\n";
  }

  return 0;
}