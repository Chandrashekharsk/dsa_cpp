#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Helper function to check if it is possible to allocate boards to 'M' painters
bool isPossible(vector<int>& nums, int n, int M, int totalAllowedBoards){
    int painter = 1, boards = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > totalAllowedBoards) return false;
        if (boards + nums[i] <= totalAllowedBoards) {
            boards += nums[i];
        } else {
            painter++;
            boards = nums[i];
            if (painter > M) return false;
        }
    }
    return painter <= M;
}

// Function to find the minimum time required to paint all boards
int paint(vector<int>& nums, int M) {
    int n = nums.size();
    if (M >= n) return *max_element(nums.begin(), nums.end());
    
    int st = *max_element(nums.begin(), nums.end());  // Start is the maximum element
    long long end = 0;  // End is the sum of all elements
    for (int i : nums) end += i;

    int ans = -1;

    // Binary Search
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isPossible(nums, n, M, mid)) {
            ans = mid;
            end = mid - 1;  // Try for a smaller value
        } else {
            st = mid + 1;  // Increase the lower bound
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int M = 2;  // Number of painters

    // Calculate minimum time to paint all boards
    int result = paint(boards, M);
    cout << "Minimum time to paint all boards: " << result << endl;

    return 0;
}
