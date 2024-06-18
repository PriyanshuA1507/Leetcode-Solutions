class Solution {
public:
    int helper(int n, vector<int>& a) {
        if (n <= 1) {
            return n;
        }
        if (a[n] != -1) {
            return a[n];
        }
        a[n] = helper(n - 1, a) + helper(n - 2, a);
        return a[n];
    }

    int fib(int n) {
        vector<int> a(n + 1, -1);
        return helper(n, a);
    }
};
