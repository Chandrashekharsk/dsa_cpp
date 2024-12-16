#include<iostream>
using namespace std;

double calculateSimpleInterest(double P, double R, double T){
    double SI = (P * R * T) / 100.0; // Corrected to floating point division
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
