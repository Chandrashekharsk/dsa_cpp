// '\0' is known as "null charactor" || "backslash 0"
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;



int main(){

  // int arr[] = {1,2,3};
  // // memory address first element of an array
  // cout<<arr<<"\n";


  char str[] = {'j', 'i', 'y', 'a'};
  // it will not give VALID  C-style string 
  // output is unpredictable since it doesn’t know where the string ends.
  cout<<"unpredictable: "<<str<<"\n";
  cout<< strlen(str)<<"\n";


  char str2[] = {'j', 'i', 'y', 'a', '\0'};
  // here '\0' will not count with string length, and it will give VALID string
  cout<<"VALID: "<<str2<<"\n";
  cout<<strlen(str2)<<"\n";


  char str3[] = "jiya"; // string literal
  // here i'm assign a string literal to a character array, the compiler automatically appends the null-terminator at the end.
  cout<<"VALID: "<<str3<<"\n";
  // The strlen function works on null-terminated character arrays (C-strings). It starts counting from the first character and stops as soon as it hits a '\0'.
  cout<<strlen(str3)<<"\n";
  cout<<"index 1: "<<str3[1]<<"\n";
  cout<<"index 4: "<<str3[4]<<"\n";


  return 0;
}