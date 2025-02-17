// 84. Largest Rectangle in Histogram
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxArea(vector<int>& histo) {
  int maxArea = 0;
  int n = histo.size();
  for (int i = 0; i < n; ++i) {
    int minHeight = histo[i];
    for (int j = i; j < n; ++j) {
      minHeight = min(minHeight, histo[j]);
      int width = j - i + 1;
      int area = minHeight * width;
      maxArea = max(maxArea, area);
    }
  }
  return maxArea;
}

int findMaxArea(vector<int> heights){
  vector<int> left(heights.size(), -1), right(heights.size(), heights.size());
  stack<int> st;

  for(int i=0; i<heights.size(); ++i){
    while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
    left[i] = st.empty()? -1 : st.top();
    st.push(i);
  };

  while(!st.empty()) st.pop();

  for(int i=heights.size()-1; i>=0; --i){
    while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
    right[i] = st.empty()? heights.size() : st.top();
    st.push(i);
  };

  int ans = 0;
  for(int i=0; i<heights.size(); ++i){
    int wt = right[i] - left[i] - 1;
    int currArea = heights[i] * wt;
    ans = max(ans, currArea);
  }
  return ans;
}



int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << "Maximum area: " << maxArea(heights) << endl;
  cout << "Maximum area: " << findMaxArea(heights) << endl;
  return 0;
}