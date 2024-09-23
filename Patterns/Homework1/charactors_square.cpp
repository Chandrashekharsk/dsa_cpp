// A B C D
// E F G H
// I J K L

#include <iostream>
using namespace std;

int main()
{

  cout << "Enter number of rows or columns: ";
  int n;
  cin >> n;
  char ch = 'A';

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ch << " ";
      ch++;
    }
    cout << "\n";
  }

  return 0;
}