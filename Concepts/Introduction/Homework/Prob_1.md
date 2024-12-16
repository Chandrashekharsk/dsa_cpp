# Simple Interest Calculation in C++

## Problem Statement
Write a C++ program to calculate the Simple Interest (SI) given the following formula:

\[ SI = \frac{P \times R \times T}{100} \]

Where:
- **P** is the principal amount.
- **R** is the annual interest rate in percentage.
- **T** is the time period in years.

## Approach

### 1. Input
The program takes three inputs:
- **Principal (P)**: The initial amount of money invested.
- **Rate (R)**: The annual interest rate.
- **Time (T)**: The number of years the money is invested.

### 2. Formula
The formula to calculate simple interest is:

\[ SI = \frac{P \times R \times T}{100} \]

### 3. Output
The program will output the simple interest calculated based on the input values.

### 4. Data Types
The initial version of the program used `int` for the calculation. However, we updated it to use `double` to handle decimal precision and avoid integer division issues.

### 5. Code Implementation

```cpp
#include<iostream>
using namespace std;

double calculateSimpleInterest(double P, double R, double T){
    double SI = (P * R * T) / 100.0;
    return SI;
}

int main(){
    double P, R, T;

    cout<< "Enter principal amount: "; 
    cin>>P;
    cout<< "Enter rate percentage: "; 
    cin>>R;
    cout<< "Enter time in years: "; 
    cin>>T;

    cout<< "Simple Interest is: " << calculateSimpleInterest(P, R, T) << endl;
    return 0;
}
