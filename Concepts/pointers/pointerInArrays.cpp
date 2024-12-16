#include <iostream>
using namespace std;

int main()
{

  int arr[] = {10, 20, 30, 40, 50};
  // arr is a pointer, addressing the 0th value of array
  // cout<< arr<<"\n";
  // cout<< *(arr)<<"\n";
  // cout<< *(arr+1)<<"\n";
  // cout<< *(arr+2)<<"\n";


  int* ptr = arr;
  cout<< *(ptr+1)<<"\n"; // 20
  cout<< *(ptr+3)<<"\n"; // 40
  ptr++;                 
  cout<< *(ptr);         // 20
  return 0;
}