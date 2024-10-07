class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1000000007;
        
        // Stacks to store previous and next smaller element indices
        stack<int> prevStack, nextStack;
        
        // Arrays to store distances to previous and next smaller elements
        vector<int> prevSmaller(n), nextSmaller(n);
        
        // Fill prevSmaller: Distance to previous smaller element
        for (int i = 0; i < n; i++) {
            while (!prevStack.empty() && arr[prevStack.top()] >= arr[i]) {
                prevStack.pop();
            }
            prevSmaller[i] = prevStack.empty() ? i + 1 : i - prevStack.top();
            prevStack.push(i);
        }
        
        // Fill nextSmaller: Distance to next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!nextStack.empty() && arr[nextStack.top()] > arr[i]) {
                nextStack.pop();
            }
            nextSmaller[i] = nextStack.empty() ? n - i : nextStack.top() - i;
            nextStack.push(i);
        }
        
        // Calculate the sum of subarray minimums
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long contribution = (long long)arr[i] * prevSmaller[i] * nextSmaller[i];
            ans = (ans + contribution) % mod;
        }
        
        return ans;
    }
};
