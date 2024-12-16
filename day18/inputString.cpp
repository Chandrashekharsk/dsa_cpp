#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int main(){

  // char str[20];
  // cout<< "enter string array: "<<"\n";
  // cin>> str;
  // cout<< str<<"\n";


  // here 3 param is a delimiter, which specifies in which char we have to stop taken string input
  // cin.getline(str, 20, '$');
  // for(int i=0; i<strlen(str);i++){
  //   cout<<str[i];
  // }

  char str[] = "apna college";
  int len = 0;
  for(int i=0; str[i]!='\0'; i++){
    len++;
  }
  cout<<len;


  return 0;
}