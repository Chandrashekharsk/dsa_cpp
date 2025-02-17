// 496. Next Greater Element I
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> nextGreaterElem(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> m;
  stack<int> st;

  for (int i = nums2.size() - 1; i >= 0; --i) {
    while (!st.empty() && nums2[i] >= st.top()) {
      st.pop();
    }
    if (st.empty())
      m[nums2[i]] = -1;
    else
      m[nums2[i]] = st.top();
    st.push(nums2[i]);
  }

  vector<int> ans;
  for (auto& i : nums1) ans.push_back(m[i]);
  return ans;
}

int main() {
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  for (auto& i : nextGreaterElem(nums1, nums2)) cout << i << " ";

  return 0;
}