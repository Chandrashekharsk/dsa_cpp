#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int lowestPrice = INT_MAX; 
    int maxProfit = 0; 

    for (int price : prices) {
        if (price < lowestPrice) {
            lowestPrice = price; // Update lowest price found so far
        }
       
        int potentialProfit = price - lowestPrice;
        if (potentialProfit > maxProfit) {
            maxProfit = potentialProfit; // Update max profit if current is higher
        }
    }
    
    return maxProfit; 
}

int main() {
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {2,4,1}; 
    cout << maxProfit(prices) << endl; 
    return 0;
}
