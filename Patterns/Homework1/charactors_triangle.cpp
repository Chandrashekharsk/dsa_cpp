// A
// B B
// C C C
// D D D D
// E E E E E

#include <iostream>
using namespace std;

int main()
{

  cout << "Enter number of rows or columns: ";
  int n;
  cin >> n;

  // char ch = 'A';
  // for (int i=0; i<n; i++){
  //   for(int j=0; j<i+1; j++){
  //     cout<<ch<<" ";
  //   }
  //   ch++;
  //   cout<<"\n";
  // }


  char ch = 'A';
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      cout << ch << " ";
      ch++;
    }
    cout << "\n";
  }

  return 0;
}