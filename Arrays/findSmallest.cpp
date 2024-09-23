#include<iostream>
#include<climits>   // For INT_MAX and INT_MIN
#include<algorithm> // For min and max functions
using namespace std;

int main() {
    int marks[] = {23, 45, 3, 67, -23, -5, 4}; 
    int smallest = INT_MAX;
    int largest = INT_MIN;

    // Calculate the number of elements in the array
    int n = sizeof(marks) / sizeof(marks[0]);

    for(int i = 0; i < n; i++) {
      
        smallest = min(smallest, marks[i]);
        largest = max(largest, marks[i]);
    }

    cout << "Smallest: " << smallest << "\n";
    cout << "Largest: " << largest << "\n";

    return 0;
}
