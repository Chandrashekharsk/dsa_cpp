// Given a person's age, find if they should get a driving license or not.

#include <iostream>
using namespace std;

void canIDrive(int age){
  age > 18 ? cout << "You can drive" : cout << "You can't drive";
}

int main()
{
  int age;
  cout << "Enter you age: ";cin >> age;
  canIDrive(age);

  return 0;
}