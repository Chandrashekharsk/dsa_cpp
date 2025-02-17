// 503. Next Greater Element II
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int N = nums.size();
    vector<int> ans(N, -1);  
    stack<int> st;

    for (int i = 2 * N - 1; i >= 0; --i) {
      while (!st.empty() && st.top() <= nums[i % N]) {
        st.pop();
      }
      if (i < N) {  // ✅ Only assign values for first N elements
        ans[i] = st.empty() ? -1 : st.top();
      }
      st.push(nums[i % N]);
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 1};
  Solution sol;
  vector<int> result = sol.nextGreaterElements(nums);
  cout << "Next Greater Elements: ";
  for (int num : result) cout << num << " ";
  cout << endl;
  return 0;
}
