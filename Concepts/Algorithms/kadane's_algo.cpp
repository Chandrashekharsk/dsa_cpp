#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH  - - O(n^2)
// int maxSubArrSum(vector<int> vec) {
//     int maxSum = INT_MIN;
//     for(int st = 0; st < vec.size(); st++) {
//         int currSum = 0;
//         for(int end = st; end < vec.size(); end++) { // Use vec.size() instead of n
//             currSum += vec[end];
//             maxSum = max(currSum, maxSum);
//         }
//     }
//     return maxSum;
// }

// KADANE'S APPROACH - O(n)
int maxSubArrSum(vector<int> vec){
  int MS = INT_MIN;
  int CS = 0;
  for(int i=0; i<vec.size(); i++){
    CS += vec[i];
    MS = max(MS, CS);
    if(CS<0){
      CS = 0;
    }
  }
  return MS;
}

int main() {
    vector<int> vec = {3, -4, 5, 4, -1, 7, -8};
    cout << maxSubArrSum(vec) << endl;
    return 0;
}
