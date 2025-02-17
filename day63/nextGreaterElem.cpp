#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> nextGreaterElem(vector<int> nums) {
  vector<int> ans(nums.size(), -1);  // Initialize with -1
  stack<int> st;
  for (int i = nums.size() - 1; i >= 0; --i) {
    while (!st.empty() && st.top() <= nums[i]) st.pop();
    if (!st.empty())  ans[i] = st.top();
    st.push(nums[i]);
  };
  return ans;
};

int main(){
  vector<int> nums = {6, 8, 0, 1, 3};
  for (auto& i : nextGreaterElem(nums)) cout << i << " ";
  return 0;
};