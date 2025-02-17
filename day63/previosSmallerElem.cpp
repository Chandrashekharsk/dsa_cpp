// 739. Daily Temperatures
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousSmaller(vector<int> nums){
  stack<int> st;
  vector<int> ans(nums.size(), -1);

  for(int i=0; i<nums.size(); ++i){
    while(!st.empty() && st.top()>= nums[i]) st.pop();
    if(!st.empty()) ans[i] = st.top();
    st.push(nums[i]);
  }
  return ans;
}

int main(){
  vector<int> nums = {3,1, 0, 8, 6};
  for(auto& i: previousSmaller(nums))cout<< i<<" ";
  return 0;
};