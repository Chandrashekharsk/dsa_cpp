// string are mutable(dynamic in nature) in c++ but char array is not mutable
// runtime resize possible in string 
// int arr[] ---> vector<int>  similarly, char charArr[] ---->string
#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main(){

  string  str = "apna college";
  cout<< str <<"\n";
  // VALID
  str = "hello";

  // char charArr[] = "apna college";
  // cout<< charArr<<"\n";
  // // NOT VALID (this will throw error lvalue is not modifiable)
  // charArr = "hello";

  string str2 = ", bruhhh";
  string str3 = str + str2;
  cout<<str3<<"\n";
  cout<<str3.length()<<"\n";
  cout<<(str2 == str3)<<"\n";
  // this will give true because lexicographically b comes before than h
  cout<<(str2 < str3)<<"\n";



  return 0;
}