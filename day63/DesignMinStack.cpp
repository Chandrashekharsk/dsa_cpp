// 155. Min Stack 
#include <climits>  // For INT_MAX
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
 public:
  long long int minVal;
  stack<long long int> st;

  MinStack() { minVal = LLONG_MAX; }  // Initialize minVal to max possible value

  void push(int val) {
    if (st.empty()) {
      minVal = val;
      st.push(val);
    } else {
      if (val < minVal) {
        st.push(2LL * val - minVal);  // Store encoded value
        minVal = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;

    if (st.top() < minVal) {
      minVal = 2 * minVal - st.top();  // Retrieve previous min value
    }
    st.pop();
  }

  int top() {
    if (st.empty()) return INT_MAX;  
    if (st.top() < minVal) return minVal; 
    return st.top();
  }

  int getMin() {
    if (st.empty()) return INT_MAX;  // Handle empty stack case safely
    return minVal;
  }
};


int main() {
  MinStack minStack;
  minStack.push(5);
  minStack.push(2);
  minStack.push(8);
  minStack.push(1);
  cout << "Min: " << minStack.getMin() << endl;  
  minStack.pop();
  cout << "Min: " << minStack.getMin() << endl;  
  cout << "Top: " << minStack.top() << endl;     
  minStack.pop();
  minStack.pop();
  cout << "Min: " << minStack.getMin() << endl;  
}
