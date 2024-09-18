// WAP for a calculator
#include <iostream>
using namespace std;
#include <cmath>    // For mathematical functions like sin, cos, exp, log
#include <limits>   // For numeric limits

void displayMenu()
{
  cout << "\nComplex Calculator Menu:\n";
  cout << "1. Addition\n";
  cout << "2. Subtraction\n";
  cout << "3. Multiplication\n";
  cout << "4. Division\n";
  cout << "5. Exponentiation\n";
  cout << "6. Logarithm\n";
  cout << "7. Sine\n";
  cout << "8. Cosine\n";
  cout << "9. Tangent\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
}

void calcultor()
{
  int choice;
  float num1, num2, result;
  displayMenu();

  cin >> choice;
  if (choice == 0)
  {
    cout << "Exited From Caluculator";
  }

  switch (choice)
  {
  case 1: // Addition
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    result = num1 + num2;
    cout << "Result: " << result << endl;
    break;
  case 2: // Subtraction
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    result = num1 - num2;
    cout << "Result: " << result << endl;
    break;
  case 3: // Multiplication
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    result = num1 * num2;
    cout << "Result: " << result << endl;
    break;
  case 4: // Division
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    if (num2 == 0)
    {
      cout << "Error: Division by zero is not allowed.\n";
    }
    else
    {
      result = num1 / num2;
      cout << "Result: " << result << endl;
    }
    break;
  case 5: // Exponentiation
    cout << "Enter base and exponent: ";
    cin >> num1 >> num2;
    result = pow(num1, num2);
    cout << "Result: " << result << endl;
    break;
  case 6: // Logarithm
    cout << "Enter a number: ";
    cin >> num1;
    if (num1 <= 0)
    {
      cout << "Error: Logarithm is undefined for non-positive numbers.\n";
    }
    else
    {
      result = log(num1);
      cout << "Result: " << result << endl;
    }
    break;
  case 7: // Sine
    cout << "Enter an angle in radians: ";
    cin >> num1;
    result = sin(num1);
    cout << "Result: " << result << endl;
    break;
  case 8: // Cosine
    cout << "Enter an angle in radians: ";
    cin >> num1;
    result = cos(num1);
    cout << "Result: " << result << endl;
    break;
  case 9: // Tangent
    cout << "Enter an angle in radians: ";
    cin >> num1;
    result = tan(num1);
    cout << "Result: " << result << endl;
    break;

  default:
    cout << "Invalid choice. Please try again.\n";
    break;
  }
}

int main()
{
  calcultor();
  return 0;
}