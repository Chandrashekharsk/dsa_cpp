// WAF for search(linear) any value
#include <iostream>
#include <vector>
using namespace std;

int searchKey(vector<int> vec, int key)
{
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] == key)
    {
      return i;
      break;
    }
  }
}

int main()
{

  vector<int> vec = {3, 45, 4, 5, 6, 15, 6, 7, 9, 8, 32, 3};
  cout <<"idx: "<< searchKey(vec, 9);

  return 0;
}