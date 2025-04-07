// #DCC 2140. Solving Questions With Brainpower
#include <iostream>
#include <vector>
using namespace std;

void calculateMaxPoints(vector<vector<int>>& questions, int i, int points,
  int brainPower, long long& maxPoints) {

  if (i >= questions.size()) {
    maxPoints = max(maxPoints, (long long)points);
    return;
  }

  int curr_bp = questions[i][1];
  int curr_points = questions[i][0];

  // Option 1: Solve the current question
  if (brainPower == 0) {
    calculateMaxPoints(questions, i + 1, points + curr_points, curr_bp, maxPoints);
  } else {  // Option 2: Skip this question
    calculateMaxPoints(questions, i + 1, points, brainPower - 1, maxPoints);
  }
}

long long mostPoints(vector<vector<int>>& questions) {
  long long maxPoints = 0;
  calculateMaxPoints(questions, 0, 0, 0, maxPoints);
  return maxPoints;
}


long long calculateMaxPoints2(vector<vector<int>>& questions, int i, vector<long long>& dp) {
  if (i >= questions.size()) return 0;
  if(dp[i] != -1) return dp[i];

  int curr_bp = questions[i][1];
  int curr_points = questions[i][0];

  // Solve the current question
  long long solve = curr_points + calculateMaxPoints2(questions, i+curr_bp+1, dp);
  // Skip this question
  long long skip = calculateMaxPoints2(questions, i + 1, dp);

  return dp[i] = max(solve, skip);
}

long long mostPoints2(vector<vector<int>>& questions) {
  long long maxPoints = 0;
  vector<long long> dp(questions.size(), -1); // Memoization array (storing results)
  return calculateMaxPoints2(questions, 0, dp);;
}

long long mostPoints3(vector<vector<int>>& questions) {
  int n = questions.size();
  vector<long long> dp(n+1, 0);

  for(int i=n-1; i>=0; --i){
    int next = i + questions[i][1] + 1;
    long long solve = questions[i][0] + ((next<n)? dp[next]: 0);
    long long skip = dp[i+1];
    dp[i] = max(solve, skip);
  }
  return dp[0];
}

int main() {
  vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
  cout << "Maximum points: " << mostPoints(questions) << endl;
  cout << "Maximum points: " << mostPoints2(questions) << endl;
  cout << "Maximum points: " << mostPoints3(questions) << endl;
  return 0;
}
